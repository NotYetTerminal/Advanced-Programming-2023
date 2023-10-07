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

	char code1[1000] = "int main() \n{ \n int var1=10;\n int char1 = 'e';\n if(var1<10) \n {\n int var3=20;\n} \n}\n";
	char variables1[1000] = "";
	
	cout << "Code:\n" << code1 << "\n";
	FindAllVariables(variables1, code1);
	cout << "Variables: " << variables1 << "\n";

	char code2[1000] = "int main()\n{ \n int numElephants = 10;\n int var2 = 10; \n if (var2 < 10)\n{\nint var3 = 20;\n}\n while(var2 < 0)\n { \n if (var2 == 10) \n { \n int var4; \n } \n int num = 10; \n } \n int var5 = 10; \n }";
	char variables2[1000] = "";
	FindAllVariablesInScope(variables2, code2, 12);


}
