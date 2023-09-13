#include <iostream>
#include <cstdlib>

int main()
{
    int firstIntVariable= 10;
    char firstChar = 'a';

    firstIntVariable = 200;
    firstChar = 'b';

    if (firstChar == 'b')
    {
        int test = 10;
    }
    else if (firstIntVariable == 23)
    {
        int test = 20;
    }
    while (firstIntVariable > 100)
    {
        firstIntVariable--;
    }
    for (int index = 0; index < 10; index++)
    {
        std::cout << index << "\n";
    }


    std::cout << "Hello, world!\n";
    return 0;
}
