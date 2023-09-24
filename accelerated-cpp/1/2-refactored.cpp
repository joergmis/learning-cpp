#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  cout << "enter your name: ";
  string name;
  cin >> name;

  const string greeting = "hello " + name + "!";

  const int pad = 1;
  const int rows = pad * 2 + 3;

  cout << endl;

  const string::size_type cols = greeting.size() + pad * 2 + 2;

  for (int r = 0; r != rows; ++r) {
    for (int c = 0; c != cols; ++c) {
      // write a character
      if (r == 0 || r == rows - 1) {
        // write the border row
        cout << "*";
      } else if (c == 0 || c == cols - 1) {
        // write the border col
        cout << "*";
      } else if (r == pad + 1 && c == pad + 1) {
        cout << greeting;
        c += greeting.size();
        // need to remove one since the loop will increment anyway
        --c;
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
