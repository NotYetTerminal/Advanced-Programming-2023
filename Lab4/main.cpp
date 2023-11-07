#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <fstream>


using namespace std;

int ReadInQuestions()
{
	std::string line;
	std::ifstream myfile("questions.txt");
    int number_of_questions = -1;

	if (myfile.is_open())
	{
	    number_of_questions = 0;
		while (std::getline(myfile, line))
		{
			for (int i = 0; i < line.length(); i++)
			{
				// line.at(i) returns char at position i in string.
				char c = line.at(i);
                number_of_questions *= 10;
                number_of_questions += c - 48;
			}
		}
		myfile.close();
	}
	else
	{
		std::cout << "Unable to open file";
	}
    return number_of_questions;
}


int main()
{
	srand(time(0)); // seed the random number generator, otherwise the rand() will return the same sequence of numbers
	int num = rand() % 10; // returns random int between 0 and 9.



}
