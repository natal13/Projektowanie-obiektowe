#include "main.h"

int main()
{
	LiczbaZespolona a( 2, 4 );
	LiczbaZespolona b( 0, 0 );

	a.Wypisz( "a" );

	a = b;

	b.Wypisz( "b" );

	getchar();
	return 0;
}


void LiczbaZespolona::Wypisz( const char* nazwa)
{
	cout << nazwa << " = ";
	if( fabs( Im ) < EPS ) cout << Re << endl;
	else if( fabs( Re ) < EPS && fabs( Im ) > EPS ) cout << Im << "i" << endl;
	else cout << Re << " + " << Im << "i" << endl;
}

void LiczbaZespolona::operator= ( LiczbaZespolona &b )
{
	b.Re = Re;
	b.Im = Im;
}