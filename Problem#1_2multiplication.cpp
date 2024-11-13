#include <iostream>
using namespace std;

void print_table_header()
{
    cout << "\n\n\t\t\tMultiplication table from 1 to 10\t\t\t\n\n";
    for(int  counter = 1; counter <= 10; counter++){
        cout << "\t" << counter;
    }
    cout << "\n";
    for(int counter = 1; counter < 10; counter++){
        cout << "_________";
    }
    cout << "_" << endl;
}

string colum_sperator(int number){
    if(number < 10)
        return "  |";
    else
        return " |";
}

void print_multiplication_table(){
    print_table_header();
    for(int v_counter = 1; v_counter <= 10; v_counter++){
        cout << " " << v_counter << colum_sperator(v_counter) << "\t";
        for(int h_counter = 1; h_counter <= 10; h_counter++){
            cout << v_counter * h_counter << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    print_multiplication_table();

    return 0;
}