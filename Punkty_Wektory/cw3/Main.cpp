#include "Main.h"

int main(int argc, char* argv[])
{	
	//PUNKT a( argc, argv );
	//printf( "a = ( %d, %d )\n\n", a.x, a.y );

	WEKTOR v( argc, argv );
	printf( "v = { ( %.1lf, %.1lf ), (%.1lf, %.1lf ) }\n\n", v.a.x, v.a.y, v.b.x, v.b.y );

	PUNKT a( 2, 3 );
	printf("%lf, %lf\n\n", a.x, a.y);
	PUNKT b( 4, 5 );
	printf("%lf, %lf\n\n", b.x, b.y);

	WEKTOR u = PunktyWWektor( a, b );
	printf( "u = { ( %.1lf, %.1lf ), (%.1lf, %.1lf ) }\n\n", u.a.x, u.a.y, u.b.x, u.b.y );

	getchar();
	return 0;
}


Punkt::Punkt()
{
	x = 0;
	y = 0;
}

Punkt::Punkt(int argc, char* argv[])
{
	if( argc < 3 )
	{
		x = 0;
		y = 0;
		return;
	}

	x = strtod( argv[1], NULL );
	y = strtod( argv[2], NULL );
}

Punkt::Punkt(double a, double b)
{
	x = a;
	y = b;
}

Wektor::Wektor()
{
	a = Punkt::Punkt();
	//printf("a = ( %d, %d )\n", a.x, a.y);
	b = Punkt::Punkt();
	//printf("b = ( %d, %d )\n", b.x, b.y);
}

Wektor::Wektor( int argc, char* argv[] )
{
	if( argc < 5 )
	{
		a.x = 0;
		a.y = 0;
		b.x = 0;
		b.y = 0;
		return;
	}
	a.x = strtod( argv[1], NULL );
	a.y = strtod( argv[2], NULL );
	b.x = strtod( argv[3], NULL );
	b.y = strtod( argv[4], NULL );
}

Wektor::Wektor( PUNKT pa, PUNKT pb )
{
	a = pa;
	b = pb;
}
