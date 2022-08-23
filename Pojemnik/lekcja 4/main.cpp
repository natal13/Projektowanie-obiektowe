#include "main.h"


int main()
{	
	Bipojemnik C( "poj1", 0, 4, 0, "poj2", 0, 5, 0 );
	C.Wypisz();

	try
	{
		C.Dolej( 12 );
	}
	catch( double przelane )
	{
		printf( "Pozostalo %.1lf cieczy.\n\n", przelane );
	}

	C.Wypisz();

	try
	{
		C.Odlej( 13 );
	}
	catch( double brakujaca )
	{
		printf("Brakuje %.1lf cieczy.\n\n", brakujaca );
	}

	C.Wypisz();

	system("pause");
	return 0;
}