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

void digits_frequency(int number){
    short frequency = 0;
    for(short digit = 0; digit < 10; digit++){
        frequency = digit_frequency(number, digit);
        if(frequency > 0){
            cout << "Digit " << digit << " frequency is: " << frequency << " time(s)" << endl;
        }
    }
}

int main()
{
    int number;
    short digit;
    number = read_positive_number("Enter a positive number: ");
    cout << "\n";
    digits_frequency(number);

    return 0;
}