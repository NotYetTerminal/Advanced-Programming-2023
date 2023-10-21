// Name: Gábor Major
// Student Number: C00271548
// Modified: 21/10/2023

#include <iostream>
#include <string>
#include <fstream>

void HorizontalChart()
{
    std::string line;
    std::ifstream myfile("part1.txt");

    if (myfile.is_open())
	{
		bool firstComma = true;

		while (std::getline(myfile, line))
		{
			int currentNumber = 0;

			for (int i = 0; i < line.length(); i++)
			{
				// line.at(i) returns char at position i in string.
				char c = line.at(i);

				if (c == ',')
				{
					if (firstComma)
					{
						firstComma = false;
					}
					else
					{
						for (int index = 0; index < currentNumber; index++)
						{
							std::cout << 0;
						}
						std::cout << '\n';
						currentNumber = 0;
					}
				}
				else if (!firstComma)
				{
					currentNumber *= 10;
					currentNumber += c - 48;
				}
			}
			for (int index = 0; index < currentNumber; index++)
			{
				std::cout << 0;
			}
			std::cout << '\n';
		}
		myfile.close();
	}
	else
	{
		std::cout << "Unable to open file";
	}
	return;
}

void VerticalChart()
{
    std::string line;
    std::ifstream myfile("part2.txt");

    if (myfile.is_open())
	{
		int numberOfIntegers = 0;

		while (std::getline(myfile, line))
		{
			int currentNumber = 0;

			for (int i = 0; i < line.length(); i++)
			{
				// line.at(i) returns char at position i in string.
				char c = line.at(i);

				if (c == ',')
				{
					if (numberOfIntegers == 0)
					{
						numberOfIntegers = currentNumber;
						currentNumber = 0;
						break;
					}
				}
				else
				{
					currentNumber *= 10;
					currentNumber += c - 48;
				}
			}
		}
		myfile.close();

		std::string line;
		std::ifstream myfile("part2.txt");

		if (!myfile.is_open())
		{
			std::cout << "Unable to open file";
			return;
		}

		int numberArray[numberOfIntegers];
		int arrayIndex = 0;
		int highestNumber = 0;
		bool firstComma = true;

		while (std::getline(myfile, line))
		{
			int currentNumber = 0;

			for (int i = 0; i < line.length(); i++)
			{
				// line.at(i) returns char at position i in string.
				char c = line.at(i);

				if (c == ',')
				{
					if (firstComma)
					{
						firstComma = false;
					}
					else
					{
						numberArray[arrayIndex] = currentNumber;
						arrayIndex++;
						if (currentNumber > highestNumber)
						{
							highestNumber = currentNumber;
						}
					}
					currentNumber = 0;
				}
				else  if (!firstComma)
				{
					currentNumber *= 10;
					currentNumber += c - 48;
				}
			}
			numberArray[arrayIndex] = currentNumber;
			arrayIndex++;
			if (currentNumber > highestNumber)
			{
				highestNumber = currentNumber;
			}
		}
		myfile.close();

		while (highestNumber != 0)
		{
			for (int index = 0; index < numberOfIntegers; index++)
			{
				if (numberArray[index] == highestNumber)
				{
					numberArray[index]--;
					std::cout << 0;
				}
				else
				{
					std::cout << ' ';
				}
			}
			std::cout << '\n';
			highestNumber--;
		}
	}
	else
	{
		std::cout << "Unable to open file";
	}
	return;
}

void CaesarCipher()
{
	std::string line;
    std::ifstream myfile("part3.txt");

    if (myfile.is_open())
	{
		char plainText[1000] = {};
		int arrayIndex = 0;

		while (std::getline(myfile, line))
		{
			for (int i = 0; i < line.length(); i++)
			{
				if (arrayIndex >= 1000)
				{
					break;
				}
				// line.at(i) returns char at position i in string.
				plainText[arrayIndex] = line.at(i);
				arrayIndex++;
			}
		}
		myfile.close();

		int shiftAmount = 0;
		std::cout << "Input shift amount: ";
		std::cin >> shiftAmount;
		std::cout << "Ciphered text: ";

		for (int index = 0; index < arrayIndex; index++)
		{
			char c = plainText[index];
			if (c != ' ')
			{
				c += shiftAmount - 97;
				c %= 26;
				c += 97;
			}
			std::cout << c;
		}
		std::cout << '\n';
	}
	else
	{
		std::cout << "Unable to open file";
	}
	return;
}

int main()
{
	std::cout << "Horizontal Chart:\n";
    HorizontalChart();

	std::cout << "Vertical Chart:\n";
    VerticalChart();

	std::cout << "Caesar Cipher up to 1000 characters.\n";
	CaesarCipher();

    return 0;
}
