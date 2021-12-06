#include<iostream>
#include <iomanip>

using namespace std;

struct matrice
{
    int linie, coloana;
}verif;

void Citire_Matr(int linii, int coloane, double matr[][101])
{
    cout << endl;
    for (int index_linie = 0; index_linie < linii; index_linie++)
        for (int index_coloana = 0; index_coloana < coloane; index_coloana++)
            cin >> matr[index_linie][index_coloana];
}

void Afisare_Matr(int linii, int coloane, double matr[][101])
{
    cout << endl;
    for (int index_linie = 0; index_linie < linii; index_linie++)
    {
        for (int index_coloana = 0; index_coloana < coloane; index_coloana++)
        {
            if (matr[index_linie][index_coloana] == -0)
                matr[index_linie][index_coloana] = 0;
            cout << matr[index_linie][index_coloana] << " ";
        }
        cout << endl;
    }
}

void Interschimbare_Linii(int coloane, int pozitia_1, int pozitia_2, double matr[][101])
{
    for (int index = 0; index < coloane; index++)
        swap(matr[pozitia_1][index], matr[pozitia_2][index]);
}

void Inmultire_cu_Constanta(int coloane, int pozitie, double matr[][101],double constanta)
{
    for (int index = 0; index < coloane; index++)
    {
        matr[pozitie][index] = matr[pozitie][index] * constanta;
    }
}

void Adaugare_Multiplu_Scalar(int coloane, int pozitie, int pozitie_inmultire, double matr[][101], float valoare)
{
    for (int index = 0; index < coloane; index++)
    {
        matr[pozitie][index] = matr[pozitie][index] - valoare * matr[pozitie_inmultire][index];
    }
}

void Aflare_solutii_comp_det (int linii, int coloane, double matr[][101])
{
    for (int index = 0; index < linii; index++)
    {
        cout << "x" << index + 1 << " are valoarea " << matr[index][coloane - 1] << endl;
    }
}

void Aflare_solutii_comp_nedet(int linii, int coloane, double matr[][101])
{
    bool vector_nec_sec[101]{};
    verif.coloana = 0;
    verif.linie = 0;

    bool Verif_existenta_nec_secundare;

    while (verif.linie != linii && verif.coloana !=coloane-1)
        if (matr[verif.linie][verif.coloana] == 1)
        {
            cout << "X" << verif.coloana + 1 << " are valoarea ";
            Verif_existenta_nec_secundare = 0;
            for (int index = 0; index < coloane - 1; index++)
                if (matr[verif.linie][index] && index!=verif.coloana)
                {
                    cout << -1 * matr[verif.linie][index] << " X" << index + 1;
                    vector_nec_sec[index] = 1;
                    Verif_existenta_nec_secundare = 1;
                }
            if(Verif_existenta_nec_secundare)
                if (matr[verif.linie][coloane - 1] > 0)
                    cout << " + ";
                else
                    cout << " - ";
            cout << abs(matr[verif.linie][coloane - 1])<< endl;
            verif.linie++;
            verif.coloana++;
        }
        else
            verif.coloana++;
    cout << "Termenul/ii ";
    for (int index = 0; index < coloane-1; index++)
        if (vector_nec_sec[index] == 1)
            cout << "X" << index + 1 << ", ";
    cout << "au drept valori constante ale domeniului de definitie al sistemului";
}

int main()
{
    int index_linie, index_coloana, nr_ec,nr_necunoscute;
    cout << setprecision(4);
    
    cout << "Numarul de ecuatii: ";
    cin >> nr_ec;
    cout << endl;
    cout << "Numarul de necunoscute: ";
    cin >> nr_necunoscute;
    cout << endl;

    int i = nr_ec;
    int j = nr_necunoscute+1;
    double matr[101][101];

    matrice principalul;
    principalul.coloana = 0;
    principalul.linie = 0;

    int contor_parcurgeri = 0, cond_comaptibilitate_sistem = 1;

    cout << "Matricea extinsa: ";
    for (index_linie = 0; index_linie < i; index_linie++)
    {
        for (index_coloana = 0; index_coloana < j; index_coloana++)
        {
            cin >> matr[index_linie][index_coloana];
        }
    }

    while (contor_parcurgeri < min(i, j - 1) && cond_comaptibilitate_sistem==1)
    {
        if (matr[principalul.linie][principalul.coloana] == 0) 
        {
            int cond_dif_0 = 0;
            for (index_coloana = principalul.linie + 1; index_coloana < nr_ec && cond_dif_0 == 0; index_coloana++)
                if (matr[index_coloana][principalul.linie] != 0)
                {
                    Interschimbare_Linii(j, principalul.linie, index_coloana, matr);
                    cond_dif_0 = 1;
                    Afisare_Matr(i, j, matr);
                }
            if (cond_dif_0 == 0)
                principalul.coloana++;
            int contor_0 = 0;
            for (int index = 0; index < j - 1; index++)
                if (matr[principalul.linie][index] == 0)
                    contor_0++;
            if (contor_0 == j - 1)
                cond_comaptibilitate_sistem = 0;
        }
        else
            if (matr[principalul.linie][principalul.coloana] != 1)
            {
                Inmultire_cu_Constanta(j, principalul.linie, matr, 1 / matr[principalul.linie][principalul.coloana]);
                Afisare_Matr(i, j, matr);
            }
            else
            {
                for (int contor_auxiliar = 0; contor_auxiliar < j; contor_auxiliar++)
                {
                    if (contor_auxiliar == principalul.linie)
                        continue;
                    Adaugare_Multiplu_Scalar(j, contor_auxiliar, principalul.linie, matr, matr[contor_auxiliar][principalul.coloana] / matr[principalul.linie][principalul.coloana]);
                }
                Afisare_Matr(i, j, matr);
                principalul.linie++;
                principalul.coloana++;
                contor_parcurgeri++;
            }
    }
    
    if (matr[principalul.linie][j - 1] == 0 && cond_comaptibilitate_sistem == 0 || nr_ec < nr_necunoscute)
    {
        cout << "Sistem compatibil nedeterminat"<<endl;
        Aflare_solutii_comp_nedet(i, j, matr);
    }
    else
        if (cond_comaptibilitate_sistem == 0)
            cout << "Sistem incompatibil";
        else
            {
                cout << "Sistem compatibil determinat" << endl;
                Aflare_solutii_comp_det(i, j, matr);
            }

}