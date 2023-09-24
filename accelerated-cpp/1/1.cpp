#include <iostream>
#include <iterator>
#include <string>

int main() {
  std::cout << "please enter your first name: ";

  std::string name;
  std::cin >> name;

  const std::string greeting = "hello " + name + "!";

  // - define a const named spaces
  // - construct it (constructor takes int + char)
  const std::string spaces(greeting.size(), ' ');
  const std::string second = "* " + spaces + " *";

  const std::string first(second.size(), '*');

  std::cout << std::endl;
  std::cout << first << std::endl;
  std::cout << second << std::endl;
  std::cout << "* " << greeting << " *" << std::endl;
  std::cout << second << std::endl;
  std::cout << first << std::endl;
  std::cout << std::endl;

  return 0;
}
