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
}


int main()
{
    int questionNumber;

    cout << "Input question number: ";
    cin >> questionNumber;

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

    return 0;
}
