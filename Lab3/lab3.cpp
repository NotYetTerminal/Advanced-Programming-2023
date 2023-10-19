#include <iostream>
#include <string>
#include <fstream>

int OpenFile()
{
    std::string line;

    std::ifstream myfile("example.txt");

    if (myfile.is_open())
	{
		while (std::getline(myfile, line))
		{
			for (int i = 0; i < line.length(); i++)
			{
				// line.at(i) returns char at position i in string.
				char c = line.at(i);
				std::cout << c;
			}
			std::cout << std::endl;
		}
		myfile.close();
	}
	else
	{
		std::cout << "Unable to open file";
	}
	return 0;
}


int main(int argc, char **argv)
{
    OpenFile();

    return 0;
}
