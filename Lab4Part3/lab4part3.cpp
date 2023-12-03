// Name: Gábor Major
// Student Number: C00271548
// Modified: 08/11/2023

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"

using namespace std;
using namespace rapidjson;

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

int LoadInHighscore(vector<Player>& highscoreVector, Document& document)
{
    string line;
    ifstream myfile("highscore.json");

    char json[10000] = "";
    int ji = 0;
    if (myfile.is_open())
    {
        while (std::getline(myfile, line))
        {
            for (int i = 0; i < line.length(); i++)
            {
                // line.at(i) returns char at position i in string.
                char c = line.at(i);
                json[ji++] = c;
            }

        }
        myfile.close();

        if (document.Parse(json).HasParseError())
        {
            return -1;
        }

        assert(document.IsObject());

        Value& highscoresData = document["highscoreVector"];
        assert(highscoresData.IsArray());

        for (int index = 0; index < highscoresData.Size(); index++)
        {
            Player playerData;
            playerData.name = highscoresData[index]["name"].GetString();
            playerData.score = highscoresData[index]["score"].GetString();
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

int WriteOutHighscore(vector<Player>& highscoreVector, Document& document)
{
    ofstream myfile("highscore.json");

	if (myfile.is_open())
    {
        Value& highscoresData = document["highscoreVector"];
        assert(highscoresData.IsArray());

        highscoresData.Clear();

        for (int index = 0; index < highscoreVector.size(); index++)
        {
            Value o(kObjectType);

            string temp = highscoreVector.at(index).name;
            o.AddMember("name", "", document.GetAllocator());
            o["name"].SetString(temp.data(), temp.size(), document.GetAllocator());

            temp = highscoreVector.at(index).score;
            o.AddMember("score", "", document.GetAllocator());
            o["score"].SetString(temp.data(), temp.size(), document.GetAllocator());

            highscoresData.PushBack(o, document.GetAllocator());
        }

	    StringBuffer sb;
        PrettyWriter<StringBuffer> writer(sb);

        document.Accept(writer);

        string jsonOut(sb.GetString(), sb.GetSize());
        myfile << jsonOut;
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
    ifstream myfile("questions.json");

    char json[10000] = "";
    int ji = 0;
    if (myfile.is_open())
    {
        while (std::getline(myfile, line))
        {
            for (int i = 0; i < line.length(); i++)
            {
                // line.at(i) returns char at position i in string.
                char c = line.at(i);
                json[ji++] = c;
            }

        }
        myfile.close();

        Document document;

        if (document.Parse(json).HasParseError())
        {
            return -1;
        }

        assert(document.IsObject());

        int numberOfQuestions = document["questionNumber"].GetInt();

        Value& questionsData = document["questionsVector"];
        assert(questionsData.IsArray());

        for (int index = 0; index < questionsData.Size(); index++)
        {
            Question questionData;
            questionData.question = questionsData[index]["question"].GetString();
            questionData.option1 = questionsData[index]["option1"].GetString();
            questionData.option2 = questionsData[index]["option2"].GetString();
            questionData.option3 = questionsData[index]["option3"].GetString();
            questionData.option4 = questionsData[index]["option4"].GetString();
            questionData.answer = questionsData[index]["answer"].GetString()[0];
            questionsVector.push_back(questionData);
        }
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

    Document highscoreDocument;

    LoadInHighscore(highscoreVector, highscoreDocument);
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

        WriteOutHighscore(highscoreVector, highscoreDocument);

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
