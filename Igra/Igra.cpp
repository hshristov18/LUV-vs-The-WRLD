#include <iostream>
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
	for (int i = 0; i < guess.size(); i++)
	{
		if (find(originalNumbers.begin(), originalNumbers.end(), guess[i]) != originalNumbers.end())
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

void playTask(int taskNumber)
{
	cout << "You're playing task " << taskNumber << endl;
	vector<int> numbers = (taskNumber == 1) ? generateDistinctRandomNumbersInRange(8, 0, 7) : 
		generateRandomNumbersInRange(8, 0, 7);
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
			cout << "Congratulations! You win!" << endl;
			playTask(2);
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

void playTaskTwo()
{

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
		cout << "Sure!" << endl;
		int combinations[8];
		int size = 8;
		cout << "Player 1, make a combination of all 8 (don't repeat the numbers) numbers in the rangeo of 0 and 7 (they dont have to be in order)." << endl;
		for (int i = 0; i < size; i++)
		{
			cin >> combinations[i];
		}
		for (int i = 0; i < size; i++)
		{
			while (combinations[i] > 7 || combinations[i] < 0)
			{
				cout << "Number " << combinations[i] << " is not in the range of 0 and 7" << endl;
				cout << "Please enter a new number that is in the range." << endl;
				cin >> combinations[i];
			}
			if (combinations[i] < 7 || combinations[i] > 0)
			{
				cout << "Nice, number " << combinations[i] << " is in the range!" << endl;
			}
		}
	}
}

