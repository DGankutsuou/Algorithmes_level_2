#include <iostream>
#include <cstdlib>
using namespace std;

int random_number(int from, int to)
{
    int random_number;
    random_number = rand() % (to - from + 1) + from; 

    return random_number;
}

short read_number_in_range(int from, int to, string message)
{
    short number;
    do{
        cout << message;
        cin >> number;
    }while(number < from || number > to);
    return number;
}

void fill_array_with_random_numbers(int array[100], int& array_length)
{
    array_length = read_number_in_range(1, 100, "Enter the number of array elements (1 - 100): ");
    for(int counter = 0; counter < array_length; counter++)
    {
        array[counter] = random_number(1, 100);
    }
}

void print_array(int array[100], int array_length)
{
    cout << "Original array: ";
    for(int counter = 0; counter < array_length; counter++)
    {
        cout << array[counter] << " ";
    }
    cout << endl;
}

short find_number_position_in_array(int array[100], int array_length, int number)
{
    for(short counter = 0; counter < array_length; counter++)
    {
        if(array[counter] == number)
        { 
            return counter;
        }
    }
    return -1;
}

bool check_number_in_array(int array[100], int array_length, int number)
{
    return find_number_position_in_array(array, array_length, number) != -1;
}

int main()
{
    srand((unsigned)time(NULL));
    int array[100];
    int array_length = 0;
    int number;
    bool number_existence;

    fill_array_with_random_numbers(array, array_length);
    print_array(array, array_length);
    number = read_number_in_range(1, 100, "Enter the number you look for (1 - 100): ");
    number_existence = check_number_in_array(array, array_length, number);

    cout << "The number you look for is: " << number << endl;
    if(!number_existence)
    {
        cout << "The number is not found :-(" << endl;
    }else{
        cout << "The number is found :-)" << endl; 
    }

    return 0;
}