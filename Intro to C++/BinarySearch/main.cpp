#include "main.h"
#include <iostream>
using namespace std;

int main()
{
	int First = 0;
	int Last = 100;
	char Choice;
	char Direction;
	bool GameRunning = true;
//	char end;

	char ch;
	//pick a random number between 0 & 100 including both
	cout << "Think of an integer number between 0 and " << Last << endl;
	cout << "Write it down on a piece of paper then hit a key to continue" << endl << endl;
	cin.get(ch);
	cout << endl << "I am going to guess the number you picked... You just need to give me some hints" << endl << endl;
	cout << "Hit any key when you're ready..." << endl << endl;
	cin.get(ch);

	//is Computer guess right?
	while (GameRunning = true)
	{
		int Middle = (First + Last) / 2;
		cout << "is this the number you chose: " << Middle << endl;
		cout << "If it is the number Type Y , otherwise type N " << endl;
		cin >> Choice;
		if (Choice == 'Y')
		{
			cout << "i win" << endl;
			GameRunning = false;
		}
		else if (Choice == 'N')
			cout << "If the number is Higher type 'H', if the Number is Lower, Type 'L'" << endl;
		cin >> Direction;
		{
			//is it higher (type H) or lower (Type L)
			if (Direction == 'H')
			{
				First = Middle+1;
				GameRunning = true;
			}
			else if (Direction == 'L')
			{
				Last = Middle - 1;
				GameRunning = true;
			}
		}
	}
}

main::~main()
{
}
