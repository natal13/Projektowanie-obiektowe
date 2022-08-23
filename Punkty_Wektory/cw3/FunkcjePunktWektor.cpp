#include "FunkcjePunktWektor.h"

WEKTOR PunktyWWektor(PUNKT a, PUNKT b)
{
	WEKTOR v;
	v.a = a;
	v.b = b;
	
	return v;
}

WEKTOR DodawanieWektorow( WEKTOR v, WEKTOR u)
{
	WEKTOR w;
	w.a = v.a;
	w.b.x = v.b.x + u.b.x;
	w.b.y = v.b.y + v.b.y;

	return w;
}