#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

enum	e_questions_level {Easy = 1, Medium, Hard, Mixed};

enum	e_questions_type {Add = 1, Sub, Mul, Div, Mix};

struct	s_game_results
{
	e_questions_level	questions_level;
	e_questions_type	questions_type;
	short				right_answers = 0;
	short				false_answers = 0;
};

void	reset_screen(void)
{
	system("cls");
	system ("color 0F");
}

short	read_how_many_questions(void)
{
	int questions = 0;
	do
	{
		cout << "How many questions do you want to answer (1 - 10)?\n-> ";
		cin >> questions;
	}while(questions < 1 || questions > 10);

	return questions;
}

e_questions_level	read_questions_level(void)
{
	int	level = 0;

	do
	{
		cout << "Enter questions level: [1] Easy, [2] Medium, [3] Hard, [4] Mixed\n-> ";
		cin >> level;
	}while(level < 1 || level > 4);
	return e_questions_level(level);
}

e_questions_type	read_questions_type(void)
{
	int	type = 0;

	do
	{
		cout << "Enter questions type: [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix\n-> ";
		cin >> type;
	}while(type < 1 || type > 5);
	return e_questions_type(type);
}

int random_number(int from, int to)
{
	int	random_number;

	random_number = rand() % (to - from + 1) + from;
	return (random_number);
}

short	print_question_and_return_answer(short number1, short number2, e_questions_type questions_type)
{
	cout << number1 << endl;
	cout << number2 << " ";
	if (questions_type == e_questions_type::Mix)
		questions_type = (e_questions_type)random_number(1, 4);
	switch (questions_type)
	{
		case e_questions_type::Add:
			cout << "+\n_____\n";
			return (number1 + number2);
			break;
		case e_questions_type::Sub:
			cout << "-\n_____\n";
			return (number1 - number2);
			break;
		case e_questions_type::Mul:
			cout << "*\n_____\n";
			return (number1 * number2);
			break;
		case e_questions_type::Div:
			cout << "/\n_____\n";
			return (number1 / number2);
			break;
		default:
			break;
	}
	return (0);
}

void	set_numbers(short &number1, short &number2, e_questions_level question_level)
{
	if (question_level == e_questions_level::Mixed)
		question_level = (e_questions_level)random_number(1, 3);
	if(question_level == e_questions_level::Easy)
	{
		number1 = random_number(0, 9);
		number2 = random_number(0, 9);
	}
	else if(question_level == e_questions_level::Medium)
	{
		number1 = random_number(10, 99);
		number2 = random_number(0, 9);
	}
	else if(question_level == e_questions_level::Hard)
	{
		number1 = random_number(10, 99);
		number2 = random_number(10, 99);
	}
}

int	generate_question(e_questions_level qustions_level, e_questions_type questions_type)
{
	short	number1, number2;
	set_numbers(number1, number2, qustions_level);
	return (print_question_and_return_answer(number1, number2, questions_type));
	return (0);
}

string	get_level_name(e_questions_level questions_level)
{
	string	level[4] = {"Easy", "Medium", "Hard", "Mixed"};

	return (level[questions_level - 1]);
}

string	get_type_name(e_questions_type questions_type)
{
	string	type[5] = {"Add", "Sub", "Mul", "Div", "Mix"};

	return (type[questions_type - 1]);
}

void	show_passing_screen(short right_answers, short false_answers)
{
	if (right_answers >= false_answers)
		cout << "You Passed" << endl;
	else
		cout << "You failed" << endl;
}

void	game_over_screen(s_game_results game_results)
{
	cout << "Questions level is:" << get_level_name(game_results.questions_level) << "\n";
	cout << "Questions type is :" << get_type_name(game_results.questions_type) << "\n";
	cout << "Right answers     :" << game_results.right_answers << "\n";
	cout << "False answers     :" << game_results.false_answers << endl;
	show_passing_screen(game_results.right_answers, game_results.false_answers);
}

void	right_answer_screen()
{
	system("color 2F");
	cout << "Thy answer is right :-)" << endl;
}

void	false_answer_screen(int right_answer)
{
	system("color 4F");
	cout << "\a";
	cout << "Thy answer is false :-(\n";
	cout << "The right answer is: " << right_answer << endl;
}

s_game_results	play_game(short how_many_questions, e_questions_level qustions_level, e_questions_type questions_type)
{
	s_game_results	game_results;
	int				answer = 0;
	int				right_answer = 0;

	game_results.questions_level = qustions_level;
	game_results.questions_type = questions_type;
	for (short question_number = 1; question_number <= how_many_questions; question_number++)
	{
		cout << "Question [" << question_number << "]" << endl;
		right_answer = generate_question(qustions_level, questions_type);
		cin >> answer;
		if (answer == right_answer)
		{
			right_answer_screen();
			game_results.right_answers++;
		}
		else
		{
			false_answer_screen(right_answer);
			game_results.false_answers++;
		}
	}
	return (game_results);
}

void	start_game(void)
{
	string			play_again = "Y";
	s_game_results	game_results;

	do
	{
		reset_screen();
		game_results = play_game(read_how_many_questions(), read_questions_level(), read_questions_type());
		game_over_screen(game_results);
		cout << "Dost thou desire to play again [Y/N]?\n-> ";
		cin >> play_again;
	} while (play_again == "Y" || play_again == "y");
	reset_screen();
}

int	main(void)
{
	srand((unsigned)time(NULL));
	start_game();
	return (0);
}
