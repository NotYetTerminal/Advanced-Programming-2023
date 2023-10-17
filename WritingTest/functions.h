#pragma once
#pragma once
#include <iostream>
using namespace std;
// Name:
// Student Number :
//You can only use int,char or bool variable.
//ONLY USE COUT IN DrawShape()
//You can use any functions you write yourself.
//To get marks the code must compile.
//Total Exam Duration 1 Hour 15 minutes

/*
Question 1 : 20 Marks
Write a nested loop that outputs the following. This nested loop contains only 2 for loops and at most 1 if and an else conditional statement.
You may only use cout << 'A' and cout << endl. The answer must be exactly the below to get marks.
AAA
AA
A
AA
AAA
*/
void DrawShape()
{
	for (int index = -2; index < 3; index++)
	{
		int count = 0; // added a count to save number of A's to print instead of changing index
		if (index < 0)
		{
			count = -index;
		}
		else
		{
			count = index;
		}
		for (int jIndex = 0; jIndex <= count; jIndex++)
		{
			cout << 'A';
		}
		cout << endl;
	}
}



//Question 2 : 30 Marks

//Delete an element from an array of at a specified position.
//The parameter size is the size of the array when the array was declared
//The elements higher in the array are shifted to the left one position.
//Use a variable called count to track the number of elements in the array.
///Return true if an element was deleted, otherwise return false.


bool deleteElement(int& size, int& count, int arr[], int deleteIndex)
{
	if (deleteIndex >= count)
	{
		return false;
	}
	for (int index = deleteIndex; index < count; index++)
	{
		if (index + 1 == size)
		{
			arr[index] = 0;
		}
		else
		{
			arr[index] = arr[index + 1];
		}
	}
	count -= 1;
	return true;
}

//Question 3 : 20 Marks
//return the frequency of value in arr 
//( return a count of the number of times value appears in the array) 
int frequencyCount(int size, int arr[], int value)
{
	int count = 0;
	for (int index = 0; index < size; index++)
	{
		if (arr[index] == value)
		{
			count++;
		}
	}
	return count;
}

//Question 4 : 30 Marks


//Right rotate an array by one position. Note: the last element is rotated //to the start of the array

int rotateRight(int size, int arr[])
{
	int last = arr[size - 1];
	for (int index = size - 1; index > 0; index--) // changed the index to start with size - 1 and end at 1
	{
		arr[index] = arr[index - 1];
	}
	arr[0] = last;
	return -1;
}


