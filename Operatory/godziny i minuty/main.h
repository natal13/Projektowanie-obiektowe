#include <iostream>
using namespace std;

class Czas
{
public:
	int Godziny;
	int Minuty;

	Czas( int h, int m ) : Godziny( h ), Minuty( m ) {};
	void Wypisz( const char* nazwa );

	Czas operator+ ( Czas b );
	Czas operator+ ( int min );
};
