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

float	my_sqrt(float number)
{
	return (pow (number, 0.5));
}

int main()
{
	float	number;

	number = read_number();
	cout << "My sqrt function: " << my_sqrt(number) << endl;
	cout << "C++ sqrt function: " << sqrt(number) << endl;
	return (0);
}
