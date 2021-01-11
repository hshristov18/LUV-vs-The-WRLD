﻿#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>     
#include <time.h>
#include <set>
#include <vector>
using namespace std;

void initialize()
{
	srand(time(NULL));
}

int generateRandomNumberInRange(int start, int end)
{
	return start + rand() % ((end + 1) - start);
}

vector<int> generateDistinctRandomNumbersInRange(int desiredSize, int start, int end)
{
	set<int>::iterator it;
	set<int> numbers;
	vector<int> result;
	while (numbers.size() < desiredSize)
	{
		int number = generateRandomNumberInRange(start, end);
		if (numbers.find(number) == numbers.end())
		{
			numbers.insert(number);
			result.push_back(number);
		}
	}
	return result;
}

vector<int> generateRandomNumbersInRange(int desiredSize, int start, int end)
{
	vector<int> result;
	while (result.size() < desiredSize)
	{
		int number = generateRandomNumberInRange(start, end);
		result.push_back(number);
	}
	return result;
}

int guessedNumbers(vector <int> guess, vector <int> originalNumbers)
{
	int result = 0;
	set <int> guessSet(guess.begin(), guess.end());
	for (int x : guessSet)
	{
		if (find(originalNumbers.begin(), originalNumbers.end(), x) != originalNumbers.end())
		{
			result++;
		}
	}
	return result;
}

int guessedNumbersAndPositions(vector <int> guess, vector <int> originalNumbers)
{
	int result = 0;
	for (int i = 0; i < guess.size(); i++)
	{
		if (guess[i]==originalNumbers[i])
		{
			result++;
		}
	}
	return result;
}

vector <int> enterPlayerNumbers(int playerNumber, int taskNumber ,bool allowRepeating = true)
{
	vector <int> playerNumbers(8);

	if (allowRepeating)
	{
		cout << "You're playing task " << taskNumber << endl;
		cout << "Player " << playerNumber << " , make a combination of all 8 (don't repeat the numbers) numbers in the rangeo of 0 and 7 (they dont have to be in order)." << endl;
	}
	else
	{
		cout << "You're playing task " << taskNumber << endl;
		cout << "Player " << playerNumber << " , make a combination of 8 numbers in the rangeo of 0 and 7 (they dont have to be in order)." << endl;
	}
	for (int i = 0; i < playerNumbers.size(); i++)
	{
		cin >> playerNumbers[i];
		while (playerNumbers[i] > 7 || playerNumbers[i] < 0)
		{
			cout << "Number " << playerNumbers[i] << " is not in the range of 0 and 7" << endl;
			cout << "Please enter a new number that is in the range." << endl;
			cin >> playerNumbers[i];
		}
		if (playerNumbers[i] <= 7 && playerNumbers[i] >= 0)
		{
			cout << "Nice, number " << playerNumbers[i] << " is in the range!" << endl;
		}
	}
	return playerNumbers;
}

void playTask(int taskNumber, bool isBot = true, vector<int> playerNumbers = vector<int>())
{
	if (taskNumber>2)
	{
		return; //here we could add more tasks/levels in future.
	}
	
	vector <int> numbers;
	if (isBot)
	{
		cout << "You're playing task " << taskNumber << endl;
		numbers = (taskNumber == 1) ? generateDistinctRandomNumbersInRange(8, 0, 7) :
			generateRandomNumbersInRange(8, 0, 7);
	}
	else
	{
		numbers = playerNumbers;
	}
	int tries = 0;
	while (tries < 13)
	{
		vector <int> playerGuess(8);
		cout << "Enter 8 numbers for your guess." << endl;
		for (int i = 0; i < 8; i++)
		{
			cin >> playerGuess[i];
		}
		int guessed = guessedNumbers(playerGuess, numbers);
		int guessedPositions = guessedNumbersAndPositions(playerGuess, numbers);
		cout << "You have guessed - " << guessed << " numbers." << endl;
		cout << "You have guessed - " << guessedPositions << " numbers and their positions." << endl;
		if (guessedPositions >= 4)
		{
			if (taskNumber == 2)
			{
				cout << "Congratulations! You win!" << endl;
			}
			if (isBot)
			{
				playTask(taskNumber + 1);
			}
			else
			{
				if (taskNumber+1<=2)
				{
					playTask(taskNumber + 1, false, enterPlayerNumbers(1, taskNumber + 1, false));
				}
			}
			break;
		}
		tries++;
	}
	if (tries>=13)
	{
		cout << "Game over! You lost." << endl;
		cout << "Do you want to play again?" << endl;
		cout << "Enter Y if you want or No if you don't." << endl;
		char instructions;
		cin >> instructions;
		while (instructions != 'Y' && instructions != 'N')
		{
			cout << "Please enter Y or N, nothing else." << endl;
			cin >> instructions;
		}
		if (instructions == 'Y')
		{
			playTask(1);
		}
		else if (instructions == 'N')
		{
			cout << "Alright, your adventure ends here." << endl;
		}
	}
}

int main()
{
	initialize();
	cout << "----------------------- German battleships -----------------------" << endl;
	cout << "Hello player! You're about to play our epic (not really) game, German battleships." << endl;
	cout << "I suggest you to read the instructions. its up to you though.";
	cout << "Press Y if you want the instructions or press N if you don't." << endl;
	char instructions;
	cin >> instructions;
	while (instructions != 'Y' && instructions != 'N')
	{
		cout << "Please enter Y or N, nothing else." << endl;
		cin >> instructions;
	}
	if (instructions == 'Y')
	{
		system("cls");
		cout << "The Germans (A player or the computer) place a combination of 4 random numbers in the range between 0 and 7, indicating the coordinates of their battleship." << endl;
		cout << "The code breaker should guess the number within 13 tries. The codebreaker places their guesses. If the german is an another player he should give a feedback whether just a number is guessed or a number and is on a correct place." << endl;
	}
	else if (instructions == 'N')
	{
		cout << "Okay, I guess you're just too smart." << endl;
	}

	cout << "Now, press 1 if you want to play against another player or press 2 if you want to play against your computer." << endl;
	char opponent;
	cin >> opponent;
	while (opponent != '1' && opponent != '2')
	{
		cout << "Please, enter only 1 or 2." << endl;
		cin >> opponent;
	}
	system("cls");
	if (opponent == '2')
	{
		cout << "Hello human! Aw, you don't have friends to play with? Haha Im just kidding(seriously, don't get upset)!" << endl;
		cout << "You will have to complete two tasks. Let's start with the first one." << endl;
		cout << "I have genereted all eight numbers from 0 to 7 for you. All you have to do is guess four of the numbers and their positions." << endl;
		playTask(1);
		system("cls");
		cout << "Now its time to move to task 2." << endl;
	}
	else
	{
		vector <int> playerOneNumbers = enterPlayerNumbers(1,1);
		system("PAUSE");
		system("cls");
		playTask(1,false,playerOneNumbers);
	}
}

