// Name: Gábor Major
// Student Number: C00271548
// Modified: 08/11/2023

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Question
{
public:
    string question, option1, option2, option3, option4;
    char answer;

    bool ProcessQuestion()
    {
        cout << question << "\n";
        cout << "1. " << option1 << "\n";
        cout << "2. " << option2 << "\n";
        cout << "3. " << option3 << "\n";
        cout << "4. " << option4 << "\n";

        char input_value;
        cin >> input_value;

        string dummyString;
        getline(cin, dummyString);

        return input_value == answer;
    }
};

class Player
{
public:
    string name, score;
};

int LoadInHighscore(vector<Player>& highscoreVector)
{
    string line;
	ifstream myfile("highscore.txt");

	if (myfile.is_open())
	{
	    while (getline(myfile, line))
		{
		    Player playerData;
            int stringStart = 0;

            for (int i = 0; i < line.length(); i++)
            {
                // line.at(i) returns char at position i in string.
                char c = line.at(i);
                if (c == ';')
                {
                    playerData.name = line.substr(stringStart, i - stringStart);
                    stringStart = i + 1;
                }
            }
            playerData.score = line.substr(stringStart, line.length() - stringStart);
            highscoreVector.push_back(playerData);
		}
	    return 0;
	}
	else
	{
		cout << "Unable to open highscore file\n";
		return -1;
	}
}

int WriteOutHighscore(vector<Player>& highscoreVector)
{
	ofstream myfile("highscore.txt");

	if (myfile.is_open())
	{
	    for (int index = 0; index < highscoreVector.size(); index++)
        {
            myfile << highscoreVector.at(index).name + ";" + highscoreVector.at(index).score + "\n";
        }
	    return 0;
	}
	else
	{
		cout << "Unable to open highscore file\n";
		return -1;
	}
}

int ReadInQuestions(vector<Question>& questionsVector)
{
	string line;
	ifstream myfile("questions.txt");

	if (myfile.is_open())
	{
	    int numberOfQuestions = 0;

		while (getline(myfile, line))
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
                Question questionData;
                int stringStart = 0;
                int stringCounter = 0;

                for (int i = 0; i < line.length(); i++)
                {
                    // line.at(i) returns char at position i in string.
                    char c = line.at(i);
                    if (c == ';')
                    {
                        if (stringCounter == 0)
                        {
                            questionData.question = line.substr(stringStart, i - stringStart);
                        }
                        else if (stringCounter == 1)
                        {
                            questionData.option1 = line.substr(stringStart, i - stringStart);
                        }
                        else if (stringCounter == 2)
                        {
                            questionData.option2 = line.substr(stringStart, i - stringStart);
                        }
                        else if (stringCounter == 3)
                        {
                            questionData.option3 = line.substr(stringStart, i - stringStart);
                        }
                        else if (stringCounter == 4)
                        {
                            questionData.option4 = line.substr(stringStart, i - stringStart);
                        }
                        stringStart = i + 1;
                        stringCounter++;
                    }
                }
                questionData.answer = line.substr(stringStart, line.length() - stringStart)[0];
                questionsVector.push_back(questionData);
            }
		}
		myfile.close();
        return numberOfQuestions;
	}
	else
	{
		cout << "Unable to open questions file\n";
		return -1;
	}
}

int main()
{
    vector<Player> highscoreVector;

    LoadInHighscore(highscoreVector);
    string userName;

    while (true)
    {
        cout << "Input name: ";
        getline(cin, userName);

        if (userName == "")
        {
            cout << "Name cannot be nothing!\n";
        }
        else
        {
            break;
        }
    }

    for (int index = 0; index < userName.length(); index++)
    {
        if (userName.at(index) == ';')
        {
            userName.erase(index, 1);
            break;
        }
    }

    while (true)
    {
        srand(time(0)); // seed the random number generator, otherwise the rand() will return the same sequence of numbers

        cout << "Trivia Quiz\nAnswer with inputting numbers (1-4)\n";

        vector<Question> questionsVector;
        int numberOfQuestions = ReadInQuestions(questionsVector);
        int userScore = 0;

        for (int index = 0; index < numberOfQuestions; index++)
        {
            cout << "Question " << index + 1 << ":\n";

            int chosenIndex = rand() % questionsVector.size();
            Question questionChosen = questionsVector[chosenIndex];
            questionsVector.erase(questionsVector.begin() + chosenIndex);

            if (questionChosen.ProcessQuestion())
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

        Player userData;
        userData.name = userName;
        userData.score = to_string(userScore);
        bool added = false;

        for (int index = 0; index < highscoreVector.size(); index++)
        {
            int score = stoi(highscoreVector.at(index).score);
            if (userScore > score)
            {
                highscoreVector.insert(highscoreVector.begin() + index, userData);
                added = true;
                break;
            }
            else if (userScore == score)
            {
                int stringOrder = userName.compare(highscoreVector.at(index).name);
                if (stringOrder == -1)
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

        cout << "Highscore List:\n";
        for (int index = 0; index < highscoreVector.size(); index++)
        {
            cout << index + 1 << ". " << highscoreVector.at(index).name << ": " << highscoreVector.at(index).score << "\n";
        }

        cout << "Type y to restart or n to quit: ";
        char answer;
        cin >> answer;
        if (answer != 'y')
        {
            break;
        }
        cout << "\n";
    }
}
