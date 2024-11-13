#include <iostream>
#include <cstdlib>
using namespace std;

int random_number(int from, int to)
{
    int random_number;
    random_number = rand() % (to - from + 1) + from; 

    return random_number;
}

int read_number_in_range(int from, int to, string message)
{
    int number;
    do{
        cout << message;
        cin >> number;
    }while(number < from || number > to);
    return number;
}

void fill_array_with_random_numbers(int array[100], int& array_length)
{
    array_length = read_number_in_range(1, 100, "Enter a number from 1 to 100: ");
    for(int counter = 0; counter < array_length; counter++)
    {
        array[counter] = random_number(1, 100);
    }
}

void print_array(int array[100], int array_length)
{
    // cout << "Original array: ";
    for(int counter = 0; counter < array_length; counter++)
    {
        cout << array[counter] << " ";
    }
    cout << endl;
}
/*
void reverse_array(int array[100], int array_length)
{
    for(int counter = 0; counter < array_length; counter++)
    {
        swap(array[counter], array[array_length - 1 - counter]);
    }
}
*/
void copy_to_array(int empty_array[100], int filled_array[100], int array_length)
{
    for(int counter = 0; counter < array_length; counter++)
    {
        empty_array[counter] = filled_array[array_length - 1 - counter];
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int array1[100], array2[100];
    int array_length = 0;

    fill_array_with_random_numbers(array1, array_length);
    cout << "Original array: ";
    print_array(array1, array_length);
    copy_to_array(array2, array1, array_length);
    cout << "Copied array in reverse: ";
    print_array(array2, array_length);

    return 0;
}