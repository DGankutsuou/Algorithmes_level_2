#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

enum e_game {stone = 1, paper, scissor};
int	read_positive_number(string message)
{
	int number = 0;
	do
	{
		cout << message;
		cin >> number;
	}while(number <= 0);

	return number;
}

int	random_number(int from, int to)
{
	int random_number;
	random_number = rand() % (to - from + 1) + from;
	return (random_number);
}

void	show_round_result(int round, int &player_score, int &computer_score, short player_choise, short computer_choise, int &no_winer)
{
	cout << "\n***** round " << round << " *****\n";
	switch (player_choise)
	{
	case 1:
		cout << "Thou choose stone" << endl;
		break;
	case 2:
		cout << "Thou choose paper" << endl;
		break;
	case 3:
		cout << "Thou choose scissor" << endl;
		break;
	default:
		break;
	}

	switch (computer_choise)
	{
	case 1:
		cout << "The computer choose stone" << endl;
		break;
	case 2:
		cout << "The computer choose paper" << endl;
		break;
	case 3:
		cout << "The computer choose scissor" << endl;
		break;
	default:
		break;
	}
	if (player_choise == computer_choise)
	{
		cout << system("color 6F") << endl;
		cout << "There is no winer in this round" << endl;
		no_winer++;
	}
	else if (player_choise == computer_choise + 1 || player_choise + 2 == computer_choise)
	{
		cout << system("color 2F") << endl;
		cout << "The player won this round" << endl;
		player_score++;
	}
	else
	{
		cout << system("color 4F") << endl;
		cout << "The computer won this game" << endl;
		cout << "\a" << endl;
		computer_score++;
	}
	cout << "Player score: " << player_score << endl;
	cout << "computer score: " << computer_score << endl;
}

void	show_game_result(int player_score, int computer_score, int no_winer)
{
	cout << "\n+++ game over +++\n";
	cout << "Player score: " << player_score << endl;
	cout << "computer score: " << computer_score << endl;
	cout << "There was no winer " << no_winer << " time(s)" << endl;
	if (player_score > computer_score)
		cout << "The player won this game" << endl;
	else if (player_score < computer_score)
		cout << "The computer won this game" << endl;
	else
		cout << "There is no winer in this game" << endl;
}

bool	desire_to_play()
{
	string	desire_to_play;
	do
	{
		cout << "Dost thou desire to play again (yes or no): ";
		cin >> desire_to_play;
	} while (desire_to_play != "no" && desire_to_play != "yes");
	if (desire_to_play == "yes")
		return (true);
	else
		return (false);
}

short	player_choising()
{
	short	choise;
	do
	{
		cout << "\nmake thy choise\n";
		cout << "1: stone\n";
		cout << "2: paper\n";
		cout << "3: scissor" << endl;
		cout << "-> ";
		cin >> choise;
	} while (choise != 1 && choise != 2 && choise != 3);
	return (choise);
}

void	stone_paper_scissor()
{
	short	player_choise;
	short	computer_choise;
	int		rounds;
	int		counter;
	int		player_score;
	int		computer_score;
	int		no_winer;

	do
	{
		player_score = 0;
		computer_score = 0;
		no_winer = 0;
		counter = 1;
		cout << system("color 0F") << endl;
		rounds = read_positive_number("How many round dost thou desire to play?\n-> ");
		while (counter <= rounds)
		{
			player_choise = player_choising();
			computer_choise = rand() % 3 + 1;
			show_round_result(counter, player_score, computer_score, player_choise, computer_choise, no_winer);
			counter++;
		}
		show_game_result(player_score, computer_score, no_winer);
	}
	while (desire_to_play());
	cout << system("color 0F") << endl;
}

int main()
{
	srand((unsigned)time(NULL));
	stone_paper_scissor();
	return (0);
}
