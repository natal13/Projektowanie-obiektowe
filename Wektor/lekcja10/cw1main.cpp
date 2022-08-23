#include "cw1main.h"


int main()
{
	short x = 1;
	double y = 2;

	cout << "m = " << Matematyka::max<double>( x, y ) << endl << "rozmiar = " << sizeof(Matematyka::max<double>( x, y )) << endl << endl;


	Wektor<int> A( 2, 4, 5 );
	Wektor<int> B( 2, 5, 12 );

	Wektor<int> C = Matematyka::max( A, B );

	A.Wypisz();

	getchar();
	return 0;
}

template <typename T>
static T Matematyka::max( T x, T y )
{
	if ( x > y ) return x;
	return y;
}



template <typename T>
Wektor<T>::Wektor( int _n, ... )
{
	n = _n;
	V = new T[n];

	va_list ap;
	va_start( ap, _n );

	for( int i = 0; i < n; i++ )
		V[i] = va_arg( ap, T );

	va_end( ap );
}

template <class T>
static Wektor<T> Matematyka::max<Wektor<T>>( Wektor<T> A, Wektor<T> B )
{
	T dlA = 0;
	T dlB = 0;

	for( int i = 0; i < n; i++ )
	{
		dlA += ( A.V[i]*A.V[i] );
		dlB += ( B.V[i]*B.V[i] );
	}

	if( sqrt( dlA ) > sqrt( dlB ) ) return A;
	return B;
}

template <typename T>
void Wektor<T>::Wypisz()
{
	for( int i = 0; i < n; i++ )
		cout << "x" << i << " = " << V[i] << endl;
}

template <typename T>
Wektor<T>::~Wektor()
{
	delete [] V;
	cout << "Pomyslnie zniszczono obiekt wektor\n " << endl;
}