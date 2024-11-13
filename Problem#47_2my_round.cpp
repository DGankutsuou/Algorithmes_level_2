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

float	get_fraction_part(float number)
{
	return (number - int(number));
}

float	my_round(float number)
{
	int		int_number;
	float	fraction_part;

	int_number = int(number);
	fraction_part = get_fraction_part(number);
	if (number < 0)
	{
		if (fraction_part > -0.5)
			return (int_number);
		else
			return (--int_number);
	}
	else if (number > 0)
	{
		if (fraction_part < 0.5)
			return (int_number);
		else
			return (++int_number);
	}
	return (number);
}

int	main()
{
	float number;

	number = read_number();
	cout << "My round funtion: " << my_round(number) << endl;
	cout << "C++ round funtion: " << round(number) << endl;
}
