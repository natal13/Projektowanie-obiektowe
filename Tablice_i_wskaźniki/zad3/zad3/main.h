#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstdarg>

using namespace std;

#define Print(x) for( int i = 0; i < ROWS; i++ ) \
					for( int j = 0; j < COLS; j++ ) \
						printf( "%5.2f%s", x[i*COLS + j], j == COLS - 1 ? "\n\n" : "   " )



#define ROWS 3
#define COLS 5

//#define v[i][j] Vec[i*COLS + j]