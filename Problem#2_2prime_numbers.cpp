#include <iostream>
#include <string>
#include <cmath>
using namespace std;

enum En_prime_or_not {Prime = 1, Not_prime};

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

En_prime_or_not is_prime(int number)
{
    int half = round(number / 2);
    for(int counter = 2; counter <= half; counter++)
    {
        if(number % counter == 0)
            return En_prime_or_not::Not_prime;
    }
    return En_prime_or_not::Prime;
}

void print_prime_numbers_from_1_to_n(int number)
{
    cout << "Prime numbers from 1 to " << number << " :" << endl;
    for(int counter = 1; counter <= number; counter++){
        if(is_prime(counter) == En_prime_or_not::Prime)
            cout << counter << ", ";
    }
}

int main()
{
    int number;
    number = read_positive_number("Enter a positive number: ");

    print_prime_numbers_from_1_to_n(number);

    return 0;
}