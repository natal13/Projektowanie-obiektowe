#include "main.h"


Pojemnik::Pojemnik()
{
	memset( nazwa, 0, NAME_SIZE );		// rozmiar char = 1
	jednostka = 0;
	pojemnosc = 0;
	zajete = 0;
}

Pojemnik::Pojemnik( const char* _nazwa, int _jednostka, double _pojemnosc, double _zajete )
{
	strcpy( nazwa, _nazwa );
	jednostka = _jednostka;
	pojemnosc = _pojemnosc;
	zajete = _zajete;
}

Pojemnik::Pojemnik( const Pojemnik &poj )
{
	strcpy( nazwa, poj.nazwa );
	jednostka = poj.jednostka;
	pojemnosc = poj.pojemnosc;
	zajete = poj.zajete;
}



double Pojemnik::Dodaj( double zawartosc )
{
	double nowaZawartosc = zajete + zawartosc;

	if( nowaZawartosc > pojemnosc )
	{
		double res = nowaZawartosc - pojemnosc + zajete;
		zajete = pojemnosc;

		throw res;
	}
	
	zajete = nowaZawartosc;
	return 0;
}


double Pojemnik::Odbierz( double zawartosc )
{
	if( zawartosc > zajete )
	{
		double res = zawartosc - zajete;
		zajete = 0;
		throw res;
	}
	
	zajete -= zawartosc;
	return zawartosc;
}

void Pojemnik::Wypisz()
{
	printf("Nazwa:\t\t%20s\nJednostka:\t%20d\nPojemnosc:\t%20.1lf\nZajete:\t\t%20.1lf\n\n", nazwa, jednostka, pojemnosc, zajete); 
}


Bipojemnik::Bipojemnik()
	:
	pojA(),
	pojB()
{}

Bipojemnik::Bipojemnik( const char* _nazwaA, int _jednostkaA, double _pojemnoscA, double _zajeteA, const char* _nazwaB, int _jednostkaB, double _pojemnoscB, double _zajeteB )
	:
	pojA( _nazwaA, _jednostkaA, _pojemnoscA, _zajeteA ),
	pojB( _nazwaB, _jednostkaB, _pojemnoscB, _zajeteB )
{}

void Bipojemnik::Wypisz()
{
	pojA.Wypisz();
	pojB.Wypisz();
	printf( "\n\n" );
}


void Bipojemnik::Dolej( double ilosc )
{
	try
	{
		pojA.Dodaj( ilosc );
	}

	catch( double przelaneA )
	{
		try
		{
			pojB.Dodaj( przelaneA );
		}
		catch( double przelaneB )
		{
			throw przelaneB;
		}
	}
}

void Bipojemnik::Odlej( double ilosc )
{
	try
	{
		pojA.Odbierz( ilosc );
	}

	catch( double brakujacaA )
	{
		try
		{
			pojB.Odbierz( brakujacaA );
		}
		catch( double brakujacaB )
		{
			throw brakujacaB;
		}
	}
}