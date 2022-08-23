#include "main.h"

int main()
{
	Czas a( 14, 10);
	Czas b( 2, 45 );

	Czas c( 0, 0 );
	c = a + b;
	c.Wypisz( "c" );

	Czas d( 0, 0 );
	d = b + 25;
	d.Wypisz( "d" );

	getchar();
	return 0;
}

void Czas::Wypisz( const char* nazwa )
{
	cout << nazwa << ": " << Godziny << "h " << Minuty << "min " << endl;
}

Czas Czas::operator+ ( Czas b )
{
	Czas res( 0, 0 );

	bool overflow = ( Minuty + b.Minuty ) >= 60;

	res.Godziny = ( Godziny + b.Godziny + ( overflow ? 1 : 0 ) );
	res.Minuty = ( overflow ? Minuty + b.Minuty - 60 : Minuty + b.Minuty ); 

	return res;
}

Czas Czas::operator+ ( int min )
{
	Czas res( 0, 0 );

	bool overflow = ( Minuty + min ) >= 60;

	res.Godziny =( Godziny + ( overflow ? (Minuty + min)/60 : 0 ) );
	res.Minuty = ( overflow ? ( Minuty + min )%60 : Minuty + min ); 

	return res;
}