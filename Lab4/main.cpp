// Name: Gábor Major
// Student Number: C00271548
// Modified: 07/11/2023

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int ReadInQuestions(vector<vector<string>>& questionsVector)
{
	string line;
	ifstream myfile("questions.txt");

	if (myfile.is_open())
	{
	    int numberOfQuestions = 0;

		while (std::getline(myfile, line))
		{
		    if (numberOfQuestions == 0)
            {
                for (int i = 0; i < line.length(); i++)
                {
                    // line.at(i) returns char at position i in string.
                    char c = line.at(i);
                    numberOfQuestions *= 10;
                    numberOfQuestions += c - 48;
                }
            }
            else
            {
                vector<string> currentQuestion;
                int stringStart = 0;

                for (int i = 0; i < line.length(); i++)
                {
                    // line.at(i) returns char at position i in string.
                    char c = line.at(i);
                    if (c == ',')
                    {
                        currentQuestion.push_back(line.substr(stringStart, i - stringStart));
                        stringStart = i + 1;
                    }
                }
                currentQuestion.push_back(line.substr(stringStart, line.length() - stringStart));
                questionsVector.push_back(currentQuestion);
            }
		}
		myfile.close();
        return numberOfQuestions;
	}
	else
	{
		cout << "Unable to open file";
		return -1;
	}
}

int main()
{
	srand(time(0)); // seed the random number generator, otherwise the rand() will return the same sequence of numbers
	int num = rand() % 10; // returns random int between 0 and 9.

    vector<vector<string>> questionsVector;
    int result = ReadInQuestions(questionsVector);

    for(int index = 0; index < result; index++)
    {
        vector<string> question = questionsVector.at(index);
        for (int jIndex = 0; jIndex < 6; jIndex++)
        {
            cout << question.at(jIndex) << " ";
        }
        cout << "\n";
    }
}
