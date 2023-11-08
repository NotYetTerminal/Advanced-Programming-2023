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

int LoadInHighscore(vector<vector<string>>& highscoreVector)
{
    string line;
	ifstream myfile("highscore.txt");

	if (myfile.is_open())
	{
	    return 0;
	}
	else
	{
		cout << "Unable to open highscore file";
		return -1;
	}
}

int WriteOutHighscore(vector<vector<string>> highscoreVector)
{
    string line;
	ifstream myfile("highscore.txt");

	if (myfile.is_open())
	{
	    return 0;
	}
	else
	{
		cout << "Unable to open highscore file";
		return -1;
	}
}

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
		cout << "Unable to open questions file";
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
    vector<vector<string>> highscoreVector;

    LoadInHighscore(highscoreVector);

    cout << "Input name: ";
    string userName;
    getline(cin, userName);

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

        vector<string> userData{userName, userScore};
        bool added = false;

        for (int index = 0; index < highscoreVector.size(); index++)
        {
            int score = stoi(highscoreVector.at(index)[1])
            if (userScore > score)
            {
                highscoreVector.insert(highscoreVector.begin() + index, userData);
                added = true;
                break;
            }
            else if (userScore == score)
            {
                if (userName > highscoreVector.at(index)[0])
                {
                    highscoreVector.insert(highscoreVector.begin() + index, userData);
                    added = true;
                    break;
                }
            }
        }
        if (!added)
        {
            highscoreVector.push_back(userData);
        }

        WriteOutHighscore(highscoreVector);

        cout << "Highscore List:\n"
        for (int index = 0; index < highscoreVector.size(); index++)
        {
            cout << index + 1 << ". " << highscoreVector.at(index)[0] << ": " << highscoreVector.at(index)[1];
        }

        cout << "Type y to restart or n to quit: ";
        char answer;
        cin >> answer;
        if (answer != 'y')
        {
            break;
        }
    }
}
