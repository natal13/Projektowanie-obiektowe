#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <iostream>

using namespace std;

class Matematyka
{
public:
	template <typename T>
	static T max( T x, T y );
	template <typename T>
	static Wektor<T> max<Wektor>( Wektor<T> A, Wektor<T> B );
};

template <typename T>
class Wektor
{
public:
	int n;
	T* V;
	
	Wektor( int _n, ... );
	void Wypisz();
	~Wektor<T>();
};