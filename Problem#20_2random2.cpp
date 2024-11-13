#include <iostream>
#include <cstdlib>
using namespace std;

enum En_char_type {capital_letter = 1, small_case_letter, spicial_char, digit};

void char_type_menu()
{
    cout << "\n*****CHAR TYPE MENU*****\n";
    cout << "1: Capital letter\n";
    cout << "2: Small case letter\n";
    cout << "3: Spicial char\n";
    cout << "4: digit\n" << endl; 
}

En_char_type read_char_type()
{
    short char_type;
    char_type_menu();
    do{
        cout << "Chose the type from the menu: ";
        cin >> char_type;
    }while(char_type < 1 || char_type > 4);
    cout << endl;

    return (En_char_type)char_type;
}

int random_number(int from, int to)
{
    int random_number;
    random_number = rand() % (to - from + 1) + from; 

    return random_number;
}

void random_char()
{
    En_char_type char_type;
    char_type = read_char_type();

    switch(char_type)
    {
        case En_char_type::capital_letter:
            cout << char(random_number('A', 'Z')) << endl;
            break;
        case En_char_type::small_case_letter:
            cout << char(random_number('a', 'z')) << endl;
            break;
        case En_char_type::spicial_char:
            cout << char(random_number('!', '@')) << endl;
            break;
        case En_char_type::digit:
            cout << char(random_number('0', '9')) << endl;
            break;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    random_char();
    random_char();
    random_char();
    random_char();

    return 0;
}