#include <iostream>
using namespace std;

short read_number_in_range(short from, short to)
{
    short number;
    do{
        cout << "Enter a number from " << from << " to " << to << ": ";
        cin >> number;
    }while(number < from || number > to);
    return number;
}

void print_inverted_pattern(short number)
{
    cout << "\n";
    short counter = 0;
    while(number > 0)
    {
        counter = number;
        while(counter > 0)
        {
            cout << number;
            counter--;
        }
        cout << "\n";
        number--;
    }
}

int main()
{
    short number;
    number = read_number_in_range(0, 9);
    print_inverted_pattern(number);

    return 0;
}
