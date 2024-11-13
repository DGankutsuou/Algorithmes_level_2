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

float	my_abs(int n)
{
	return (n * ((n < 0) * -1 + (n > 0)));
}

int	main()
{
	float	number;

	number = read_number();
	cout << "My ABS function: " << my_abs(number) << endl;
	cout << "C++ ABS function: " << abs(number) << endl;
}
