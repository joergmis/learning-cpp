#include <algorithm>
#include <iostream>
#include <span>
#include <sys/types.h>
#include <vector>

typedef std::vector<uint>::size_type vec_sz;

int exercise2();
uint median(std::vector<uint> data);

int main() { return exercise2(); }

int exercise2() {
  std::vector<uint> values;

  std::cout << "enter the unsigned integers, followed by a EOL: ";
  uint val;
  while (std::cin >> val) {
    values.push_back(val);
  }

  vec_sz size = values.size();

  if (size <= 3) {
    std::cout << "not enough values, please try again" << std::endl;
    return 1;
  }

  sort(values.begin(), values.end());

  const uint med = median(values);

  const std::vector<uint> lower(values.begin(),
                                size % 2 == 0 ? values.begin() + size / 2
                                              : values.begin() + size / 2 + 1);
  const uint lower_quartile = median(lower);

  const std::vector<uint> upper(size % 2 == 0 ? values.begin() + size / 2
                                              : values.begin() + size / 2 + 1,
                                values.end());
  const uint upper_quartile = median(upper);

  std::cout << "lower quartile: " << lower_quartile << std::endl;
  std::cout << "median: " << med << std::endl;
  std::cout << "upper quartile: " << upper_quartile << std::endl;

  return 0;
}

/*
 * Calculate the median of the given vector. Expects the vector to already
 * be sorted.
 *
 * @param data vector which is already sorted.
 * @return median of the vector.
 */
uint median(std::vector<uint> data) {
  vec_sz size = data.size();

  if (size < 3) {
    std::cout << "not enough values, please try again" << std::endl;
    return 0;
  }

  const vec_sz middle = size / 2;
  const uint median =
      size % 2 == 0 ? (data[middle] + data[middle - 1]) / 2 : data[middle];

  return median;
}
