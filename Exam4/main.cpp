#include "functions.h"

// Examples of how to call the functions

int main()
{

	char strtoFind[4] = "cat";
	char str[9] = "gellocat";
	int resultQuestion1 = IndexOfStringinString(strtoFind, 4,str,9);

	std::cout << resultQuestion1 << '\n';

	char array2D[100][100] = {' '};
	int triangleWidth = 3;
	DrawTriangleInArray(array2D, triangleWidth);

	for (int row = 0; row < 5; row++)
    {
        for (int column = 0; column < 5; column++)
        {
            std::cout << array2D[row][column] << ',';
        }
        std::cout << '\n';
    }

	char  code[100] = "int main()\n{\nint a=10;\nif(a==10)\n{\nint b=4;\n}\n}";
	char indentedCode[100];
	int size=100;
	IndentCode(code, indentedCode, size);

	for (int index = 0; index < 100; index++)
    {
        if (code[index] == 0)
        {
            break;
        }
        std::cout << code[index];
    }
    std::cout << '\n';

	for (int index = 0; index < 100; index++)
    {
        if (indentedCode[index] == 0)
        {
            break;
        }
        std::cout << indentedCode[index];
    }
    std::cout << '\n';
}
