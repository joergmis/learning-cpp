#include "Student_info.h"
#include "median.h"
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

double grade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const std::vector<double> &hw) {
  /*
  The third argument is called "reference to vector of const double". The const
  keyword makes the promise that we won't modify the content of it - basically
  it just turns it into a readonly parameter for the scope of this function.

  This is passing arguments by reference - which avoids copying.

  Note that this is also an overload for the grade function.

  const std::vector<double> hw
  ^ this would specify the intent that we want to modify the data as well.
  */
  if (hw.size() == 0) {
    throw std::domain_error("student has done no homework");
  }

  return grade(midterm, final, median(hw));
}

double grade(const Student_info &s) {
  return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info &s) { return grade(s) < 60; }

std::vector<Student_info> extract_fails(std::vector<Student_info> &students) {
  std::vector<Student_info> fail;

  std::vector<Student_info>::iterator iter = students.begin();
  while (iter != students.end()) {
    if (fgrade(*iter)) {
      // push_back invalidates all iterators as well (since the vector might
      // get relocated) - but again, only for vectors but not for lists
      fail.push_back(*iter);
      // erase returns a new iterator past this object - otherwise this would
      // not work as expected if we would use the same iterator again
      // IMPORTANT: erase will invalidate every iterator on this object!
      iter = students.erase(iter);
    } else {
      ++iter;
    }
  }

  return fail;
}

std::list<Student_info> extract_fails(std::list<Student_info> &students) {
  std::list<Student_info> fail;

  std::list<Student_info>::iterator iter = students.begin();
  while (iter != students.end()) {
    if (fgrade(*iter)) {
      // neither push_back nor erase invalidate iterators for lists!
      fail.push_back(*iter);
      iter = students.erase(iter);
    } else {
      ++iter;
    }
  }

  return fail;
}
