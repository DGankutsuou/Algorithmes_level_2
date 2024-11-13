#include <iostream>
using namespace std;

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

int sum_digits(int number)
{
    int remainder = 0;
    int sum = 0;
    while(number > 0){
        remainder = number % 10;
        number /= 10;
        sum += remainder;
    }
    return sum;
}

int main()
{
    int number;
    number = read_positive_number("Enter a positive number: ");
    cout << "The sum of the digits is: " << sum_digits(number) << endl;

    return 0;
}