
#include <iostream>
using namespace std;
// You may only use int or chars
// Name: Gabor Major
// Student ID: C00271548
//
//Question1 (20 Marks)
//
//int IndexOfStringinString(char strToFind[] , int strToFindSize,char str[], int strSize  )
//
// return the index of the first occurence of strToFind within str;
// Note:it returns the index of the first letter of the strToFind within str
// Return -1 if not found
// The size of strToFind will always be less than size of str array.
//Exmampke
//strToFind is "cat"
//str is "dogcatdecat"
// returns 3
//strToFind is "dec"
//str is "dogcatdecat"
// returns 6

int IndexOfStringinString(char strToFind[] , int strToFindSize,char str[], int strSize  )
{
	if (strToFindSize == 0)
    {
        return -1;
    }
    for (int index = 0; index <= (strSize - strToFindSize); index++)
    {
        if (str[index] == strToFind[0])
        {
            bool allCorrect = true;
            for (int jIndex = 1; jIndex < strToFindSize; jIndex++)
            {
                if (str[index + jIndex] != strToFind[jIndex])
                {
                    allCorrect = false;
                    break;
                }
            }
            if (allCorrect)
            {
                return index;
            }
        }
    }
	return -1;
}
//Question 2  (30 marks)
//void DrawTriangleInArray(char array2D[10][10] , int triangleWidth)
//The array2d is set all to spaces before the function is called.
// The triangleWidth will be limited to a size that can fit in the array
//Example :
// triangleWidth = 2
//
//Result
// data[0][0] = 'X';
// data[1][0] = 'X';
// data[1][1] = 'X';
// data[2][0] = 'X';
//
// //Example :
// triangleWidth = 3
//
//Result
// data[0][0] = 'X';
// data[1][0] = 'X';
// data[1][1] = 'X';
// data[2][0] = 'X';
// data[2][1] = 'X';
// data[2][2] = 'X';
// data[3][0] = 'X';
// data[3][1] = 'X';
// data[4][0] = 'X';


void DrawTriangleInArray(char array2D[100][100] , int triangleWidth)
{
	int row = 0;
	int lastColumn = 0;
	for (int index = 0; index < triangleWidth * triangleWidth;) // removed index++
    {
        if (index * 2 < triangleWidth * triangleWidth) // changed (index / 2) to (index * 2)
        {
            for (int column = 0; column <= row; column++)
            {
                array2D[row][column] = 'X';
                index++;
            }
            lastColumn = row;
        }
        else
        {
            for (int column = 0; column < lastColumn; column++)
            {
                array2D[row][column] = 'X';
                index++;
            }
            lastColumn--;
        }
        row++;
    }
    return;
}


//Question 3  (50 marks)
//void IndentCode(char  code[], char indentedCode[], int sizeofArrays)
// Indent the code correctly for '{' and '}'. Indent size is 3 spaces.
// '{' and '}' will always be on a separate line
// Fill identedCode array with the indented code.
// sizeofArrays is the size of the code array and indentedCode array;
// The end of a string is denoted by a 0 .
// Exmample
//code  "int main()\n{\nint a=10;\nif(a==10)\n{\nint b=4;\n}\n}"
// if printed out it would look like the below
//int main()
//{
//int a=10;
//if( a==10)
//{
//int b=4;
//}
//}
// indentedCode
// "int main()\n{\n   int a=10;\n   if(a==10)\n   {\n      int b=4;\n   }\n}"
// if printed out it would look like the below
//int main()
//{
//   int a=10;
//   if( a==10)
//   {
//      int b=4;
//   }
//}
void IndentCode(char  code[], char indentedCode[], int sizeofArrays)
{
	int indentedCodeIndex = 0;
	int indentAmount = 0;
	for (int index = 0; index < sizeofArrays; index++)
    {
        char c = code[index];
        if (c == 0)
        {
            indentedCode[indentedCodeIndex] = c;
            return;
        }
        else if (c == '{')
        {
            indentedCode[indentedCodeIndex] = c;
            indentedCodeIndex++;
            indentAmount += 3;
        }
        else if (c == '}')
        {
            indentAmount -= 3;
            indentedCodeIndex -= 3;
            indentedCode[indentedCodeIndex] = c;
            indentedCodeIndex++;
        }
        else if (c == '\n')
        {
            indentedCode[indentedCodeIndex] = c;
            indentedCodeIndex++;
            for (int jIndex = 0; jIndex < indentAmount; jIndex++)
            {
                indentedCode[indentedCodeIndex] = ' ';
                indentedCodeIndex++;
            }
        }
        else
        {
            indentedCode[indentedCodeIndex] = c;
            indentedCodeIndex++;
        }
    }
}
