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
    array_length = read_number_in_range(1, 100, "Enter the number of array elements (1 to 100): ");
    for(int counter = 0; counter < array_length; counter++)
    {
        array[counter] = random_number(-100, 100);
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

int	count_negatives_in_array(int array[100], int array_length)
{
	int negatives_counter = 0;
	for (int counter = 0; counter < array_length; counter++)
	{
		if (array[counter] < 0)
			negatives_counter++;
	}
	return (negatives_counter);
}

int main()
{
	srand((unsigned)time(NULL));
	int array[100];
	int array_length = 0;

	fill_array_with_random_numbers(array, array_length);
	cout << "Original array: ";
	print_array(array, array_length);
	cout << "There is/are " << count_negatives_in_array(array, array_length);
	cout << " negative numbers in this array." << endl;
	return 0;
}
