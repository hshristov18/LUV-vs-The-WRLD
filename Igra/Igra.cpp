#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
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
	else
	{
		cout << "Okay, I guess you're just too smart." << endl;
	}
	cout << "Now, press 1 if you want to play against your computer or press 2 if you want to play against another player." << endl;
	char opponent;
	cin >> opponent;
	if (opponent == '1')
	{
		cout << "Aw, you don't have friends to play with? Haha Im just kidding(seriously, don't get upset)!" << endl;
		cout << "BeEp bOop+* HelLo hoOmAn!I wiLl gEnerAte foUr rAndoM nUmbErS fOr yOU. WiSh yOu luCk!!+" << endl;
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
				//da se opravi tva
			}
			else
			{
				cout << "Nice, number " << combinations[i] << " is in the range!" << endl;
			}
		}
	}

}

