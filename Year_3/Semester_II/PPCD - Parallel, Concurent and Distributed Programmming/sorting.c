#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>
#include <time.h>


int MPI_Sort_ranking(int n, double* a, int root, MPI_Comm comm);
int MPI_Sort_bucket(int n, double* a, double max, int root, MPI_Comm comm);
int MPI_Sort_shell(int n, double* a, int root, MPI_Comm comm);
int MPI_Bitonic_sort(int n, double* a, int root, MPI_Comm comm);
double* Merge_array(int n, double* a, int m, double* b);
int MPI_Odd_Even(int n, double* a, int my_rank, int comm_sz, MPI_Comm comm);
int MPI_Direct_Sort(int n, double* a, int rank, int size, MPI_Comm comm);
void Merge_sort(int n, double* a);
void Merge(int n, double* a, int m, double* b);

void Swap(double* a, double* b);
int compare_doubles(const void* a, const void* b) {
	double x = *(const double*)a;
	double y = *(const double*)b;

	if (x < y) {
		return -1;
	}
	else if (x > y) {
		return 1;
	}
	else {
		return 0;
	}
}

int main(int argc, char* argv[])
{
	int rank, size;

	int n = 100000;
	double m = 100000.0;
	double* a;// , * b;

	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	a = (double*)calloc(n, sizeof(double));

	if (rank == 0)
	{		
		srand(((unsigned)time(NULL) + rank));

		for (int i = 0; i < n; i++)
		{
			a[i] = ((double)rand() / RAND_MAX) * m;
		}
	}
	double start_time = MPI_Wtime();

	 //MPI_Sort_bucket(n, a,m, 0, MPI_COMM_WORLD);
    // MPI_Odd_Even(n, a, rank, size, MPI_COMM_WORLD);
	//MPI_Sort_direct(n, a, 0, MPI_COMM_WORLD);
	//MPI_Sort_shell(n, a, 0, MPI_COMM_WORLD);
	 //MPI_Bitonic_sort(n, a, 0, MPI_COMM_WORLD);
	MPI_Direct_Sort(n, a, rank, size, MPI_COMM_WORLD);
	double end_time = MPI_Wtime();

	free(a);
	MPI_Finalize();
	printf("Execution time: %f seconds\n", end_time - start_time);
}

int MPI_Sort_ranking(int n, double* a, int root, MPI_Comm comm)
{
	int rank, size;
	// find rank and size
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	
	int* local_pos = (int*)calloc(n / size, sizeof(int));
	int* pos = (int*)calloc(n, sizeof(int));
	double* aux = (double*)calloc(n, sizeof(double));
	MPI_Bcast(a, n, MPI_DOUBLE, root, comm);

	for (int i = rank * n / size; i < (rank + 1) * n / size; i++)
	{
		for (int j = 0; j < n; j++)
			if (a[j] < a[i])
				local_pos[i - rank * n / size]++;
	}
	// Gather the array ranking to finalRanking
	MPI_Gather(local_pos, n / size, MPI_INT, pos, n / size, MPI_INT, root, comm);

	// if processor 0 then restore the order in the array b and move b back to a
	if (rank == root)
	{
		for (int i = 0; i < n; i++)
		{
			aux[pos[i]] = a[i];
		}
		memcpy(a, aux, n * sizeof(double));
	}
	free(local_pos);
	free(pos);
	free(aux);
	return MPI_SUCCESS;
}

int MPI_Sort_bucket(int n, double* a, double max, int root, MPI_Comm comm)
{
	int rank, size;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	// allocate array for each bucket 
	double* bucket = (double*)calloc(n, sizeof(double));

	int* cnts = (int*)calloc(size, sizeof(int));
	int* displ = (int*)calloc(size, sizeof(int));
	
	MPI_Bcast(a, n, MPI_DOUBLE, root, comm);	
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (a[i] >= rank * max / size && a[i] < (rank + 1) * max / size)
			bucket[cnt++] = a[i];

	Merge_sort(cnt, bucket);
	MPI_Gather(&cnt, 1, MPI_INT, cnts, 1, MPI_INT, root, comm);
	displ[0] = 0;
	for (int i = 1; i < size; i++)
		displ[i] = displ[i - 1] + cnts[i - 1];
	MPI_Gatherv(bucket, cnt, MPI_DOUBLE, a, cnts, displ, MPI_DOUBLE, root, comm);
	return MPI_SUCCESS;
}


int MPI_Sort_direct(int n, double* a, int root, MPI_Comm comm)
{
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int i, j;
	double temp;

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	return MPI_SUCCESS;
}


void bitonicMerge(double* arr, int low, int cnt, int dir)
{
	if (cnt > 1)
	{
		int k = cnt / 2;
		for (int i = low; i < low + k; i++)
		{
			if ((arr[i] > arr[i + k]) == dir)
			{
				double temp = arr[i];
				arr[i] = arr[i + k];
				arr[i + k] = temp;
			}
		}
		bitonicMerge(arr, low, k, dir);
		bitonicMerge(arr, low + k, k, dir);
	}
}

void bitonicSort(double* arr, int low, int cnt, int dir)
{
	if (cnt > 1)
	{
		int k = cnt / 2;
		bitonicSort(arr, low, k, 1);
		bitonicSort(arr, low + k, k, 0);
		bitonicMerge(arr, low, cnt, dir);
	}
}

int MPI_Bitonic_sort(int n, double* a, int root, MPI_Comm comm)
{
	int size, rank;
	double* local_array;

	MPI_Comm_size(comm, &size);
	MPI_Comm_rank(comm, &rank);

	local_array = (double*)malloc(n / size * sizeof(double));

	int error = MPI_Scatter(a, n / size, MPI_DOUBLE, local_array, n / size, MPI_DOUBLE, root, comm);
	if (error != MPI_SUCCESS)
	{
		free(local_array);
		return error;
	}

	bitonicSort(local_array, 0, n / size, 1); 

	error = MPI_Gather(local_array, n / size, MPI_DOUBLE, a, n / size, MPI_DOUBLE, root, comm);
	if (error != MPI_SUCCESS)
	{
		free(local_array);
		return error;
	}

	if (root == rank)
	{
		for (int step = 2; step <= size; step *= 2)
		{
			for (int i = 0; i < size; i += step)
			{
				int dir = ((i / step) % 2 == 0) ? 1 : 0; 
				int k = step / 2;
				bitonicMerge(a, i * n / size, k * n / size, dir);
				bitonicMerge(a, (i + k) * n / size, k * n / size, dir);
			}
		}
	}

	free(local_array);
	return MPI_SUCCESS;
}
double* Merge_array(int n, double* a, int m, double* b) {
	int i, j, k;
	double* c = (double*)calloc(n + m, sizeof(double));

	for (i = j = k = 0; (i < n) && (j < m);)
		if (a[i] <= b[j])c[k++] = a[i++];
		else c[k++] = b[j++];
	if (i == n)for (; j < m;)
		c[k++] = b[j++];
	else for (; i < n;)c[k++] = a[i++];
	return c;
}

void Merge_sort(int n, double* a) {
	double* c;
	int i;
	if (n <= 1) return;
	if (n == 2) {

		if (a[0] > a[1])Swap(&a[0], &a[1]);
		return;
	}
	Merge_sort(n / 2, a); Merge_sort(n - n / 2, a + n / 2);
	c = Merge_array(n / 2, a, n - n / 2, a + n / 2);
	for (i = 0; i < n; i++)a[i] = c[i];
}

void Swap(double* a, double* b) {
	double temp;
	temp = *a; *a = *b; *b = temp;
}

int MPI_Sort_shell(int n, double* a, int root, MPI_Comm comm)
{
	int rank, size;
	MPI_Comm_rank(comm, &rank);
	MPI_Comm_size(comm, &size);

	int i, j, k, gap;
	double temp;


	gap = n / size;

	
	for (i = rank * gap; i < (rank + 1) * gap; i++)
	{
		for (j = i + gap; j < n; j += gap)
		{
			temp = a[j];
			for (k = j - gap; k >= 0 && temp < a[k]; k -= gap)
				a[k + gap] = a[k];
			a[k + gap] = temp;
		}
	}

	
	double* temp_arr = NULL;
	if (rank == root)
	{
		temp_arr = (double*)malloc(n * sizeof(double));
		MPI_Gather(MPI_IN_PLACE, gap, MPI_DOUBLE, temp_arr, gap, MPI_DOUBLE, root, comm);
	}
	else
	{
		MPI_Gather(&a[rank * gap], gap, MPI_DOUBLE, temp_arr, gap, MPI_DOUBLE, root, comm);
	}

	if (rank == root)
	{
		for (i = 1; i < n; i++)
		{
			temp = temp_arr[i];
			for (j = i - 1; j >= 0 && temp < temp_arr[j]; j--)
				temp_arr[j + 1] = temp_arr[j];
			temp_arr[j + 1] = temp;
		}
		memcpy(a, temp_arr, n * sizeof(double));
		free(temp_arr);
	}

	return MPI_SUCCESS;
}



int MPI_Odd_Even(int n, double* a, int rank, int size, MPI_Comm comm)
{
	int chunk_size = (n + size - 1) / size;
	double* local_a = (double*)calloc(chunk_size, sizeof(double));
	double* local_b = (double*)calloc(chunk_size, sizeof(double));

	MPI_Scatter(a, chunk_size, MPI_DOUBLE, local_a, chunk_size, MPI_DOUBLE, 0, comm);
	Merge_sort(chunk_size, local_a);

	for (int step = 0; step < size; step++)
	{
		if ((rank % 2 == 0) && (rank < size - 1))
		{
			MPI_Sendrecv(local_a, chunk_size, MPI_DOUBLE, rank + 1, 0,
				local_b, chunk_size, MPI_DOUBLE, rank + 1, 0,
				comm, MPI_STATUS_IGNORE);

			Merge(chunk_size, local_a, chunk_size, local_b);
		}
		else if ((rank % 2 != 0) && (rank > 0))
		{
			MPI_Sendrecv(local_a, chunk_size, MPI_DOUBLE, rank - 1, 0,
				local_b, chunk_size, MPI_DOUBLE, rank - 1, 0,
				comm, MPI_STATUS_IGNORE);

			Merge(chunk_size, local_b, chunk_size, local_a);
			for (int i = 0; i < chunk_size; i++)
			{
				local_a[i] = local_b[i];
			}
		}
		MPI_Barrier(comm);
	}

	MPI_Gather(local_a, chunk_size, MPI_DOUBLE, a, chunk_size, MPI_DOUBLE, 0, comm);

	free(local_a);
	free(local_b);

	return MPI_SUCCESS;
}
void Merge(int n, double* a, int m, double* b)
{
	int i = 0, j = 0, k = 0;
	double* temp = (double*)calloc(n + m, sizeof(double));

	while (i < n && j < m)
	{
		if (a[i] <= b[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = b[j++];
		}
	}

	while (i < n)
	{
		temp[k++] = a[i++];
	}

	while (j < m)
	{
		temp[k++] = b[j++];
	}

	for (i = 0; i < n; i++)
	{
		a[i] = temp[i];
	}

	for (j = 0; j < m; j++)
	{
		b[j] = temp[i++];
	}

	free(temp);
}

int MPI_Direct_Sort(int n, double* a, int rank, int size, MPI_Comm comm)
{
	int chunk_size = (n + size - 1) / size;
	double* local_a = (double*)calloc(chunk_size, sizeof(double));

	MPI_Scatter(a, chunk_size, MPI_DOUBLE, local_a, chunk_size, MPI_DOUBLE, 0, comm);

	for (int i = 0; i < chunk_size - 1; i++)
	{
		int min_index = i;

		for (int j = i + 1; j < chunk_size; j++)
		{
			if (local_a[j] < local_a[min_index])
			{
				min_index = j;
			}
		}

		if (min_index != i)
		{
			double temp = local_a[i];
			local_a[i] = local_a[min_index];
			local_a[min_index] = temp;
		}
	}

	MPI_Gather(local_a, chunk_size, MPI_DOUBLE, a, chunk_size, MPI_DOUBLE, 0, comm);

	if (rank == 0)
	{
		for (int i = 0; i < n - 1; i++)
		{
			int min_index = i;

			for (int j = i + 1; j < n; j++)
			{
				if (a[j] < a[min_index])
				{
					min_index = j;
				}
			}

			if (min_index != i)
			{
				double temp = a[i];
				a[i] = a[min_index];
				a[min_index] = temp;
			}
		}
	}

	free(local_a);
	return MPI_SUCCESS;
}




