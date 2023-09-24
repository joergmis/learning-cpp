#include <iostream>
#include <string>

void exercise6();

int main() {
  exercise6();
  return 0;
}

void exercise3() {
  {
    const std::string s = "a string";
    std::cout << s << std::endl;
  }

  {
    const std::string s = "a string";
    std::cout << s << std::endl;
  }
}

void exercise4() {
  const std::string s = "a string";
  std::cout << s << std::endl;

  {
    // a const can be redefined in different scopes
    const std::string s = "a string";
    std::cout << s << std::endl;
  }
}

void exercise5() {
  {
    std::string s = "a string";
    {
      std::string x = s + " really";
      std::cout << s << std::endl;
    }

    // wrong scope - has no notion of x
    // std::cout << x << std::endl;
  }
}

void exercise6() {
  // std::cin seems to split the input by spaces. If there are items left,
  // subsequent calls to std::cin will use them until there are no more items
  // left. Then, it will rely on stdin again (?)
  // you can test this by running this function with input "first second"
  std::string name;
  std::cout << "you name please: ";
  std::cin >> name;
  std::cout << "welcome " << name << std::endl;

  std::string name2;
  std::cout << "you name please: ";
  std::cin >> name2;
  std::cout << "welcome " << name2 << std::endl;

  std::string name3;
  std::cout << "you name please: ";
  std::cin >> name3;
  std::cout << "welcome " << name3 << std::endl;
}
