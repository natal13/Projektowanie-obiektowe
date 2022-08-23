#include "main.h"

int main()
{
	LiczbaZespolona a( 3.0, 8.291 );
	a.Wypisz( "a" );

	LiczbaZespolona b( 1.1, -2.291 );

	LiczbaZespolona c( 0, 0 );
	c = a + b;
	c.Wypisz( "c" );

	c = a*b;
	c.Wypisz( "c" );

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

LiczbaZespolona LiczbaZespolona::operator+( LiczbaZespolona b )
{
	LiczbaZespolona res( Re + b.Re, Im + b.Im );
	return res;
}

LiczbaZespolona LiczbaZespolona::operator-( LiczbaZespolona b )
{
	LiczbaZespolona res( Re - b.Re, Im - b.Im );
	return res;
}

LiczbaZespolona LiczbaZespolona::operator*( LiczbaZespolona b )
{
	LiczbaZespolona res( Re * b.Re - Im * b.Im, Re * b.Im + Im * b.Re );
	return res;
}

/*LiczbaZespolona LiczbaZespolona::operator= ( LiczbaZespolona b )
{
	b.Re = Re;
	b.Im = Im;
	return b;
}*/