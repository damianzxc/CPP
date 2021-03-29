#include <iostream>
#include <cmath>

#define P 0.00001        //dokładność wyznaczania miejsca zerowego
#define A 0                //zakres od A do B
#define B 10                 //!A>B

using namespace std;

struct Interval{
    double a;       //dolna granica przedziału
    double b;       //górna granica przedziału
};

double y(double x) {
    //return x*(x*(3*x+3)-2)+11;    //x^3 + 3x^2 -2x +11
    //return x*x*(x*x-2)-1;         //x^4 - 2x^2 -1
    return x*(2*x+16)-7;            //2x^2 + 16x -7
}

// funkcja zwraca indeks węzła, dla którego wartość y jest najbliższa 0
int minimumNode(double *X) {
    int j;                  // indeks minimum
    double m = 1000;        // indeks wartość
    bool found = false;
    for(int i=0; i<=10; i++) {
        if( y(X[i]) < m && y(X[i]) > 0) {
            m = y(X[i]);
            found = true;
            j = i;
        }
    }
    if(found) {
        //cout << "X najbliższe 0 to: " << m << " y= "<< y(X[j]) << endl;
        return j;
    }
    else cout << "Brak miejsc zerowych" << endl;
}

// funkcja zwraca nowe wartości przedziałów a i b
// X - tablica węzłów
// j - indeks miejsca zerowego
// h - odległość (b-a)/10
Interval setNewInterval(double *X, int j, double h) {
    Interval i;
    if(j==0) {i.a = X[0]-5*h; i.b = X[5];}
    if(j==1) {i.a = X[0]-4*h; i.b = X[6];}
    if(j==2) {i.a = X[0]-3*h; i.b = X[7];}
    if(j==3) {i.a = X[0]-h; i.b = X[7];}
    if(j==4) {i.a = X[1]; i.b = X[7];}
    if(j==5) {i.a = X[2]; i.b = X[8];}
    if(j==6) {i.a = X[3]; i.b = X[9];}
    if(j==7) {i.a = X[4]; i.b = X[10]+h;}
    if(j==8) {i.a = X[5]; i.b = X[10]+3*h;}
    if(j==9) {i.a = X[4]; i.b = X[10]+4*h;}
    if(j==10) {i.a = X[5]; i.b = X[10]+5*h;}
    return i;
}

int main()
{
    Interval I;             //przedział a-b
    I.a = A;               //min
    I.b = B;                //max (min < max)

    int j = 0;              //indeks miejsca zerowego
    double X[11];           //tablica węzłów
    double h;               //odległość między węzłami
    bool found = false;     //przerywa pętle gdy element zostanie znaleziony z założoną dokładnością

    while(!found){
        if((I.a >= 0)&&(I.b > I.a)) {       //jeżeli a i b >= 0
            h = (I.b - I.a) / 10;
        }
        if((I.b <= 0) && (I.a < I.b)) {     //jeżeli a i b < 0
            h = fabs((I.b - I.a)) / 10;
        }
        if((I.b > 0) && (I.a <= 0)) {       //jeżeli a >= 0 < b
            h = ((I.b) + fabs(I.a)) / 10;
        }
        if((I.b - I.a) <= 0) {              //a nie może być mniejsze niż b
            cout << "błąd" << endl;
            break;
        }
        // Tablica nowych węzłów
        X[0] = I.a;
        for(int i=1; i<=10; i++) {
            X[i] = X[i-1]+h;
        }
        j = minimumNode(X);          // węzeł dla którego y(x) --> minimum
        I = setNewInterval(X,j,h);      // nowy przedział
        if(h <= (P/10)) {           // przedział mniejszy od P, KONIEC
            found = true;
        }
}
    cout << "Miejsce zerowe x = : " << X[j] << endl;
    cout << "Dla x z przedziału = : " << I.a << " do " << I.b << endl << endl;
    cout << "Dokładność = : " << P << endl;
    cout << "Błąd dla x = : " << I.b - I.a << endl;
    cout << "Błąd dla y = : " << y(I.b) - y(I.a) << endl;
    return 0;
}
