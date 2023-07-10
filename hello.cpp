#include <iostream>

using namespace std;

int main()
{
    cout << "hello"
         << ", "
         << "world\n";
    cout << "second line" << endl;

    const double pi = 3.14;
    int number = (int)pi;

    cout << "converted double " << pi << " to int: " << number << endl;

    string hello = "hello world";
    char test = '@';
    hello[2] = test;

    cout << hello << endl;

    int score = 12;
    int &score_address = score;

    score = 24;
    cout << "the score is now " << score_address << endl;
    cout << "memory address of the score is: " << &score << endl;

    string day = "Monday";
    string *day_ptr = &day;
    cout << "the day is " << day << endl;
    day = "Sunday";
    cout << "the day is now " << day_ptr << endl;
    cout << "the day is now " << *day_ptr << endl;

    return 0;
}