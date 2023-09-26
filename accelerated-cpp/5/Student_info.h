#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <string>
#include <vector>

struct Student_info {
  std::string name;
  double midterm, final;
  std::vector<double> homework;
};

// compares students based on their names
bool compare(const Student_info &x, const Student_info &y);

// read homework grades from an input stream into a vector
std::istream &read_hw(std::istream &in, std::vector<double> &hw);

// populate the student with the data from the stream
std::istream &read(std::istream &is, Student_info &s);

#endif
