// CodeBreaker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
char again = 'y';
int main()
{
	do {
		enum fields { WORD, HINT, NUM_FIELDS };
		const int NUM_WORDS = 10;
		const string WORDS[NUM_WORDS][NUM_FIELDS] =
		{
			{ "rain", "it falls from the sky" },
			{ "boat","likes to float" },
			{ "book","old fashioned kindle" },
			{ "simulation","is it real?" },
			{ "jumble","its what the game is all about" },
			{ "rain", "it falls from the sky" },
			{ "glasses","these might help you see the answer" },
			{ "labored","going slowly is it?" },
			{ "presistent","keep at it" },
			{ "jumble","its what the game is all about" }
		};

		srand(static_cast<unsigned int>(time(0)));
		int choice = (rand() % NUM_WORDS);
		string theWord = WORDS[choice][WORD]; //word to guess
		string theHint = WORDS[choice][HINT]; //hint for the guess

		string jumble = theWord;
		string jumblecheck = jumble;
		int length = jumble.size();
		do
		{
			for (int i = 0; i < length; ++i)
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			}
		} while (jumble == jumblecheck);

		cout << "Welcome to Word Jumble\n\n";
		cout << "Unscramble the letters to make a word.\n";
		cout << "Enter 'hint' for a hint.\n";
		cout << "enter 'quit' to quit the game.\n";

		cout << "The jumble is : " << jumble;

		string guess;
		cout << "\n\nYour guess: ";
		cin >> guess;

		while ((guess != theWord) && (guess != "quit"))
		{
			if (guess == "hint")
			{
				cout << theHint;
			}
			else
			{
				cout << "Sorry thats not it.";
			}
			cout << "\n\nYour guess: ";
			cin >> guess;
		}
		if (guess == theWord)
		{
			cout << "\n thats correct";

		}
		if (guess != "quit")
		{
			cout << "\nThanks for playing.\nWould you like to play again (y/n): ";
			cin >> again;
		}
		else if (guess == "quit") {
			cout << "Thnaks for playing";
			again = "n";
		}
	} while (again == 'y');
    return 0;
}
 
