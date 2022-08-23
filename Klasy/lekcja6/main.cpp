#include "main.h"

int main()
{
	Bazowa a;
	Pochodna b;

	a.id();
	b.id();

	Bazowa* c = new Pochodna;
	Pochodna* d = new Pochodna;

	c->id();
	d->id();

	LIFO qLifo(5);
	qLifo.Dodaj(3);
	qLifo.Dodaj(8);
	qLifo.Dodaj(2);

	qLifo.Wypisz();

	delete c;
	delete d;

	//FIFO qFifo(6);

	system( "pause" );
	return 0;
}