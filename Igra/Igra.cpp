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
	while (numbers.size()<desiredSize)
	{
		int number = generateRandomNumberInRange(start, end);
		if (numbers.find(number)==numbers.end())
		{
			numbers.insert(number);
			result.push_back(number);
		}
	}
	return result;
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
	if (instructions == 'Y')
	{
		cout << "The Germans (A player or the computer) place a combination of 4 random numbers in the range between 0 and 7, indicating the coordinates of their battleship." << endl;
		cout << "The code breaker should guess the number within 13 tries. The codebreaker places their guesses. If the german is an another player he should give a feedback whether just a number is guessed or a number and is on a correct place." << endl;
	}
	if (instructions == 'N')
	{
		cout << "Okay, I guess you're just too smart." << endl;
	}
	else
	{
		cout << "Please enter Y or N, nothing else." << endl;
		//a
	}
	cout << "Now, press 1 if you want to play against your computer or press 2 if you want to play against another player." << endl;
	char opponent;
	cin >> opponent;
	if (opponent == '1')
	{
		cout << "Hello human! Aw, you don't have friends to play with? Haha Im just kidding(seriously, don't get upset)!" << endl;
		cout << "You will have to complete two tasks. Let's start with the first one." << endl;
		cout << "I have genereted all eight numbers from 0 to 7 for you. All you have to do is guess four of the numbers and their positions." << endl;
		cout << "Let's begin, take a guess." << endl;
		vector<int> numbers = generateDistinctRandomNumbersInRange(8, 0, 7);
		int tries = 0;
		bool gameOver = false;
		int guessedNumbers = 0;
		while (!gameOver)
		{
			int guessNumber, guessPosition;
			cout << "Enter a number and a position." << endl;
			cin >> guessNumber >> guessPosition;
			vector <int>::iterator numberIt = find(numbers.begin,numbers.end,guessNumber);
			if (numberIt!=numbers.end())
			{
				guessedNumbers++;
			}
			bool foundNumber=numbers.
		}
		while (number != randomNumber)
		{
			cout << "You did not guess any numbers, try again!" << endl;
			cin >> number;
			tries++;
			if (tries == 13)
			{
				cout << "Game over! You failed to save the world..:(" << endl;
				gameOver = true;
				break;
			}
		}
		if (!gameOver)
		{
			cout << "Congratulations player!!! You saved the world!";
		}
	}
	else
	{
		cout << "Sure!" << endl;
		int combinations[4];
		int size = 4;
		cout << "Make a combination of 4 random numbers in the rangeo of 0 and 7." << endl;
		for (int i = 0; i < size; i++)
		{
			cin >> combinations[i];
		}
		for (int i = 0; i < size; i++)
		{
			if (combinations[i] > 7 || combinations[i] < 0)
			{
				cout << "Number " << combinations[i] << " is not in the range of 0 and 7" << endl;
				//a
				cout << "Please enter a new number that is in the range." << endl;
			}
			else
			{
				cout << "Nice, number " << combinations[i] << " is in the range!" << endl;
			}
		}
	}

}

