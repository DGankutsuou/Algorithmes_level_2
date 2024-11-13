#include <iostream>
#include <cstdlib>
using namespace std;

int random_number(int from, int to)
{
    int random_number;
    random_number = rand() % (to - from + 1) + from; 

    return random_number;
}

int main()
{
    srand((unsigned)time(NULL));

    cout << random_number(1, 10) << endl;
    cout << random_number(1, 10) << endl;
    cout << random_number(1, 10) << endl;

    return 0;
}