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
    for(short i = 65; i <= 65 + number - 1; i++)
    {
        for(short j = 1; j <= i - 65 + 1; j++)
        {
            cout << char(i);
        }
        cout << "\n";
    }
}

int main()
{
    short number;
    number = read_number_in_range(1, 26);
    print_number_pattern(number);
    
    return 0;
}