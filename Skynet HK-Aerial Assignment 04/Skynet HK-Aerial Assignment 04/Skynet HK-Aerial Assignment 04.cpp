// Skynet HK-Aerial Assignment 04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	char playAgain; // holds inputs 

	cout << "Ptrack is online and ready to challange you human!" << endl << endl;
	do // This forces the player to play at least once. This is where we will restart the loop.
	{
		srand(static_cast<unsigned int>(time(0))); // Seed random number generator
		int highNum = 64; 
		int lowNum = 1; 
		const int targetPos = rand() % highNum + lowNum; //  AI is trying to find this number
		int randomAIPos = rand() % 64; // randomAI's guess is held here
		int guess; // This is the number the AI is scanning
		int humanGuess; // Humans guess is held in this variable
		int ai1Tries = 0; //  number of attempts it took binary search AI to find the target
		int ai2Tries = 0; //  number of attempts it took linear search AI to find the target
		int ai3Tries = 0; //  number of attempts it took random search AI to find the target
		int humanTries = 0; // number of attempts it took the player to find the target
		int winner; //  number of attempts it took the winner to find the target

		do // Do loop! This runs at least once! Human Guess
		{
			cout << "Alright human, guess where the prisoner is on an 8x8 grid (1-64)" << endl; // Prompt user to enter their guess
			cin >> humanGuess; //  called every time the loop restarts. makes player guess again 
			cout << "\nSearching cell " << humanGuess << "." << endl;

			if (humanGuess > targetPos) // if target is smaller than our guess
			{
				cout << "Prisoner not found. \nYou must search a lower position." << endl << endl;
				humanTries++; // add 1 to tries, so we know how many attempts it took the player
			}
			else if (humanGuess < targetPos) // if target is larger than our guess
			{
				cout << "Prisoner not found. \nYou must search a higher position." << endl << endl;
				humanTries++; // add 1 to tries, so we know how many attempts it took the player
			}
			else
			{
				humanTries++; // add 1 to tries, so we know how many attempts it took the player
				cout << "Prisoner sighted at " << targetPos << endl; // print the block that we found our target at.
				cout << "Scanned " << humanTries << " cells to find the Prisoner." << endl << endl; // Print the number of tries it took us to get the correct number
			}
		} while (humanGuess != targetPos); // This restarts the human guess loop

		do // Do loop! This runs at least once! Binary Search
		{
			guess = ((highNum - lowNum) / 2) + lowNum; // This will get called every time the loop restarts. It will make the computer choose a new guess.
			cout << "Initiating search at position " << guess << "." << endl;

			if (guess > targetPos)
			{
				cout << "Target not found. \nInitiating search at lower position." << endl << endl;
				highNum = guess; // If number is too high, then we make highNum the guess, so when we restart the loop, the computer cannot guess any higher than our previous number
				ai1Tries++; // add 1 to tries, so we know how many attempts it took the computer
			}
			else if (guess < targetPos)
			{
				cout << "Target not found. \nInitiating search at higher position." << endl << endl;
				lowNum = guess; // If number is too low, then we make lowNum the guess, so when we restart the loop, the computer cannot guess any lower than our previous guess
				ai1Tries++; // add 1 to tries, so we know how many attempts it took the computer
			}
			else
			{
				ai1Tries++; // add 1 to tries, so we know how many attempts it took the computer
				cout << "Prisoner sighted at " << targetPos << endl; // print the block that we found our target at.
				cout << "Scanned " << ai1Tries << " cell to find the Prisoner." << endl << endl; // Print the number of tries it took us to get the correct number

			}

		} while (guess != targetPos); // This is the loop part of the Do. As long as the AI hasn't found the target it will keep searching.

		for (int i = 0; i <= targetPos; i++) // Linear Search
		{
			if (i != targetPos) // if the iteration of our search is not equal to the targets position
			{
				cout << "Prisoner not in cell " << i << "." << endl;
			}
			else // if the iteration of our search is equal to the targets position
			{
				cout << "Prisoner sighted in cell " << i << "." << endl;
				cout << "It took " << ai2Tries << " tries to find the Prisoner." << endl;
			}
			ai2Tries++; // add 1 to ai2's tries
		}

		while (true) // Random Search
		{
			ai3Tries++; // add 1 to ai3's tries
			if (randomAIPos != targetPos) // if the random AI's guess is not equal to the targets position
			{
				cout << "Prisoner not found at " << randomAIPos << endl;
				randomAIPos = rand() % 64 + 1; // pick a new random number
			}
			else // if the random AI's guess is equl to the targets position
			{
				cout << "Prisoner found at " << targetPos << endl;
				cout << "It took AI 3 " << ai3Tries << " tries to find the cell." << endl;
				break; // break the loop when we have found the targets position
			}

		}
		cout << "The binary AI took " << ai1Tries << " to find the Prisoner." << endl; // Results 
		cout << "The linear AI took " << ai2Tries << " to find the Prisoner." << endl; // Results
		cout << "The Random AI took " << ai3Tries << " to find the Prisoner." << endl; // Results
		cout << "You took " << humanTries << " trys to find the Prisoner." << endl; // Results 

		winner = min(ai1Tries, min(ai2Tries, min(ai3Tries, humanTries))); // Sets the winner equal to the lowest number of tries so we can compare them next.

																		  // Below print out the name of the AI that won!
		if (winner == ai1Tries)
		{
			cout << "Binary Search AI Wins!" << endl;
		}
		else if (winner == ai2Tries)
		{
			cout << "Linear Search AI Wins!" << endl;
		}
		else if (winner == ai3Tries)
		{
			cout << "Random Search AI Wins!" << endl;
		}
		else if (winner == humanTries)
		{
			cout << "Human Player 1 Wins!" << endl;
		}

		cout << "\n\nWould you like to play again?\nY/N" << endl; // Ask player if they want to play again or not
		cin >> playAgain; // Player input for wrether they want to play again or not
		while (playAgain != 'Y' && playAgain != 'N' && playAgain != 'y' && playAgain != 'n') // This loop catches invalid inputs
		{
			cout << "Error: Invalid Input.\nPlease Select a valid operator\n";
			cin >> playAgain;
		}
	} while (playAgain == 'y' || playAgain == 'Y');

	system("pause"); // Pause the console
	return 0;
}