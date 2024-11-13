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

void print_inverted_pattern(short number)
{
    cout << "\n";
    for(short i = 65 + number - 1; i >= 65; i--)
    {
        for(short j = 1; j <= number - (65 + number - 1 - i); j++)
        {
            cout << char(i);
        }
        cout << "\n";
    }
}
/*
void print_inverted_pattern(short number)
{
    cout << "\n";
    short counter = 0;
    char letter; 
    while(number > 0)
    {
        letter = number + 64;
        counter = number;
        while(counter > 0)
        {
            cout << letter;
            counter--;
        }
        cout << "\n";
        number--;
    }
}
*/
int main()
{
    short number;
    number = read_number_in_range(1, 26);
    print_inverted_pattern(number);
    
    return 0;
}