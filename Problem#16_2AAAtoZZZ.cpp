#include <iostream>
using namespace std;

void AAAtoZZZ()
{
    string word = "";
    for(short first_letter = 65; first_letter <= 90; first_letter++)
    {
        for(short second_letter = 65; second_letter <= 90; second_letter++)
        {
            for(short third_letter = 65; third_letter <= 90; third_letter++)
            {
                word += char(first_letter);
                word += char(second_letter);
                word += char(third_letter);
                cout << word;
                if(!(first_letter == 90 && second_letter == 90 && third_letter == 90))
                {
                    cout << ", ";
                    word = "";
                }
            }
        }
    }
}

int main()
{
    AAAtoZZZ();

    return 0;
}