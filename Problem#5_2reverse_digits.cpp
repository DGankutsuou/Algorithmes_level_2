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

void print_digits_in_reverse(int number)
{
    int remainder;
    while(number > 0){
        remainder = number % 10;
        number /= 10;
        cout << remainder << endl;
    }
}

int main()
{
    int number;
    number = read_positive_number("Enter a positive number: ");
    print_digits_in_reverse(number);

    return 0;
}