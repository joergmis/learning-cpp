#include <iostream>
#include <string>

int main() {
  std::cout << "enter your name: ";
  std::string name;
  std::cin >> name;

  const std::string greeting = "hello " + name + "!";

  const int pad = 1;
  const int rows = pad * 2 + 3;

  std::cout << std::endl;

  int r = 0;
  const std::string::size_type cols = greeting.size() + pad * 2 + 2;

  while (r != rows) {
    std::string::size_type c = 0;

    while (c != cols) {
      // write a character
      if (r == 0 || r == rows - 1) {
        // write the border row
        std::cout << "*";
        c++;
      } else if (c == 0 || c == cols - 1) {
        // write the border col
        std::cout << "*";
        c++;
      } else if (r == pad + 1 && c == pad + 1) {
        std::cout << greeting;
        c += greeting.size();
      } else {
        std::cout << " ";
        c++;
      }
    }
    std::cout << std::endl;

    ++r;
  }
  std::cout << std::endl;

  return 0;
}
