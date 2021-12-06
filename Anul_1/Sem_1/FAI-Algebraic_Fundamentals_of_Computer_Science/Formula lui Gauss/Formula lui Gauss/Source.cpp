#include<iostream>
#include <iomanip>

using namespace std;
void Input_matrix(int size_lines, int size_columns, double matrix[][101])
{
    cout << endl;
    for (int counter_line = 0; counter_line < size_lines; counter_line++)
        for (int counter_column = 0; counter_column < size_columns; counter_column++)
            cin >> matrix[counter_line][counter_column];
}

void Output_matrix(int size_lines, int size_columns, double matrix[][101])
{
    cout << endl;
    for (int counter_line = 0; counter_line < size_lines; counter_line++)
    {
        for (int counter_column = 0; counter_column < size_columns; counter_column++)
        {
            if (matrix[counter_line][counter_column] == -0)
                matrix[counter_line][counter_column] = 0;
            cout << matrix[counter_line][counter_column] << " ";
        }
        cout << endl;
    }
}

//Operatia echivalenta cu Sij din inmultirea matricelor de transformare
void Swapping_lines(int size_column, int position1, int position2, double matrix[][101])
{
    for (int counter_column = 0; counter_column < size_column; counter_column++)
        swap(matrix[position1][counter_column], matrix[position2][counter_column]);
}

//Operatia echivalenta cu Mi(a) din inmultirea matricelor de transformare
void Multiplying_with_constant(int size_column, int position_line, double matrix[][101],double multiplying_value)
{
    for (int counter_column = 0; counter_column < size_column; counter_column++)
    {
        matrix[position_line][counter_column] = matrix[position_line][counter_column] * multiplying_value;
    }
}

//Operatia echivalenta cu Ti(aLj) din inmultirea matricelor de transformare
void Adding_scalar_multiple_of_row1_to_row2(int size_column, int position_line, int position_multiplying, double matrix[][101], float multiplying_value)
{
    for (int counter_column = 0; counter_column < size_column; counter_column++)
    {
        matrix[position_line][counter_column] = matrix[position_line][counter_column] - multiplying_value * matrix[position_multiplying][counter_column];
    }
}

struct element_matrice
{
    int linie, coloana;
};

void Aflare_solutii_comp_det (int size_lines, int size_columns, double matrix[][101])
{
    for (int contor = 0; contor < size_lines; contor++)
    {
        cout << "x" << contor + 1 << " are valoarea " << matrix[contor][size_columns - 1] << endl;
    }
}

void Aflare_solutii_comp_nedet(int size_lines, int size_columns, double matrix[][101])
{
    bool vector_nec_sec[101]{};

    element_matrice verif;
    verif.coloana = 0;
    verif.linie = 0;

    bool Verif_existenta_nec_secundare;

    while (verif.linie != size_lines && verif.coloana !=size_columns-1)
        if (matrix[verif.linie][verif.coloana] == 1)
        {
            cout << "X" << verif.coloana + 1 << " are valoarea ";
            Verif_existenta_nec_secundare = 0;
            for (int contor_secundar = 0; contor_secundar < size_columns - 1; contor_secundar++)
                if (matrix[verif.linie][contor_secundar] && contor_secundar!=verif.coloana)
                {
                    cout << -1 * matrix[verif.linie][contor_secundar] << " X" << contor_secundar + 1;
                    vector_nec_sec[contor_secundar] = 1;
                    Verif_existenta_nec_secundare = 1;
                }
            if(Verif_existenta_nec_secundare)
                if (matrix[verif.linie][size_columns - 1] > 0)
                    cout << " + ";
                else
                    cout << " - ";
            cout << abs(matrix[verif.linie][size_columns - 1])<< endl;
            verif.linie++;
            verif.coloana++;
        }
        else
            verif.coloana++;
    cout << "Termenul/ii ";
    for (int contor = 0; contor < size_columns-1; contor++)
        if (vector_nec_sec[contor] == 1)
            cout << "X" << contor + 1 << ", ";
    cout << "au drept valori constante ale domeniului de definitie al sistemului";
}

int main()
{
    int contor_linie, contor_coloana, nr_ec,nr_necunoscute;
    cout << setprecision(4);
    
    cout << "\nIntroduceti numarul de ecuatii: ";
    cin >> nr_ec;
    cout << "\nIntroduceti numarul de necunoscute: ";
    cin >> nr_necunoscute;

    int i = nr_ec;
    int j = nr_necunoscute+1;
    double mat[101][101];

    element_matrice principalul;
    principalul.coloana = 0;
    principalul.linie = 0;

    int contor_parcurgeri = 0, cond_comaptibilitate_sistem = 1;

    cout << "\nIntroduceti elementele matricei extinse: ";
    for (contor_linie = 0; contor_linie < i; contor_linie++)
    {
        for (contor_coloana = 0; contor_coloana < j; contor_coloana++)
        {
            cin >> mat[contor_linie][contor_coloana];
        }
    }

    while (contor_parcurgeri < min(i, j - 1) && cond_comaptibilitate_sistem==1)
    {
        if (mat[principalul.linie][principalul.coloana] == 0) //atunci cand a[i][i] ==0, se cauta mai jos de el sa se interschimbe liniile intre ele
        {
            int cond_dif_0 = 0;
            for (contor_coloana = principalul.linie + 1; contor_coloana < nr_ec && cond_dif_0 == 0; contor_coloana++)
                if (mat[contor_coloana][principalul.linie] != 0)
                {
                    Swapping_lines(j, principalul.linie, contor_coloana, mat);
                    cond_dif_0 = 1;
                    Output_matrix(i, j, mat);
                }
            if (cond_dif_0 == 0)
                principalul.coloana++;

            //verificare compatibilitate sistem
            int contor_0 = 0;
            for (int contor_auxiliar = 0; contor_auxiliar < j - 1; contor_auxiliar++)
                if (mat[principalul.linie][contor_auxiliar] == 0)
                    contor_0++;
            if (contor_0 == j - 1)
                cond_comaptibilitate_sistem = 0;
        }
        else
            if (mat[principalul.linie][principalul.coloana] != 1)
            {
                Multiplying_with_constant(j, principalul.linie, mat, 1 / mat[principalul.linie][principalul.coloana]);
                Output_matrix(i, j, mat);
            }
            else
            {
                for (int contor_auxiliar = 0; contor_auxiliar < j; contor_auxiliar++)
                {
                    if (contor_auxiliar == principalul.linie)
                        continue;
                    Adding_scalar_multiple_of_row1_to_row2(j, contor_auxiliar, principalul.linie, mat, mat[contor_auxiliar][principalul.coloana] / mat[principalul.linie][principalul.coloana]);
                }
                Output_matrix(i, j, mat);
                principalul.linie++;
                principalul.coloana++;
                contor_parcurgeri++;
            }
    }
    
    if (mat[principalul.linie][j - 1] == 0 && cond_comaptibilitate_sistem == 0 || nr_ec < nr_necunoscute)
    {
        cout << "Sistem compatibil nedeterminat"<<endl;
        Aflare_solutii_comp_nedet(i, j, mat);
    }
    else
        if (cond_comaptibilitate_sistem == 0)
            cout << "Sistem incompatibil";
        else
            {
                cout << "Sistem compatibil determinat" << endl;
                Aflare_solutii_comp_det(i, j, mat);
            }

}