#include <iostream>
#include <cstdlib>
using namespace std;

enum En_char_type {capital_letter = 1, small_case_letter, spicial_char, digit};

int read_number_in_range(int from, int to, string message)
{
    int number;
    do{
        cout << message;
        cin >> number;
    }while(number < from || number > to);
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

void fill_array_with_keys(string array[100], En_char_type char_type, short word_length, short key_length, int number_of_keys)
{
    int counter = 0;
    while(counter < number_of_keys)
    { 
        array[counter++] = generate_key(char_type, word_length, key_length);
    }
}

void print_array(string array[100], int array_length)
{
    // cout << "Original array: ";
    for(int counter = 0; counter < array_length; counter++)
    {
        cout << "Array[" << counter << "]: ";
        cout << array[counter] << "\n";
    }
}

int main()
{
    srand((unsigned)time(NULL));

    string array[100];
    int number_of_keys = 0;
    number_of_keys = read_number_in_range(1, 100, "Enter the number of the keys you want: ");

    fill_array_with_keys(array, En_char_type::capital_letter, 4, 4, number_of_keys);
    print_array(array, number_of_keys);

    return 0;
}