//============================================================================
// Name        : pc++.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "String.h"
#include "Array.h"

int main(void) {
	Array<int, 10> x;

	for (int i = 0; i < 200; i++)
		x.add(i);

	Array<int, 10> y;

	y.add(x);

	for (int i = 0; i < 200; i++)
		printf("%d\n", y[i]);

	return 0;
}
