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

short digit_frequency(int number, short digit)
{
    short remainder = 0;
    short frequency = 0;
    while(number > 0){
        remainder = number % 10;
        number /= 10;
        if(remainder == digit)
        frequency++;
    }
    return frequency;
}

int main()
{
    int number;
    short digit;
    number = read_positive_number("Enter a positive number: ");
    digit = read_positive_number("Enter the digit: ");
    cout << "The frequency of the digit is: " << digit_frequency(number, digit) << endl;

    return 0;
}