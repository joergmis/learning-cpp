#include "4_Student_info.h"

#include <algorithm>
#include <iostream>
#include <istream>
#include <vector>

bool compare(const Student_info &x, const Student_info &y) {
  return x.name < y.name;
}

std::istream &read_hw(std::istream &in, std::vector<double> &hw) {
  /*
  By making the referene to the vector NOT a reference we state the intent to
  modify the content.

  In CPP you can't return multiple values - to circumvent this, we can simply
  pass references into the function which we can modify and use in the calling
  function later on.

  Note that arguments that are passed by reference have to be so-called
  "Ivalues" which basically means that they can't be anonymous objects.
  */
  if (in) {
    // get rid of previous contents
    hw.clear();

    std::cout << "enter the homework of the student: ";

    double x;
    while (in >> x) {
      hw.push_back(x);
    }

    // clear the stream to make sure it'll work for the next student
    in.clear();
  }

  return in;
}

std::istream &read(std::istream &is, Student_info &s) {
  std::cout << "enter the name of the student, his midterm and final grade: ";
  is >> s.name >> s.midterm >> s.final;
  read_hw(is, s.homework);
  return is;
}
