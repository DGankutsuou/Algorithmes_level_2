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

bool is_palindrome(int number)
{
    return number == converting_number_to_reverse(number);
}

void print_result(bool is_palindrome)
{
    if(is_palindrome)
        cout << "This number is palindrome" << endl;
    else
        cout << "This number is not palindrome" << endl;
}

int main()
{
    int number;
    number = read_positive_number("Enter a positive number: ");
    print_result(is_palindrome(number));

    return 0;
}