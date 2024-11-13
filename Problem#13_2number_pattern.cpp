#include <iostream>
using namespace std;

short read_number_in_range(int from, int to)
{
    short number;
    do{
        cout << "Enter a number from " << from << " to " << to << ": ";
        cin >> number;
    }while(number < from || number > to);
    return number;
}

void print_number_pattern(short number)
{
    cout << "\n";
    for(short counter1 = 1; counter1 <= number; counter1++)
    {
        for(short counter2 = 1; counter2 <= counter1; counter2++)
        {
            cout << counter1;
        }
        cout << "\n";
    }
}

int main()
{
    short number;
    number = read_number_in_range(0, 9);
    print_number_pattern(number);
    
    return 0;
}