#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include "FunkcjePunktWektor.h"

#ifndef _MAIN_
#define _MAIN_
struct Punkt
{
	double x;
	double y;
	Punkt();
	Punkt( int argc, char* argv[] );
	Punkt( double a, double b );
};

typedef struct Punkt PUNKT;

struct Wektor
{
	Punkt a;
	Punkt b;
	Wektor();
	Wektor( int argc, char* argv[] );
	Wektor( PUNKT pa, PUNKT pb); 
};


typedef struct Wektor WEKTOR;


// jesli wywolamy wektor(int argc, argv) to najpierw robi domyslny konstruktor, a potem ten, zeby robil tylko ten, bez domyslnego to listy.
#endif