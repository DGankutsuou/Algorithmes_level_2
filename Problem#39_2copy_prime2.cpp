#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

enum En_prime_or_not {Prime = 1, Not_prime};

En_prime_or_not is_prime(int number)
{
    int half = round(number / 2);
    for(int counter = 2; counter <= half; counter++)
    {
        if(number % counter == 0)
            return En_prime_or_not::Not_prime;
    }
    return En_prime_or_not::Prime;
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

void fill_array_with_random_numbers(int array[100], int& array_length)
{
    array_length = read_number_in_range(1, 100, "Enter the number of array elements (1 to 100): ");
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

void add_array_element(int number, int array[100], int& array_length)
{
    array[array_length] = number;
    array_length++;
}

void copy_primes_to_array_using_add_array_element(int empty_array[100], int filled_array[100], int& array_e_length, int array_f_length)
{
    for( int counter_f = 0; counter_f < array_f_length; counter_f++ )
    {
        if(is_prime(filled_array[counter_f]) == En_prime_or_not::Prime)
        {
            add_array_element(filled_array[counter_f], empty_array, array_e_length);
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int array1[100], array2[100];
    int array1_length = 0;
    int array2_length = 0;

    fill_array_with_random_numbers(array1, array1_length);
    cout << "Original array: ";
    print_array(array1, array1_length);
    copy_primes_to_array_using_add_array_element(array2, array1, array2_length, array1_length);
    cout << "Copied primes in array: ";
    print_array(array2, array2_length);

    return 0;
}