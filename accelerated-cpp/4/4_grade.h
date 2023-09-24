#ifndef GUARD_grade_h
#define GUARD_grade_h

// check if this keyword is defined - that's a mark to make sure that this is
// only included once and not multiple times.
// on a sidenote - it's a good practice to make this on the first line. For
// some c++ it would make it easier / faster according to the book (to omit
// the content the second time)?

#include "4_Student_info.h"
#include <string>
#include <vector>

double grade(double, double, double);
double grade(double, double, const std::vector<double> &);
double grade(const Student_info &);

#endif
