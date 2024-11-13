#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

enum	e_questions_level {Easy = 1, Medium, Hard, Mixed};

enum	e_op_type {Add = 1, Sub, Mul, Div, Mix};

void	reset_screen(void)
{
	system("cls");
	system ("color 0F");
}

int random_number(int from, int to)
{
	int	random_number;

	random_number = rand() % (to - from + 1) + from;
	return (random_number);
}

struct	s_question
{
	short	number1 = 0;
	short	number2 = 0;
	e_questions_level	questions_level;
	e_op_type			op_type;
	short				correct_answer = 0;
	short				player_answer = 0;
	bool				answer_result = false;
};

struct	s_quizz
{
	s_question			question[100];
	short				number_of_qustions;
	e_questions_level	questions_level;
	e_op_type			op_type;
	short				number_of_correct_answers = 0;
	short				number_of_uncorrect_answers = 0;
	bool				is_pass = false;
};

short	read_how_many_questions(void)
{
	int questions = 0;
	do
	{
		cout << "How many questions do you want to answer (1 - 100)?\n-> ";
		cin >> questions;
	}while(questions < 1 || questions > 100);

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

e_op_type	read_op_type(void)
{
	int	type = 0;

	do
	{
		cout << "Enter operator type: [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix\n-> ";
		cin >> type;
	}while(type < 1 || type > 5);
	return e_op_type(type);
}

short simple_calculator(short number1, short number2, e_op_type op_type)
{
	switch(op_type)
	{
		case e_op_type::Add:
			return number1 + number2;
		case e_op_type::Sub:
			return number1 - number2;
		case e_op_type::Mul:
			return number1 * number2;
		case e_op_type::Div:
			return number1 / number2;
	}
	return 0;
}

s_question	generate_question(e_questions_level questions_level, e_op_type op_type)
{
	s_question	question;

	if (questions_level == e_questions_level::Mixed)
		questions_level = (e_questions_level)random_number(1, 3);
	if (op_type == e_op_type::Mix)
		op_type = (e_op_type)random_number(1, 4);
	question.questions_level = questions_level;
	question.op_type = op_type;
	switch (question.questions_level)
	{
		case e_questions_level::Easy:
			question.number1 = random_number(0, 9);
			question.number2 = random_number(0, 9);
			question.correct_answer = simple_calculator(question.number1, question.number2, question.op_type);
			return (question);
		case e_questions_level::Medium:
			question.number1 = random_number(10, 99);
			question.number2 = random_number(0, 9);
			question.correct_answer = simple_calculator(question.number1, question.number2, question.op_type);
			return (question);
		case e_questions_level::Hard:
			question.number1 = random_number(10, 99);
			question.number2 = random_number(10, 99);
			question.correct_answer = simple_calculator(question.number1, question.number2, question.op_type);
			return (question);
	}
	return (question);
}

void	generate_quizz_questions(s_quizz &quizz)
{
	for (short question = 0; question < quizz.number_of_qustions; question++)
	{
		quizz.question[question] = generate_question(quizz.questions_level, quizz.op_type);
	}
}

string	get_op_type_text(e_op_type op_type)
{
	switch(op_type)
	{
		case e_op_type::Add:
			return  ("+");
		case e_op_type::Sub:
			return  ("-");
		case e_op_type::Mul:
			return  ("*");
		case e_op_type::Div:
			return  ("/");
	}
	return ("Mix");
}

void	print_question(s_question question)
{
	cout << question.number1 << "\n" << question.number2;
	cout << " " << get_op_type_text(question.op_type);
	cout << "\n_______" << endl;
}

short	read_player_answer(void)
{
	short	answer = 0;

	cin >> answer;
	return (answer);
}

void	set_scrren_color(bool is_correct)
{
	if (is_correct)
		system ("color 2F");
	else
		system ("color 4F");
}

void	correct_answer(s_quizz &quizz, short question_number)
{
	if (quizz.question[question_number].player_answer == quizz.question[question_number].correct_answer)
	{
		cout << "Thy answer is correct :-)" << endl;
		quizz.question[question_number].answer_result = true;
		quizz.number_of_correct_answers++;
	}
	else
	{
		cout << "thy answer is uncorrect :-(\n";
		cout << "The correct answer is: " << quizz.question[question_number].correct_answer << endl;
		quizz.question[question_number].answer_result = false;
		quizz.number_of_uncorrect_answers++;
	}
	cout << endl;
	set_scrren_color(quizz.question[question_number].answer_result);
}

void	ask_and_correct_answers(s_quizz &quizz)
{
	for (short question_number = 0; question_number < quizz.number_of_qustions; question_number++)
	{
		print_question(quizz.question[question_number]);
		quizz.question[question_number].player_answer = read_player_answer();
		correct_answer(quizz, question_number);
	}
	quizz.is_pass = quizz.number_of_correct_answers >= quizz.number_of_uncorrect_answers;
}

string	get_level_text(e_questions_level questions_level)
{
	string	levels[4] = {"Easy", "Medium", "Hard", "Mixed"};

	return (levels[questions_level - 1]);
}

string	get_final_result_text(bool is_pass)
{
	if (is_pass)
		return ("THOU PASSED");
	return ("THOU FAILED");
}

void	print_quizz_result(s_quizz quizz)
{
	cout << "\n________________________\n";
	cout << "Number of questions was: " << quizz.number_of_qustions;
	cout << "\nQuestions level was: " << get_level_text(quizz.questions_level);
	cout << "\nOperator type was: " << get_op_type_text(quizz.op_type);
	cout << "\nThe number of correct answers is: " << quizz.number_of_correct_answers;
	cout << "\nThe number of uncorrect answers is: " << quizz.number_of_uncorrect_answers;
	cout << "\n________________________\n";
	cout << "Final result: " << get_final_result_text(quizz.is_pass);
	cout << "\n________________________\n";
}

void	play_math_game(void)
{
	s_quizz	quizz;

	quizz.number_of_qustions = read_how_many_questions();
	quizz.questions_level = read_questions_level();
	quizz.op_type = read_op_type();
	generate_quizz_questions(quizz);
	ask_and_correct_answers(quizz);
	print_quizz_result(quizz);
}

void	start_game(void)
{
	string			play_again = "Y";

	do
	{
		reset_screen();
		play_math_game();
		cout << "\nDost thou desire to play again [Y/N]?\n-> ";
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
