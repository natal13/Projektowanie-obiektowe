#include "main.h"

void Bazowa::id()
{
	cout << "Bazowa\n";
}

void Pochodna::id()
{
	cout << "Pochodna\n";
}

LIFO::LIFO()
{
	x = 0;
	pNext = NULL;
}

LIFO::LIFO( int _x )
{
	LIFO* v = this;
	while( v->pNext )
		v = v->pNext;

	v->x = _x;
	v->pNext = NULL;
}

LIFO::~LIFO()
{

}

void LIFO::Dodaj( int _x )
{
	LIFO* v = new LIFO;
	v->x = 0;
	v->pNext = NULL;
	pNext = v;
}

int LIFO::Zdejmij()
{
	LIFO* v = pNext;
	LIFO* u = this->pNext;

	while( v->pNext )
	{
		u = u->pNext;
		v = v->pNext;
	}

	int res = v->x;
	u->pNext = NULL;
	delete v;
	return res;
}

void LIFO::Wypisz()
{
	LIFO* v = pNext;
	while( v )
	{
		cout << v->x << endl;
		v = v->pNext;
	}
//	cout << v->x << endl << endl << endl;
}

FIFO::~FIFO()
{}