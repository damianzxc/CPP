#include <iostream>
#include <time.h>
#include <math.h>
#define MAX 10      // maksymalna wielkość macierzy

using namespace std;

void getRandomValues(int A[MAX][MAX], int n) {
    srand( (unsigned)time(NULL) );
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            A[i][j] = rand() % 6;
        }
    }
}

void displayMatrix(int A[MAX][MAX], int n) {
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
//obliczanie wyznacznika metodą rekurencji
int determinant(int A[MAX][MAX], int n) {
    int det = 0;    //wyznacznik
    int L[MAX][MAX]; // tablica n-1 elementów
    // jeśli jest tylko jeden element zwracamy go
    if (n == 1) {
        return A[0][0];
    }
    // jeśli macierz jest 2x2
    if (n == 2) {
        return (A[0][0] * A[1][1] - A[1][0] * A[0][1]);
    }
    else {
    //jeśli macierz jest większa od 2x2
    //przechodzimy kolejno po elementach wiersza
        for(int x=0; x<n; x++) {
            // iterator dla elementów wiersza n-1
            int xi = 0;
            //przepisywanie kolejnych elementów (A x-1,y-1 -> Lxy)
            for(int i=1; i<n; i++) {
                // iterator dla el. kolumn n-1
                int xj = 0;
                for(int j=0; j<n; j++) {
                    if(j == x) {
                        continue;
                    }
                    // nowa tablica n-1
                    L[xi][xj] = A[i][j];
                    xj++;
                }
                xi++;
            }
            // rekurencyjne wyliczanie wyznacznika
            det = det + (pow(-1, x) * A[0][x] * determinant(L, n-1));
        }
    }
    return det;
}

int main() {
    int A[MAX][MAX];
    int n = 11;
    while (n > 10) {
        cout << "Podaj rozmiar macierzy kwadratowej " ; cin >> n;
    }

    //wypełniam macierz losowymi liczbami
    getRandomValues(A, n);
    displayMatrix(A, n);

    cout << "wyznacznik macierzy wynosi: " << endl << determinant(A, n) << endl;

    return 0;
}
