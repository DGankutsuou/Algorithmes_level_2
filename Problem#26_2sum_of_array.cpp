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
    array_length = read_number_in_range(1, 100, "Enter a number from 1 to 100: ");
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

int calculat_sum_of_array(int array[100], int array_length)
{
    int sum;
    sum = 0;
    for(int counter = 0; counter < array_length; counter++)
    {
            sum += array[counter];
    }

    return sum;
}

int main()
{
    srand((unsigned)time(NULL));
    int array[100];
    int array_length = 0;

    fill_array_with_random_numbers(array, array_length);
    print_array(array, array_length);
    cout << "The sum of all numbers is: " << calculat_sum_of_array(array, array_length);

    return 0;
}
