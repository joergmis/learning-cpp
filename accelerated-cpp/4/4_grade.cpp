#include "4_Student_info.h"
#include "4_median.h"
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
