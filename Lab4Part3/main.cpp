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

int LoadInHighscore(vector<vector<string>>& highscoreVector, Document& document)
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
            highscoreVector.push_back({highscoresData[index]["name"].GetString(), highscoresData[index]["score"].GetString()});
        }
        return 0;
    }
    else
    {
        cout << "Unable to open highscore file\n";
		return -1;
    }
}

int WriteOutHighscore(vector<vector<string>> highscoreVector, Document& document)
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

            string temp = highscoreVector.at(index)[0];
            o.AddMember("name", "", document.GetAllocator());
            o["name"].SetString(temp.data(), temp.size(), document.GetAllocator());

            temp = highscoreVector.at(index)[1];
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

int ReadInQuestions(vector<vector<string>>& questionsVector)
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
            questionsVector.push_back({questionsData[index]["question"].GetString(),
                                       questionsData[index]["option1"].GetString(),
                                       questionsData[index]["option2"].GetString(),
                                       questionsData[index]["option3"].GetString(),
                                       questionsData[index]["option4"].GetString(),
                                       questionsData[index]["answer"].GetString()});
        }
        return numberOfQuestions;
    }
    else
    {
        cout << "Unable to open questions file\n";
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
        if (userName.at(index) == ',')
        {
            userName.erase(index, 1);
            break;
        }
    }

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

        vector<string> userData{userName, to_string(userScore)};
        bool added = false;

        for (int index = 0; index < highscoreVector.size(); index++)
        {
            int score = stoi(highscoreVector.at(index)[1]);
            if (userScore > score)
            {
                highscoreVector.insert(highscoreVector.begin() + index, userData);
                added = true;
                break;
            }
            else if (userScore == score)
            {
                int stringOrder = userName.compare(highscoreVector.at(index)[0]);
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
            cout << index + 1 << ". " << highscoreVector.at(index)[0] << ": " << highscoreVector.at(index)[1] << "\n";
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
