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


bool ProcessQuestion(vector<string> question)
{
    cout << question[0] << "\n";
    cout << "1. " << question[1] << "\n";
    cout << "2. " << question[2] << "\n";
    cout << "3. " << question[3] << "\n";
    cout << "4. " << question[4] << "\n";

    char input_value;
    cin >> input_value;

    string dummyString;
    getline(cin, dummyString);

    return input_value == question[5].at(0);
}


int main()
{
    while (true)
    {
        srand(time(0)); // seed the random number generator, otherwise the rand() will return the same sequence of numbers

        cout << "Trivia Quiz\nAnswer with inputting numbers (1-4)\n";

        vector<vector<string>> questionsVector;
        int numberOfQuestions = ReadInQuestions(questionsVector);
        int userScore = 0;

        for (int index = 0; index < numberOfQuestions; index++)
        {
            cout << "Question " << index + 1 << ":\n";

            int chosenIndex = rand() % questionsVector.size();
            vector<string> questionChosen = questionsVector[chosenIndex];
            questionsVector.erase(questionsVector.begin() + chosenIndex);

            if (ProcessQuestion(questionChosen))
            {
                cout << "Correct\n";
                userScore++;
            }
            else
            {
                cout << "Wrong\n";
            }
            #ifdef _WIN32
            system("pause");
            #else
            system("read");
            #endif
        }
        cout << "You got " << userScore << " out of " << numberOfQuestions << " questions correct.\n";
        cout << "Type y to restart or n to quit: ";
        char answer;
        cin >> answer;
        if (answer != 'y')
        {
            break;
        }
    }
}
