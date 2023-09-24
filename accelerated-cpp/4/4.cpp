#include "4_Student_info.h"
#include "4_grade.h"

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

int main() {
  std::vector<Student_info> students;
  Student_info record;
  std::string::size_type maxlen = 0;

  while (read(std::cin, record)) {
    maxlen = std::max(maxlen, record.name.size());
    students.push_back(record);
  }

  std::cout << std::endl;

  std::sort(students.begin(), students.end(), compare);

  for (std::vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
    std::cout << students[i].name
              << std::string(maxlen + 1 - students[i].name.size(), ' ');

    try {
      double final_grade = grade(students[i]);
      std::streamsize prec = std::cout.precision();
      std::cout << std::setprecision(3) << final_grade
                << std::setprecision(prec);
    } catch (std::domain_error e) {
      std::cout << e.what();
    }

    std::cout << std::endl;
  }

  return 0;
}
