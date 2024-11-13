#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

enum e_game_choises {stone = 1, paper, scissor};

enum e_game_winer {player = 1, computer, draw};

struct s_round_info
{
	short			round_number = 0;
	e_game_choises	player_choise;
	e_game_choises	computer_choise;
	e_game_winer	game_winer;
	string			winer_name = "";
};

struct s_game_results
{
	short			game_rounds;
	short			player_win_times;
	short			computer_win_times;
	short			draw_times;
	e_game_winer	game_winer;
	string			winer_name = "";
};

int random_number(int from, int to)
{
	int	random_number;

	random_number = rand() % (to - from + 1) + from;
	return (random_number);
}

string	tabs(unsigned int number_of_tabs)
{
	string tab = "";
	for (int i = 0; i < number_of_tabs; i++)
	{
		tab += "\t";
	}
	return (tab);
}

short	read_how_many_rounds()
{
	int rounds = 0;
	do
	{
		cout << "How many rounds do you want to play (1 - 10)?\n-> ";
		cin >> rounds;
	}while(rounds < 1 || rounds > 10);

	return rounds;
}

e_game_choises	get_player_choise()
{
	short	choise;

	do
	{
		cout << "make thy choise:\n1: stone\n2:paper\n3:scissor\n-> ";
		cin >> choise;
	} while (choise < 1 || choise > 3);
	return ((e_game_choises)choise);
}

e_game_choises	get_computer_choise()
{
	return ((e_game_choises)random_number(1, 3));
}

e_game_winer	get_round_winer(s_round_info round_info)
{
	if (round_info.player_choise == round_info.computer_choise)
		return (e_game_winer::draw);
	switch (round_info.player_choise)
	{
	case e_game_choises::stone:
		if (round_info.computer_choise == e_game_choises::paper)
			return (e_game_winer::computer);
			break;
	case e_game_choises::paper:
		if (round_info.computer_choise == e_game_choises::scissor)
			return (e_game_winer::computer);
			break;
	case e_game_choises::scissor:
		if (round_info.computer_choise == e_game_choises::stone)
			return (e_game_winer::computer);
			break;
	}
	return (e_game_winer::player);
}

string	get_winer_name(e_game_winer winer)
{
	string	winer_name[3] = {"Player", "Computer", "Draw"};

	return (winer_name[winer - 1]);
}

string	get_choise_name(e_game_choises choise)
{
	string	choise_name[3] = {"Stone", "Paper", "Scissor"};

	return (choise_name[choise - 1]);
}

void	set_winer_screen_color(e_game_winer winer)
{
	switch (winer)
	{
	case e_game_winer::player:
		system("color 2F");
		break;
	case e_game_winer::computer:
		system("color 4F");
		cout << "\a" << endl;
		break;
	default:
		system("color 6F");
		break;
	}
}

void	print_round_result(s_round_info round_info)
{
	cout << "\n______Round " << round_info.round_number << "______\n";
	cout << "Thy choise is: " << get_choise_name(round_info.player_choise) << "\n";
	cout << "Computer choise is: " << get_choise_name(round_info.computer_choise) << "\n";
	cout << "Thus the winer is: " << round_info.winer_name << endl;
	set_winer_screen_color(round_info.game_winer);
}

e_game_winer	get_game_winer(short player_win_times, short computer_win_times)
{
	if (player_win_times > computer_win_times)
		return (e_game_winer::player);
	else if (player_win_times < computer_win_times)
		return (e_game_winer::computer);
	else
		return (e_game_winer::draw);
}

s_game_results	fill_game_results(short game_rounds, short player_win_times, short computer_win_times, short draw_times)
{
	s_game_results	game_results;
	game_results.game_rounds = game_rounds;
	game_results.player_win_times = player_win_times;
	game_results.computer_win_times = computer_win_times;
	game_results.draw_times = draw_times;
	game_results.game_winer = get_game_winer(player_win_times, computer_win_times);
	game_results.winer_name = get_winer_name(game_results.game_winer);
	return (game_results);
}

s_game_results	play_game(short how_many_rounds)
{
	s_round_info	round_info;
	short			player_win_times = 0;
	short			computer_win_times = 0;
	short			draw_times = 0;

	for (short round_number = 1; round_number <= how_many_rounds; round_number++)
	{
		round_info.round_number = round_number;
		round_info.player_choise = get_player_choise();
		round_info.computer_choise = get_computer_choise();
		round_info.game_winer = get_round_winer(round_info);
		round_info.winer_name = get_winer_name(round_info.game_winer);
	if (round_info.game_winer == e_game_winer::player)
		player_win_times++;
	else if (round_info.game_winer == e_game_winer::computer)
		computer_win_times++;
	else
		draw_times++;
	print_round_result(round_info);
	}
	return (fill_game_results(how_many_rounds, player_win_times, computer_win_times, draw_times));
}

void	show_game_over_screen()
{
	cout << tabs(2) << "_________________________________\n";
	cout << tabs(2) << "    ++++++++Game over++++++++    \n";
	cout << tabs(2) << "_________________________________" << endl;
}

void	print_game_results(s_game_results game_results)
{
	cout << tabs(2) << "_________ [Game results] _________\n\n";
	cout << tabs(2) << "Game rounds       : " << game_results.game_rounds << "\n";
	cout << tabs(2) << "Player win times  : " << game_results.player_win_times << "\n";
	cout << tabs(2) << "Computer win times: " << game_results.computer_win_times << "\n";
	cout << tabs(2) << "Draw times        : " << game_results.draw_times << "\n";
	cout << tabs(2) << "Thus the winer is : " << game_results.winer_name << endl;
	cout << tabs(2) << "__________________________________\n";
	set_winer_screen_color(game_results.game_winer);
}

void	reset_screen()
{
	system("cls");
	system ("color 0F");
}

void	start_game()
{
	string			paly_again = "Y";
	s_game_results	game_results;
	do
	{
		reset_screen();
		game_results = play_game(read_how_many_rounds());
		show_game_over_screen();
		print_game_results(game_results);
		cout << "\n" << tabs(3) << "Dost thou deisre to play again (Y/N)?\n-> ";
		cin >> paly_again;
	} while (paly_again == "Y" || paly_again == "y");
	reset_screen();
}

int	main()
{
	srand((unsigned)time(NULL));
	start_game();
	return (0);
}
