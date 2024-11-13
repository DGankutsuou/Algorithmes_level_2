#include <iostream>
#include <string>
using namespace std;

string read_three_letter_password()
{
    char letters[3];
    string password = "";
    do{
        cout << "Enter three capital letters:" << endl;
        cin >> letters[0];
        cin >> letters[1];
        cin >> letters[2];
    }while((letters[0] < 'A' || letters[0] > 'Z') || (letters[1] < 'A' || 
    letters[1] > 'Z') || (letters[2] < 'A' || letters[2] > 'Z'));
    password += letters[0];
    password += letters[1];
    password += letters[2];
    return password;
}

bool guess_three_letters_password(string password)
{
    string word = "";
    int counter = 0;
    for(short first_letter = 65; first_letter <= 90; first_letter++)
    {
        for(short second_letter = 65; second_letter <= 90; second_letter++)
        {
            for(short third_letter = 65; third_letter <= 90; third_letter++)
            {
                counter++;
                word += char(first_letter);
                word += char(second_letter);
                word += char(third_letter);
                if(word == password)
                {
                    cout << "The password is: " << word << endl;
                    cout << "Found after " << counter << " trial(s)" << endl;
                    return true;
                }
                word = "";
            }
        }
    }
    return false;
}

int main()
{
    const string PASSWORD = "BAN";
    string password = "";
    guess_three_letters_password(PASSWORD);
    cout << "\n";
    password = read_three_letter_password();
    cout << password;
    guess_three_letters_password(password);

    return 0;
}