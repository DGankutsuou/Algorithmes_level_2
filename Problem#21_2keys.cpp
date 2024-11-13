#include <iostream>
#include <cstdlib>
using namespace std;

enum En_char_type {capital_letter = 1, small_case_letter, spicial_char, digit};

int read_positive_number(string message)
{
    int number = 0;
    do
    {
        cout << message;
        cin >> number;
    }while(number <= 0);

    return number;
}

int random_number(int from, int to)
{
    int random_number;
    random_number = rand() % (to - from + 1) + from; 

    return random_number;
}

char random_char(En_char_type char_type)
{
    switch(char_type)
    {
        case En_char_type::capital_letter:
            return char(random_number('A', 'Z'));

        case En_char_type::small_case_letter:
            return char(random_number('a', 'z'));

        case En_char_type::spicial_char:
            return char(random_number('!', '@'));

        case En_char_type::digit:
            return char(random_number('0', '9'));
    }
    return '0';
}

string generate_word(En_char_type char_type, short word_length)
{
    string word = "";
    for(short counter = 0; counter < word_length; counter++)
    {
        word += random_char(char_type);
    }
    return word;
}

string generate_key(En_char_type char_type, short word_length, short key_length)
{
    string key = "";
    for(short counter = 0; counter < key_length; counter++)
        {
            key += generate_word(char_type, word_length);
            if(counter < key_length - 1)
            {
                key += "-";
            }else{
                key += "\n";
            }
        }
        return key;
}

void generate_keys(En_char_type char_type, short word_length, short key_length, int number_of_keys)
{
    int counter = 1;
    while(counter <= number_of_keys)
    {
        cout << "Key[" << counter << "]: "; 
        cout << generate_key(char_type, word_length, key_length);
        counter++;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int number_of_keys = 0;
    number_of_keys = read_positive_number("Enter the number of the keys you want: ");

    generate_keys(En_char_type::capital_letter, 4, 4, number_of_keys);

    return 0;
}