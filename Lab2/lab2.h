// Name: Gábor Major
// Student Number: C00271548
// Modified: 07/10/2023
#pragma once
#include <iostream>
using namespace std;
const int rowCount = 4;
const int columnCount = 6;
// dont use cout in any of the functions apart from PrintArray();
int ReplaceWithMinusOne(int array[4][6])
{
	int minNumberCluster = 3;
	int score = 0;
	for (int row = 0; row < rowCount; row++)
	{
		for (int column = 0; column < columnCount; column++)
		{
			int currentValue = array[row][column];
			if (currentValue > 0)
			{
				if (column + minNumberCluster <= columnCount)
				{
					int columnIndex = column + 1;
					int nextValue = array[row][columnIndex];
					int clusterCount = 1;
					while (nextValue == currentValue)
					{
						clusterCount++;

						columnIndex++;
						if (columnIndex == columnCount)
						{
							break;
						}
						else
						{
							nextValue = array[row][columnIndex];
						}
					}
					if (clusterCount >= minNumberCluster)
					{
						score += currentValue * clusterCount;
						for (int index = 0; index < clusterCount; index++)
						{
							array[row][column + index] = -1;
						}
					}
				}
				currentValue = array[row][column];
				if (currentValue > 0 && row + minNumberCluster <= rowCount)
				{
					int rowIndex = row + 1;
					int nextValue = array[rowIndex][column];
					int clusterCount = 1;
					while (nextValue == currentValue)
					{
						clusterCount++;

						rowIndex++;
						if (rowIndex == rowCount)
						{
							break;
						}
						else
						{
							nextValue = array[rowIndex][column];
						}
					}
					if (clusterCount >= minNumberCluster)
					{
						score += currentValue * clusterCount;
						for (int index = 0; index < clusterCount; index++)
						{
							array[row + index][column] = -1;
						}
					}
				}
			}
		}
	}
	return score;
}
void swapValues(int array[4][6], int row1, int column1, int row2, int column2)
{
	int temp = array[row1][column1];
	array[row1][column1] = array[row2][column2];
	array[row2][column2] = temp;
	return;
}
void FallDownAndReplace(int array[4][6])
{
	for (int column = 0; column < columnCount; column++)
	{
		int negativeOnesCount = 0;
		for (int row = rowCount - 1; row >= 0; row--)
		{
			int currentValue = array[row][column];
			if (currentValue == -1)
			{
				negativeOnesCount += 1;
				array[row][column] = -2;
			}
			else if (currentValue != 0)
			{
				swapValues(array, row, column, row + negativeOnesCount, column);
			}
		}
	}
	return;
}
void PrintArray(int array[4][6])
{
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
	int variablesIndex = 0;
	for (int codeIndex = 0; codeIndex < 1000; codeIndex++)
	{
		char character = code[codeIndex];
		if (character == 0)
		{
			break;
		}
		else
		{
			if ((character == 'i' &&
				 code[codeIndex + 1] == 'n' &&
				 code[codeIndex + 2] == 't')
				||
				(character == 'c' &&
				 code[codeIndex + 1] == 'h' &&
				 code[codeIndex + 2] == 'a' &&
				 code[codeIndex + 3] == 'r'))
			{
				codeIndex += 4;
				character = code[codeIndex];
				while (character == ' ' && codeIndex < 1000)
				{
					codeIndex++;
					character = code[codeIndex];
				}
				int starting_variablesIndex = variablesIndex;
				while (codeIndex < 1000)
				{
					character = code[codeIndex];
					if (character == '(' || character == '[')
					{
						variablesIndex = starting_variablesIndex;
						variables[variablesIndex] = 0;
						break;
					}
					else if (character == ' ' || character == '=')
					{
						variables[variablesIndex] = ',';
						variablesIndex++;
						break;
					}
					else
					{
						variables[variablesIndex] = character;
						variablesIndex++;
					}
					codeIndex++;
				}
			}
		}
	}
	if (variablesIndex != 0 && variables[variablesIndex - 1] == ',')
	{
		variables[variablesIndex - 1] = 0;
	}
	return;
}
void FindAllVariablesInScope(char variables[1000], char code[1000], int lineNumber)
{

}
