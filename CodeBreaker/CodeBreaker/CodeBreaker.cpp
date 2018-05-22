// CodeBreaker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] = 
	{
		{"wall", "Do you feel like you're banging your head against something"},
		{"glasses","these might help you see the answer"},
		{"labored","going slowly is it?"},
		{"presistent.","keep at it"},
		{"jumble","its what the game is all about"}
	};

	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD]; //word to guess
	string theHHint = WORDS[choice][WORD]; //hint for the guess
	
	string jumble = theWord;
	int length = jumble.size();
	for (int i = 0; i < length; ++i) 
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}
	
	cout << "Welcome to Word Jumble\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "enter 'quit' to quit the game.\n";

	
    return 0;
}
 
