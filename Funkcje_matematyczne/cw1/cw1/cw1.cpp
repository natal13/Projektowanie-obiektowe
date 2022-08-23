// cw1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <math.h>	//plik nag³ówkowy systemowy zawieraj¹cy funkcje matematyczne

#define PI  3.14159265358979	//z , - wyra¿enie przecinkowe, z . - liczba
//tu deklarujê funkcje

int _tmain(int argc, _TCHAR* argv[])
{
	//definicja x,y - musze je zadeklarowac    //kazda zmienna w osobnej linii !!!
	double x = 0; //odciêta punktu
	double y = 0; //rzêdna punktu
	
	//trzeba napisac, co program ode mnie chce
	//wczytanie wspolrzednych punktu
	cout << "Podaj wsp punktu: x, y: ";
		cin >> x;
		cin >> y;
	
	//wczytanie katu obrotu w stopniach
	double alpha;
	cout << "Podaj k¹t obrotu w stopniach: ";
		cin >> alpha;	// strza³ka pokazuje czy cos wchodzi czy wychodzi

	//konwersja kata do radianow
	double radians = alpha * PI / 180.;

	//obliczyc wspolrzedne punktu po obrocie
	double x1 = x*cos(radians) - y*sin(radians);
	double y1 = x*sin(radians) + y*cos(radians);

	//wypisac wyliczone wspolrzedne
	cout << "x1 = " << x1;
	cout << "y1 = " << y1;

	cout << "\n\n";

	return 0;
}

