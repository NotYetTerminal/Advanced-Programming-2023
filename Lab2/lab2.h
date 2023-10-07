// Name: Gábor Major
// Student Number: C00271548
// Modified: 07/10/2023
#pragma once
#include <iostream>
using namespace std;
// dont use cout in any of the functions apart from PrintArray();
int ReplaceWithMinusOne(int array[4][6])
{
	return 0;
}
void FallDownAndReplace(int array[4][6])
{

}
void PrintArray(int array[4][6])
{
	int rowCount = 4;
	int columnCount = 6;
	cout << "Array: {";
	for (int row = 0; row < rowCount; row++)
	{
		if (row != 0)
		{
			cout << "        ";
		}
		cout << "{";
		for (int column = 0; column < columnCount; column++)
		{
			cout << array[row][column];
			if (column + 1 == columnCount)
			{
				cout << "}";
			}
			else
			{
				cout << ", ";
			}
		}
		if (row + 1 != rowCount)
		{
			cout << ",\n";
		}
	}
	cout << "}\n";
	return;
}
void FindAllVariables(char variables[1000], char code[1000])
{

}
void FindAllVariablesInScope(char variables[1000], char code[1000], int lineNumber)
{

}
