
#include <iostream>
#include "functions.h"
using namespace std;
int main()
{
	//Examples of how to call the functions



	int question1[5] = { 1,2,3,4,1 };
	bool palinArrayresult = IsPalindromicArray(question1, 5);

	cout << palinArrayresult << "\n";


	int  question2[5][5] = { {1,1,1,0,1},
						{1,1,1,1,1},
						{1,1,0,1,0},
						{1,1,1,1,0},
						{1,0,0,1,0}
	};


	int count = CountNumOfColsContainOneZeroOnly(question2);
	cout << count << "\n";

	int  question3[6][6] = { {0,1,1,1,1,1},
                             {0,1,0,0,0,1},
                             {0,1,0,0,0,1},
                             {0,1,0,0,0,1},
                             {0,1,0,0,0,1},
                             {0,1,1,1,1,1}
	};
	int area = AreaOfRectangleOutlinedBy1s(question3);
    cout << area << "\n";

}
