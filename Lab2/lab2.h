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
void FallDownAndReplace(int array[4][6])
{

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

}
void FindAllVariablesInScope(char variables[1000], char code[1000], int lineNumber)
{

}
