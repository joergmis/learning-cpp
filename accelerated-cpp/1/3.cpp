#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::cout << "enter first name: ";
  std::string name;
  std::cin >> name;
  std::cout << "hello " << name << "!" << std::endl;

  std::cout << "enter midterm and final grades: ";
  double midterm, final;
  std::cin >> midterm >> final;

  std::cout << "enter all homework grades, "
               "followed by end-of-file: ";

  int count = 0;
  double sum = 0;

  double x;
  std::vector<double> homework;

  while (std::cin >> x) {
    ++count;
    sum += x;
    homework.push_back(x);
  }

  // create a synonym since the size type is a bit unwieldly
  typedef std::vector<double>::size_type vec_sz;
  vec_sz size = homework.size();

  if (size == 0) {
    std::cout << std::endl
              << "no homework grades entered - "
                 "please try again"
              << std::endl;
    return 1;
  }

  sort(homework.begin(), homework.end());
  vec_sz mid = size / 2;
  double median;
  median =
      size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];

  std::streamsize prec = std::cout.precision();
  std::cout << "your final grade is " << std::setprecision(3)
            << 0.2 * midterm + 0.4 * final + 0.4 * median
            << std::setprecision(prec) << std::endl;

  return 0;
}
