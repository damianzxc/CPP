#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#define N 5

using namespace std;

void getMatrix(double **A, int n) {
    double tab[n][n] = { {4,5,3,2,2},{2,4,0,-9,6},{1,2,3,4,5},{4,8,36,4,5},{3,5,8,-12,25} };
    //srand( (unsigned)time(NULL) );
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            A[i][j] = tab[i][j];
            //A[i][j] = rand()% 5-3;
        }
    }
}

// wyświetla macierz w linii
void displayMatrix(double **A, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(A[i][j] < -9) {
                cout << A[i][j] << "  ";
            }
            else if(A[i][j] < 0 || A[i][j] > 9) {
                cout << A[i][j] << "   ";
            }
            else {
                cout << A[i][j] << "    ";
            }
        }
        cout << endl;
    }
}

// ustawia największy element na początek macierzy, współrzędne wiersza i kolumny
int transformMatrix(double ** A, int n) {
    int w = 0;
    int k = 0;
    // znak potrzebny do wyznaczenia współczynnika
    int sign = 1;
    double maxValue = fabs(A[0][0]);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(fabs(A[i][j]) > maxValue) {
                maxValue = fabs(A[i][j]);
                w = i;
                k = j;
            }
        }
    }
    // zamiana wierszy
    if(w > 0) {
        double tmp;
        for(int i=0; i<n; i++) {
            tmp = A[0][i];
            A[0][i] = A[w][i];
            A[w][i] = tmp;
        }
    }
    // zamiana kolumn
    if(k > 0) {
        double tmp;
        for(int j=0; j<n; j++) {
            tmp = A[j][0];
            A[j][0] = A[j][k];
            A[j][k] = tmp;
        }
    }
    // jeżeli zmienia się równocześnie wiersz i kolumna znak zostaje ten sam
    if(k>0 && w>0) sign = 1;
    else sign = -1;
    return sign;
}

void deleteMatrix(double **A, int n) {
    for(int i=0; i<n; i++) {
        delete [] A [i];
    }
    delete []A;
}

double determinant(double **A, int n) {
    if(n < 2) {
        return A[0][0];
    }
    else {
        cout << "---------------" << endl;
        // ustawia el. max na początku, zwraca znak mnożenia
        int sign = transformMatrix(A, n);
        double det = A[0][0];
        displayMatrix(A, n);
        // tablica wyników, mniejsza o 1
        double **B;
        B = new double * [n-1];
        for(int i=0; i<(n-1); i++) {
            B[i] = new double [n-1];
        }

        // liczenie wyznacznika
        // k - ilość permutacji (rekurencji)
        for(int k=0; k<n; k++) {
            // i - kolumna
            for(int i=k; i<n; i++) {
                // j - wiersz
                for(int j=1; j<n; j++) {
                    if(j>k) {
                    // wzór 2
                    //
                        if(k == i) {
                            A[k][j] = A[k][j] / A[k][k];
                        }
                        else {
                            A[i][j] = A[i][j] - A[i][k] * A[k][j];
                        }
                    }
                }
            }
            // przepisuje wyniki do tablicy B
            for(int r=0; r<n-1; r++) {
                for(int z=0; z<n-1; z++) {
                    B[r][z] = A[r+1][z+1];
                }
            }
            det *= sign * determinant(B, n-1);
            deleteMatrix(B, n-1);
            return det;
        }
    }
}


int main() {
    cout << setprecision(3) << fixed;
    double **A;
    A = new double * [N];
    for(int i=0; i<N; i++) {
        A[i] = new double [N];
    }

    getMatrix(A, N);
    cout << "Macierz do obliczenia wyznacznika: " << endl;
    displayMatrix(A, N);
    double det = determinant(A, N);
    cout << "Wyznacznik wynosi: " << det << endl;
    cout << "Liczba elementów macierzy: " << N << endl;
    deleteMatrix(A, N);
    return 0;
}
