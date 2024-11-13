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

void fill_array_with_random_numbers(int array[100], int array_length)
{
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

void copy_to_array(int empty_array[100], int filled_array[100], int array_length)
{
    for(int counter = 0; counter < array_length; counter++)
    {
        empty_array[counter] = filled_array[counter];
    }
}

void sum_two_arrays(int empty_array[100], int array1[100], int array2[100], int array_length)
{
    for(int counter = 0; counter < array_length; counter++)
    {
        empty_array[counter] = array1[counter] + array2[counter];
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int array1[100], array2[100], array3[100];
    int array_length;
    array_length = read_number_in_range(1, 100, "Enter a number from 1 to 100: ");

    fill_array_with_random_numbers(array1, array_length);
    fill_array_with_random_numbers(array2, array_length);
    sum_two_arrays(array3, array2, array1, array_length);

    cout << "First array: ";
    print_array(array1, array_length);
    cout << "Second array: ";
    print_array(array2, array_length);
    cout << "The sum array: ";
    print_array(array3, array_length);

    return 0;
}