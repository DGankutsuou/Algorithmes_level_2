#include <iostream>
using namespace std;

int read_number(string message)
{
    int number = 0;
    cout << message;
    cin >> number;

    return number;
}

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

void read_array(int array[100], int& array_length)
{
    array_length = read_positive_number("Enter the number of the array length: ");
    for(int counter = 0; counter < array_length; counter++)
    {
        cout << "Element[" << counter + 1 << "] = ";
        cin >> array[counter];
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

int count_times(int array[100], int array_length, int number)
{
    int times = 0;
    for(int counter = 0; counter < array_length; counter++)
    {
        if(number == array[counter])
        {
            times++;
        }
    }

    return times;
}

int main()
{
    int array[100];
    int array_length = 0;
    int number_to_check = 0;
    int times = 0;
    array[array_length];

    read_array(array, array_length);
    number_to_check = read_number("Enter the number you want to check: ");
    times = count_times(array, array_length, number_to_check);
    print_array(array, array_length);
    cout << "The number_to_check " << number_to_check << " repeated " << times << " time(s)" << endl;

    return 0;
}
