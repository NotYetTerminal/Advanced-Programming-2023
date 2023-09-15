// Name: Gábor Major
// Student Number: C00271548
// Modified: 15/09/2023


#include <iostream>
#include <cmath>


using namespace std;


void Question1()
{
    int yearChecking;

    cout << "Input year to check: ";
    cin >> yearChecking;
    cout << yearChecking << "\n";


    if (yearChecking % 4 == 0)
    {
        if (yearChecking % 100 == 0)
        {
            if (yearChecking % 400 == 0)
            {
                cout << "Leap year!";
            }
            else
            {
                cout << "Not leap year!";
            }
        }
        else
        {
            cout << "Leap year!";
        }
    }
    else
    {
        cout << "Not leap year!";
    }

    cout << "\n";
    return;
}


void Question2()
{
    int numberToCheck;

    cout << "Input number to check if palindrome: ";
    cin >> numberToCheck;
    cout << numberToCheck << "\n";

    int temporaryNumber = numberToCheck;
    int reversedNumber = 0;
    while (temporaryNumber != 0)
    {
        reversedNumber *= 10;
        reversedNumber += (temporaryNumber % 10);
        temporaryNumber /= 10;
    }

    while (numberToCheck != 0)
    {
        if (numberToCheck % 10 != reversedNumber % 10)
        {
            cout << "Not a palindrome!\n";
            return;
        }
        numberToCheck /= 10;
        reversedNumber /= 10;
    }

    cout << "It is a palindrome!\n";
    return;
}


void Question3()
{
    int numberToCheck;

    cout << "Input number to check if prime: ";
    cin >> numberToCheck;
    cout << numberToCheck << "\n";

    if (numberToCheck < 0)
    {
        numberToCheck = abs(numberToCheck);
    }

    int maxFactor = ceil(sqrt(numberToCheck));

    for (int currentFactor = 2; currentFactor <= maxFactor; currentFactor++)
    {
        if (numberToCheck % currentFactor == 0)
        {
            cout << "Not a prime!\n";
            return;
        }
    }

    cout << "It is a prime!\n";
    return;
}


void Question4()
{
    int binaryNumber;

    cout << "Input binary number to convert: ";
    cin >> binaryNumber;
    cout << binaryNumber << "\n";

    int decimalNumber = 0;
    int powerOfTwo = 1;
    int currentDigit;

    while (binaryNumber != 0)
    {
        currentDigit = binaryNumber % 10;
        if (currentDigit != 0 && currentDigit != 1)
        {
            cout << "Not a binary number was input!\n";
            return;
        }
        decimalNumber += powerOfTwo * currentDigit;
        powerOfTwo *= 2;
        binaryNumber /= 10;
    }

    cout << "Result in decimal: " << decimalNumber << "\n";
    return;
}


void Question5()
{
    char characterNumber;

    cout << "Input number: ";

    int asciiNumber;
    int integerNumber = 0;
    const int asciiForZero = 48;
    const int asciiForNine = 57;

    do
    {
        cin >> characterNumber;
        asciiNumber = int(characterNumber);
        if (asciiNumber < asciiForZero || asciiNumber > asciiForNine)
        {
            cout << "Incorrect input number! Only put in 0 to 9!\n";
            return;
        }
        integerNumber *= 10;
        integerNumber += (asciiNumber - asciiForZero);
    }
    while (cin.peek() != '\n');

    cout << "Number in integer format: " << integerNumber << "\n";
    return;
}


void Question6()
{
    int numberOfRows = 4;
    char printingCharacter = 'A';

    for (int row = 0; row < numberOfRows; row++)
    {
        for (int columns = 0; columns <= row; columns++)
        {
            cout << printingCharacter;
        }
        cout << "\n";
    }
    return;
}


void Question7()
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
        cout << "\n";
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


void Question8()
{
    int size = 6;
    int arr[size] = {1, 2, 43, 54, 77, 18};
    int toFind;

    cout << "Input number to search: ";
    cin >> toFind;

    int result = find(size, arr, toFind);

    if (result != -1)
    {
        cout << toFind << " found at: " << result << "\n";
    }
    else
    {
        cout << toFind << " not found in array!\n";
    }
    return;
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


void Question9()
{
    int size = 3;
    int arr[size];
    int answer;

    cout << "Array 1 or 2: ";
    cin >> answer;

    if (answer == 1)
    {
        arr[0] = 1;
        arr[1] = 33;
        arr[2] = 12;
    }
    else
    {
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 1;
    }

    int result = find2ndLargest(size, arr);

    if (result != -1)
    {
        cout << "Second largest number: " << result << "\n";
    }
    else
    {
        cout << "No second largest in in array!\n";
    }
    return;
}


void copyArraytoArray(int size, int arr1[], int arr2[])
{
    for (int index = 0; index < size; index++)
    {
        arr2[index] = arr1[index];
    }
	return;
}


void printArray(int size, int arr[])
{
    cout << "{";
    for (int index = 0; index < size; index++)
    {
        cout << arr[index];
        if (index != size - 1)
        {
            cout << ", ";
        }
    }
    cout << "}\n";
}


void Question10()
{
    int size = 4;
    int arr1[size] = {1, 2, 3, 4};
    int arr2[size] = {9, 8, 7, 6};

    cout << "Array 1: ";
    printArray(size, arr1);
    cout << "Array 2: ";
    printArray(size, arr2);

    cout << "Copying.\n";
    copyArraytoArray(size, arr1, arr2);

    cout << "Array 1: ";
    printArray(size, arr1);
    cout << "Array 2: ";
    printArray(size, arr2);

    return;
}


void rightCopyAtIndex(int& count, int arr[], int stoppingIndex)
{
    for (int index = count; index >= stoppingIndex; index--)
    {
        arr[index] = arr[index - 1];
    }
    count += 1;
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
        rightCopyAtIndex(count, arr, insertIndex);
        arr[insertIndex] = elementToInsert;
    }
	return true;
}


void Question11()
{
    int size = 5;
    int count = 3;
    int arr[5] = {1, 2, 4};

    cout << "Array: ";
    printArray(size, arr);

    int elementToInsert = 88;
    int insertIndex = 4;

    bool result = insertElement(size, count, arr, elementToInsert, insertIndex);
    if (result == true)
    {
        cout << "Element inserted!\n";
    }
    else
    {
        cout << "Element not inserted!\n";
    }
    cout << "Array: ";
    printArray(size, arr);

    elementToInsert = 65;
    insertIndex = 1;

    result = insertElement(size, count, arr, elementToInsert, insertIndex);
    if (result == true)
    {
        cout << "Element inserted!\n";
    }
    else
    {
        cout << "Element not inserted!\n";
    }
    cout << "Array: ";
    printArray(size, arr);

    elementToInsert = 12;
    insertIndex = 2;

    result = insertElement(size, count, arr, elementToInsert, insertIndex);
    if (result == true)
    {
        cout << "Element inserted!\n";
    }
    else
    {
        cout << "Element not inserted!\n";
    }
    cout << "Array: ";
    printArray(size, arr);

    return;
}


void Question12()
{

    return;
}


void Question13()
{

    return;
}


void Question14()
{

    return;
}


void Question15()
{

    return;
}


void Question16()
{

    return;
}


void Question17()
{

    return;
}


void Question18()
{

    return;
}


void Question19()
{

    return;
}


int main()
{
    int questionNumber;

    do
    {
        cout << "Input question number: ";
        cin >> questionNumber;
        //questionNumber = 11;

        if (questionNumber == 1)
        {
            Question1();
        }
        else if (questionNumber == 2)
        {
            Question2();
        }
        else if (questionNumber == 3)
        {
            Question3();
        }
        else if (questionNumber == 4)
        {
            Question4();
        }
        else if (questionNumber == 5)
        {
            Question5();
        }
        else if (questionNumber == 6)
        {
            Question6();
        }
        else if (questionNumber == 7)
        {
            Question7();
        }
        else if (questionNumber == 8)
        {
            Question8();
        }
        else if (questionNumber == 9)
        {
            Question9();
        }
        else if (questionNumber == 10)
        {
            Question10();
        }
        else if (questionNumber == 11)
        {
            Question11();
        }
        else if (questionNumber == 12)
        {
            Question12();
        }
        else if (questionNumber == 13)
        {
            Question13();
        }
        else if (questionNumber == 14)
        {
            Question14();
        }
        else if (questionNumber == 15)
        {
            Question15();
        }
        else if (questionNumber == 16)
        {
            Question16();
        }
        else if (questionNumber == 17)
        {
            Question17();
        }
        else if (questionNumber == 18)
        {
            Question18();
        }
        else if (questionNumber == 19)
        {
            Question19();
        }
    }
    while (questionNumber != 0);

    return 0;
}
