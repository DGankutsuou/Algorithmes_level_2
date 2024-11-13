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

void print_number_type(int number)
{
    if(is_perfect(number) == En_perfect_or_not::perfect)
        cout << "The number " + to_string(number) +  " is perfect." << endl;
    else
        cout << "The number " + to_string(number) +  " is not perfect." << endl;
}

int main()
{
    int number;
    number = read_positive_number("Enter a number > 0: ");

    print_number_type(number);

    return 0;
}