#pragma once

#pragma once
//Student Name: Gabor Major
//Student No: C00271548

// Do not cout any values within these functions.
// This is a closed book exam.
// You may only use int, char and bool datatypes.





//Question 1 : (30 Marks)


//check if a 1D integer array is palindromic,
//i.e., it remains the same when reversed.
//or  it reads the same from left to right and from right to left.

// int arr[] = {1, 2, 3, 2, 1}; is palindromic
//int arr[] = { 1, 2, 3, 3, 1 } is not
bool IsPalindromicArray(int arr[], int arrSize)
{
    for (int index = 0; index < arrSize; index++)
    {
        if (arr[index] != arr[arrSize - index - 1])
        {
            return false;
        }
    }
	return true;
}

//Question 2 ; ( 40 Marks)
//Count and return the number of colums  in mz that contain only 1 zero.
int  CountNumOfColsContainOneZeroOnly(int mz[5][5])
{
    int columnCount = 0;
    for (int column = 0; column < 5; column++)
    {
        bool oneZero = false;
        for (int row = 0; row < 5; row++)
        {
            if (mz[row][column] == 0)
            {
                if (oneZero)
                {
                    oneZero = false;
                    break;
                }
                else
                {
                    oneZero = true;
                }
            }
        }
        if (oneZero)
        {
            columnCount++;
        }
    }
	return columnCount;
}

//Question 3 ; ( 30 Marks)
// find the area of the rectangle outlined by 1's. There will be one rectangle.
// examples
/*
000000
011110
010010
010010
010010
011110

answer 20 : 4*5
Example 2
011100
010100
011100
000000
000000
000000
answer 9 : 3*3  (note: this is the smallest possible rectangle)


*/
int AreaOfRectangleOutlinedBy1s(int grid[6][6])
{
    int length = 0;
    int width = 0;
    for(int row = 0; row < 6; row++)
    {
        for (int column = 0; column < 6; column++)
        {
            if (grid[row][column] == 1)
            {
                for (int index = column; index < 6; index++)
                {
                    if (grid[row][index] == 1) // accidentally wrote arr instead of grid on paper
                    {
                        width++;
                    }
                    else
                    {
                        break;
                    }
                }
                for (int index = row; index < 6; index++)
                {
                    if (grid[index][column] == 1) // accidentally wrote arr instead of grid on paper
                    {
                        length++;
                    }
                    else
                    {
                        break;
                    }
                }
                return length * width;
            }
        }
    }
	return 0;
}
