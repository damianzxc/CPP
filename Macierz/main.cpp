
#include <iostream>

using namespace std;

// Procedura wypełnia macierz i wyświetla ją
//------------------------------------------
void p ( int m, int n, int ** A )
{
  int i, j;

  for( i = 0; i < m; i++ )
    for( j = 0; j < n; j++ ) A [ i ][ j ] = ( i + j ) % 2;

  for( i = 0; i < m; i++ )
  {
    for( j = 0; j < n; j++ ) cout << A [ i ][ j ] << " ";
    cout << endl;
  }
}

// *** PROGRAM GŁÓWNY ***
//-----------------------

int main( )
{
  int ** A, n, m, i;

  cout << "m = "; cin >> m;
  cout << "n = "; cin >> n;

  // tworzymy tablicę wskaźników

  A = new int * [ m ];

  // tworzymy kolejne tablice wierszy

  for( i = 0; i < m; i++ ) A [ i ] = new int [ n ];

  // wypełniamy i wyświetlamy macierz

   p ( m, n, A );

  // najpierw usuwamy tablice wierszy

  for( i = 0; i < m; i++ ) delete [ ] A [ i ];

  // teraz usuwamy tablicę wskaźników

  delete [ ] A;

  return 0;
}
