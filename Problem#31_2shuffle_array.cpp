#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

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

void fill_array_with_ordered_numbers(int array[100], int& array_length)
{
    array_length = read_number_in_range(1, 100, "Enter a number from 1 to 100: ");
    for(int counter = 0; counter < array_length; counter++)
    {
        array[counter] = counter + 1;
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

void shuffle_array(int array[100], int array_length)
{
    for(int counter = 0; counter < array_length; counter++)
    {
        swap(array[random_number(1, array_length) - 1], array[random_number(1, array_length) - 1]);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int array[100];
    int array_length = 0;

    fill_array_with_ordered_numbers(array, array_length);
    cout << "Original array: ";
    print_array(array, array_length);
    shuffle_array(array, array_length);
    cout << "Array after shuffling: ";
    print_array(array, array_length);

    return 0;
}