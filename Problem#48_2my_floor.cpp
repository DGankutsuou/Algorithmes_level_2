#include <iostream>
#include <cmath>
using namespace std;

float	read_number()
{
	float	number;

	cout << "Enter a number: ";
	cin >> number;
	return (number);
}

float	my_floor(float number)
{
	int		int_number;

	int_number = int(number);
	if (number < 0 && int_number > number)
		return (--int_number);
	else if (number > 0)
		return (int_number);
	return (number);
}

int	main()
{
	float number;

	number = read_number();
	cout << "My floor funtion: " << my_floor(number) << endl;
	cout << "C++ floor funtion: " << floor(number) << endl;
}
