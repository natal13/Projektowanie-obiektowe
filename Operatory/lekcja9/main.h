#include <iostream>
#include <cmath>

#define EPS 1e-17
using namespace std;

class LiczbaZespolona
{
public:
	double Re;
	double Im;
	char nazwa[10];

	LiczbaZespolona( double _Re, double _Im ) : Re(_Re), Im(_Im) {};

	LiczbaZespolona operator+ ( LiczbaZespolona b );
	LiczbaZespolona operator- ( LiczbaZespolona b );
	LiczbaZespolona operator* ( LiczbaZespolona b );

	void Wypisz( const char* nazwa );
};