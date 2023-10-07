// Name: Gábor Major
// Student Number: C00271548
// Modified: 07/10/2023
#include "lab2.h"
using namespace std;
// add your tests here.
int main()
{
	//example of calling the functions

	int array[4][6] = {{0,0,3,1,3,4},
					   {0,0,3,2,4,3},
					   {0,0,3,3,3,2},
					   {0,0,1,1,1,1}};
	PrintArray(array);
	cout << "\n";

	cout << "Replace with minus one.\n";
	int score = ReplaceWithMinusOne(array);
	cout << "Score: " << score << "\n";
	PrintArray(array);
	cout << "\n";

	cout << "Fall down and replace.\n";
	FallDownAndReplace(array);
	PrintArray(array);
	cout << "\n";

	char code[1000] = "";
	char variables[1000] = "";
	
	FindAllVariables(variables, code);
	FindAllVariablesInScope(variables, code, 12);


}
