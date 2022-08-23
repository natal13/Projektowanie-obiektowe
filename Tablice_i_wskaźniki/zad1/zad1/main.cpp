#include "main.h"

int main()
{
	int i = 5;
	int &alias = i;

	int* ptr = &i;

	alias = 9;

	Print;

	const int &iref = i;
	const int* iptr = &i;

	iref = 14;		// b³¹d kompilacji
	*iptr = 14;		// b³¹d kompilacji

	i = 14;
	Print;


	getchar();
	return 0;
}