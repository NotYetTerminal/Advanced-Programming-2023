// Name: Gábor Major
// Student Number: C00271548
// Modified: 15/09/2023


#pragma once
#include <iostream>
#include <cmath>


using namespace std;


bool isLeapYear(int year)
{
	if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
				return true;
            }
            else
            {
				return false;
            }
        }
        else
        {
			return true;
        }
    }
    else
    {
		return false;
    }
}

int Reversed(int testNumber)
{
	int reversedNumber = 0;
	while (testNumber != 0)
    {
        reversedNumber *= 10;
        reversedNumber += (testNumber % 10);
        testNumber /= 10;
    }
	return reversedNumber;
}
bool isAPalindrome(int testNumber)
{
    int reversedNumber = Reversed(testNumber);

    while (testNumber != 0)
    {
        if (testNumber % 10 != reversedNumber % 10)
        {
            return false;
        }
        testNumber /= 10;
        reversedNumber /= 10;
    }
    return true;
}
bool isAPrimeNumber(int numbertoTest)
{
	if (numbertoTest < 0)
    {
        numbertoTest = abs(numbertoTest);
    }

    int maxFactor = ceil(sqrt(numbertoTest));

    for (int currentFactor = 2; currentFactor <= maxFactor; currentFactor++)
    {
        if (numbertoTest % currentFactor == 0)
        {
            return false;
        }
    }
    return true;
}
int input5CharsConvertToInt()
{
	int returnInt = 0;
	char inputChar;
    int asciiNumber;
    const int asciiForZero = 48;
    const int asciiForNine = 57;
	for (int i = 0; i < 5; i++)
	{
		std::cin >> inputChar;
		asciiNumber = int(inputChar);
        if (asciiNumber < asciiForZero || asciiNumber > asciiForNine)
        {
            return 0;
        }
        returnInt *= 10;
        returnInt += (asciiNumber - asciiForZero);

	}
	return returnInt;
}
int convertBinarytoDecimal(int binaryNumber)
{
	int decimalNumber = 0;
    int powerOfTwo = 1;
    int currentDigit;

    while (binaryNumber != 0)
    {
        currentDigit = binaryNumber % 10;
        if (currentDigit != 0 && currentDigit != 1)
        {
            return 0;
        }
        decimalNumber += powerOfTwo * currentDigit;
        powerOfTwo *= 2;
        binaryNumber /= 10;
    }
    return decimalNumber;
}
void drawRightAngledTriangle()
{
	int numberOfRows = 4;
    char printingCharacter = 'A';

    for (int row = 0; row < numberOfRows; row++)
    {
		for (int columns = 0; columns <= row; columns++)
        {
            cout << printingCharacter;
        }
        cout << '\n';
    }
    return;
}
void drawIsocelesTriangle()
{
	int numberOfRows = 6;

    char printingCharacter = 'A';
    int characterPrintAmount;

    for (int row = 0; row <= numberOfRows; row++)
    {
        if (row > 3)
        {
            characterPrintAmount = 6 - row;
        }
        else
        {
            characterPrintAmount = row;
        }
        for (int columns = 0; columns <= characterPrintAmount; columns++)
        {
            cout << printingCharacter;
        }
        cout << '\n';
    }
    return;
}
void drawIsocelesTriangle2()
{
	int maxLength = 4;
    maxLength -= 1;

    char printingCharacter = 'A';
    int characterPrintAmount;

    for (int row = -maxLength; row <= maxLength; row++)
    {
        characterPrintAmount = abs(abs(row) - maxLength);
        for (int columns = 0; columns <= characterPrintAmount; columns++)
        {
            cout << printingCharacter;
        }
        cout << '\n';
    }
    return;
}

int find(int size, int arr[], int toFind)
{
	for (int index = 0; index < size; index++)
    {
        if (arr[index] == toFind)
        {
            return index;
        }
    }
    return -1;
}
int find2ndLargest(int size, int arr[])
{
	int largest = -1;
    int secondLargest = -1;

    for (int index = 0; index < size; index++)
    {
        if (arr[index] > largest)
        {
            largest = arr[index];
        }
        else if (arr[index] > secondLargest && arr[index] != largest)
        {
            secondLargest = arr[index];
        }
    }
	return secondLargest;
}
void copyArraytoArray(int size, int arr1[], int arr2[])
{
	for (int index = 0; index < size; index++)
    {
        arr2[index] = arr1[index];
    }
	return;
}
bool insertElement(int& size, int& count, int arr[], int elementToInsert, int insertIndex)
{
	if (count == size)
    {
        return false;
    }
    if (insertIndex >= count)
    {
        arr[count] = elementToInsert;
        count += 1;
    }
    else
    {
		for (int index = count; index >= insertIndex; index--)
		{
			if (index == 0)
			{
				arr[index] = 0;
			}
			else
			{
				arr[index] = arr[index - 1];
			}
		}
		count += 1;
        arr[insertIndex] = elementToInsert;
    }
	return true;
}
bool deleteElement(int& size, int& count, int arr[], int deleteIndex)
{
	if (deleteIndex >= count)
    {
        return false;
    }
	for (int index = deleteIndex; index < count; index++)
    {
        if (index != size - 1)
        {
            arr[index] = arr[index + 1];
        }
        else
        {
            arr[index] = 0;
        }
    }
    count -= 1;
	return true;
}
int frequencyCount(int size, int arr[], int value)
{
	int foundCount = 0;
    for (int index = 0; index < size; index++)
    {
        if (arr[index] == value)
        {
            foundCount++;
        }
    }
	return foundCount;
}
int countDuplicates(int size, int arr[])
{
	int duplicateCount = 0;
    for (int index = 0; index < size; index++)
    {
        if (index < size - 1)
        {
            for (int jIndex = index + 1; jIndex < size; jIndex++)
            {
                if (arr[index] == arr[jIndex])
                {
                    duplicateCount++;
                    break;
                }
            }
        }
    }
	return duplicateCount;
}
void reverse(int size, int arr[])
{
	int temporaryNumber;
    for (int index = 0; index < size / 2; index++)
    {
        temporaryNumber = arr[index];
        arr[index] = arr[size - index - 1];
        arr[size - index - 1] = temporaryNumber;
    }
	return;
}
int rotateLeft(int size, int arr[])
{
	int firstElement = arr[0];
    int count = size;

	for (int index = 0; index < count; index++)
    {
        if (index != size - 1)
        {
            arr[index] = arr[index + 1];
        }
        else
        {
            arr[index] = 0;
        }
    }
    count -= 1;
    arr[size - 1] = firstElement;

	return -1;
}
bool twoMovies(int flightLength, int movieLengths[], int size)
{
	for (int index = 0; index < size; index++)
    {
        if (index < size - 1)
        {
            for (int jIndex = index + 1; jIndex < size; jIndex++)
            {
                if (movieLengths[index] + movieLengths[jIndex] == flightLength)
                {
                    return true;
                }
            }
        }
    }
	return false;
}
int wordCounter(int size, char characters[])
{
	int wordCount = 0;
    int basicLatinCharacterFound = false;

    for (int index = 0; index < size; index++)
    {
        if (characters[index] >= 65 && characters[index] <= 90)
        {
            basicLatinCharacterFound = true;
        }
        else if (characters[index] >= 97 && characters[index] <= 122)
        {
            basicLatinCharacterFound = true;
        }
        else if (basicLatinCharacterFound && characters[index] == ' ')
        {
            wordCount++;
            basicLatinCharacterFound = false;
        }
    }
    if (basicLatinCharacterFound)
    {
        wordCount++;
    }
	return wordCount;
}
void printArrayElements(int size, int arrayIn[])
{
    cout << "{";
    for (int index = 0; index < size; index++)
    {
        if (index == 0)
        {
            cout << arrayIn[index];
        }
        else
        {
            cout << ", " << arrayIn[index];
        }
    }
    cout << "}";
}
void printArrayElements(int size, char arrayIn[])
{
    cout << "{";
    for (int index = 0; index < size; index++)
    {
        if (index == 0)
        {
            cout << arrayIn[index];
        }
        else
        {
            cout << ", " << arrayIn[index];
        }
    }
    cout << "}";
}
