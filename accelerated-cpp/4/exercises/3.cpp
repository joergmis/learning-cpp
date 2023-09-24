#include <iomanip>
#include <iostream>
#include <math.h>
#include <stdexcept>
#include <sys/types.h>
#include <vector>

int main() {
  const std::vector<uint>::size_type size = 1000;

  std::vector<uint> orig;
  std::vector<uint> square;

  for (std::vector<uint>::size_type i = 0; i < size; ++i) {
    orig.push_back(i);
    square.push_back(i * i);
  }

  // calculate the padding based on the biggest number
  int max_width_orig = ceil(log10(orig[orig.size() - 1]));
  int max_width_square = ceil(log10(square[square.size() - 1]));

  for (std::vector<uint>::size_type i = 0; i < orig.size(); ++i) {
    std::cout << std::setw(max_width_orig) << orig[i] << " "
              << std::setw(max_width_square) << square[i] << std::endl;
  }

  return 0;
}
