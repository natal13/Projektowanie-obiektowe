#ifndef _KLASY_
#define _KLASY_

class Bazowa
{
public:
	virtual void id();
};

class Pochodna : public Bazowa
{
public:
	void id();
};



class LIFO
{
public:
	int x;
	LIFO* pNext;

	LIFO();
	LIFO( int _x );
	~LIFO();

	void Dodaj( int _x );
	int Zdejmij();
	void Wypisz();
};

class FIFO: public LIFO
{
	FIFO();
	FIFO( int _x );
	~FIFO();
	int Zdejmij();
};

#endif