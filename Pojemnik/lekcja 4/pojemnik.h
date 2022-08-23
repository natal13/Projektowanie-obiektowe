#ifndef _POJEMNIK_H_ 
#define _POJEMNIK_H_ 

#define NAME_SIZE 100

typedef enum { Przelanie, BrakCieczy } RodzajWyjatku;

class Pojemnik
{
public:
	
	char nazwa[NAME_SIZE];
	int jednostka;
	double pojemnosc;
	double zajete;

	Pojemnik();
	Pojemnik( const char* _nazwa, int _jednostka, double _pojemnosc, double _zajete );
	Pojemnik( const Pojemnik &poj );

	double Dodaj( double zawartosc );
	double Odbierz( double zawartosc );
	void Wypisz();
};


class Bipojemnik
{
public:
	Pojemnik pojA;
	Pojemnik pojB;

	Bipojemnik();
	Bipojemnik( const char* _nazwaA, int _jednostkaA, double _pojemnoscA, double _zajeteA, const char* _nazwaB, int _jednostkaB, double _pojemnoscB, double _zajeteB );
	
	void Dolej( double ilosc );
	void Odlej( double ilosc );
	void Wypisz();
};

//class Wyjatki
//{
//public:
//	RodzajWyjatku rw;
//	double ilosc;
//	char ktoryPojemnik[NAME_SIZE];
//};

#endif