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

void print_digits_in_reverse(int number)
{
    int remainder;
    while(number > 0){
        remainder = number % 10;
        number /= 10;
        cout << remainder << endl;
    }
}

/*
void print_digits(int number)
{
    short remainder;
    int digit[10];
    short counter = 0;
    while(number > 0){
        remainder = number % 10;
        number /= 10;
        digit[counter] = remainder;
        counter++;
    }
    while(counter > 0){
        counter--;
        cout << digit[counter] << endl;
    }
}
*/

int main()
{
    int number, reverse;
    number = read_positive_number("Enter a positive number: ");
    reverse = converting_number_to_reverse(number);
    print_digits_in_reverse(reverse);

    return 0;
}