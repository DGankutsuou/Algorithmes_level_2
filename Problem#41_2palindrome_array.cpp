#include <iostream>
#include <cstdlib>
using namespace std;

void fill_array(int array[100], int& array_length)
{
    array_length = 9;
    array[0] = 10;
    array[1] = 90;
    array[2] = 70;
    array[3] = 20;
    array[4] = 80;
    array[5] = 20;
    array[6] = 70;
    array[7] = 90;
    array[8] = 10;
    // array[9] = 10;
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

bool	is_palindrome_array(int array[100], int array_length)
{
    for (int counter = 0; counter < array_length / 2; counter++)
    {
        if (array[counter] != array[array_length - 1 - counter])
            return (false);
        // cout << counter << " " << array_length - 1 - counter << endl;
    }
    return (true);
}

void    print_result(bool is_palindrome_array)
{
    if (is_palindrome_array)
        cout << "This is a palindrome array.";
    else
        cout << "This is not a palindrome array.";
}

int main()
{
    int array[100];
    int array_length = 0;

    fill_array(array, array_length);
    cout << "Original array: ";
    print_array(array, array_length);
    print_result(is_palindrome_array(array, array_length));
}
