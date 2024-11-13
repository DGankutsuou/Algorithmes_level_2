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

int converting_number_to_reverse(int number)
{
    int remainder = 0;
    int reverse = 0;
    while(number > 0){
        remainder = number % 10;
        number /= 10;
        reverse *= 10;
        reverse += remainder;
    }
    return reverse;
}

int main()
{
    int number;
    number = read_positive_number("Enter a positive number: ");
    cout << "The reverse of the number is: " << converting_number_to_reverse(number) << endl;

    return 0;
}