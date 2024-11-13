#include <iostream>
#include <string>
using namespace std;

string read_text()
{
    string text = "";
    cout << "Enter your text: ";
    getline(cin, text);

    return text;
}

string encrypt(string text, short encryption_key)
{
    int length = text.size();
    for(int i = 0; i < length; i++)
    {
        text[i] = char((int) text[i] + encryption_key);
    }
    return text;
}

string decrypt(string text, short encryption_key)
{
    int length = text.size();
    for(int i = 0; i < length; i++)
    {
        text[i] = char((int) text[i] - encryption_key);
    }
    return text;
}

int main()
{
    short encryption_key = 2;
    string text = "";
    text = read_text();
    cout << "\ntext before encryption: " << text << endl;
    string encrypted = encrypt(text, 2);
    string decrypted = decrypt(encrypted, 2);
    cout << "text encrypted: " << encrypted << endl;
    cout << "text decrypted: " << decrypted << endl;
    
    return 0;
}