#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
	srand(time(0)); // seed the random number generator, otherwise the rand() will return the same sequence of numbers
	int num = rand() % 10; // returns random int between 0 and 9.

}
