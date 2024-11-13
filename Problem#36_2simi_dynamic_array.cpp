#include <iostream>
#include <cstdlib>
using namespace std;

int random_number(int from, int to)
{
    int random_number;
    random_number = rand() % (to - from + 1) + from; 

    return random_number;
}

short read_number(string message)
{
    short number;
    cout << message;
    cin >> number;

    return number;
}

void add_array_element(int number, int array[100], int& array_length)
{
    array[array_length] = number;
    array_length++;
}

void input_user_numbers_in_array(int array[100], int& array_length)
{
    bool add_more;
    int number;
    do
    {
        number = read_number("Enter a number from 1 to 100: ");
        add_array_element(number, array, array_length);
        cout << "Dost Thou desire to add another number (Yes = 1/ No = 0): ";
        cin >> add_more;
    } while (add_more);
}

void print_array(int array[100], int array_length)
{
    for(int counter = 0; counter < array_length; counter++)
    {
        cout << array[counter] << " ";
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));
    int array[100];
    int array_length = 0;

    input_user_numbers_in_array(array, array_length);
    cout << "\nArray length is: " << array_length << endl;
    cout << "Array elements: ";
    print_array(array, array_length);

    return 0;
}