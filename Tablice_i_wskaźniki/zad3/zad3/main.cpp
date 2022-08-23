#include "main.h"


int main()
{
// +++++++++++++++++++++++ tablica statyczna +++++++++++++++++++++++++
	float tab[ROWS][COLS] = {
		{ 5.3, 3.1, 8.0, 3.51, 0.22 },
		{ 1.1, 7.56, 2.32, 14.033, 9.21 },
		{ 10.004, 4.05, 1.0, 3.01, 7.49 } };

	float* fPtr = *tab;

	for( int i = 0; i < ROWS*COLS; i++, fPtr++ )
		printf( "%.3f  ", *fPtr);
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


	printf( "\n\n\n" );


// +++++++++++++++++++++++ tablica statyczna +++++++++++++++++++++++++
	float* Vec = new float[ROWS*COLS]; //(float*)calloc(ROWS*COLS, sizeof(float) );

	for( int i = 0; i < ROWS; i++ )
		for( int j = 0; j < COLS; j++ )
			Vec[i*COLS + j] = 10*i + j + (float)i/10 + (float)j/100;


	printf( "\n\n\n" );

	Print(Vec);		// wypisanie w pêtli

	printf( "\n\n\n" );


	float** v = &Vec;
	for(int i = 0; i < ROWS ; i++)
	{
		for( int j = 0; j < COLS; j++ )


			printf( "%5.2f   ", v[i][j] );
		printf( "\n\n" );
	}

	//float** V = &Vec;
	//printf("V[0][1] = %5.2f\n\n", V[0][1] );
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


	getchar();
	return 0;
}