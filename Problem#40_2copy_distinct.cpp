#include <iostream>
//#include <cstdlib>
using namespace std;

void fill_array(int array[100], int& array_length)
{
    array_length = 10;
    array[0] = 10;
    array[1] = 10;
    array[2] = 10;
    array[3] = 50;
    array[4] = 50;
    array[5] = 70;
    array[6] = 70;
    array[7] = 70;
    array[8] = 70;
    array[9] = 90;
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

void add_array_element(int number, int array[100], int& array_length)
{
    array[array_length] = number;
    array_length++;
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

bool check_number_in_array(int number, int array[100], int array_length)
{
    return find_number_position_in_array(array, array_length, number) != -1;
}

void copy_distincts_to_array_using_add_array_element(int empty_array[100], int filled_array[100], int& array_e_length, int array_f_length)
{
    for( int counter = 0; counter < array_f_length; counter++ )
    {
        if(!check_number_in_array(filled_array[counter], empty_array, array_e_length))
        {
            add_array_element(filled_array[counter], empty_array, array_e_length);
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int array1[100];
    int array2[100];
    int array1_length = 0;
    int array2_length = 0;
    fill_array(array1, array1_length);

    cout << "Original array: ";
    print_array(array1, array1_length);
    copy_distincts_to_array_using_add_array_element(array2, array1, array2_length, array1_length);
    cout << "Copied distincts in array: ";
    print_array(array2, array2_length);

    return 0;
}