#include <iostream>
#include <string>
#include <cmath>
using namespace std;

enum En_perfect_or_not {perfect = 1, Not_perfect};

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

En_perfect_or_not is_perfect(int number)
{
    int half = round(number / 2);
    int counter = 0;
    for(int i = 1; i <= half; i++)
    {
        if(number % i == 0){
            counter += i;
        }
    }
    if(counter == number)
        return En_perfect_or_not::perfect;
    else
        return En_perfect_or_not::Not_perfect;
}

void print_perfect_numbers(int number)
{
    cout << "The perfect numbers from 1 to " + to_string(number) + ":" << endl;
    for(int counter = 1; counter <= number; counter++){
        if(is_perfect(counter) == En_perfect_or_not::perfect)
            cout << counter << ", ";
    }
}

int main()
{
    int number;
    number = read_positive_number("Enter a positive number: ");

    print_perfect_numbers(number);

    return 0;
}