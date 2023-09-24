#include <algorithm>
#include <bits/types/cookie_io_functions_t.h>
#include <cstring>
#include <iostream>
#include <span>
#include <sstream>
#include <stdexcept>
#include <string>
#include <sys/types.h>
#include <vector>

typedef std::vector<uint>::size_type vec_sz;

void exercise2();
void exercise3();
void exercise4();
uint median(std::vector<uint> data);

int main() {
  exercise4();
  return 0;
}

void exercise2() {
  std::vector<uint> values;

  std::cout << "enter the unsigned integers, followed by a EOL: ";
  uint val;
  while (std::cin >> val) {
    values.push_back(val);
  }

  vec_sz size = values.size();

  if (size <= 3) {
    throw std::domain_error("not enough values");
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
    throw std::domain_error("not enough values, please try again");
  }

  const vec_sz middle = size / 2;
  const uint median =
      size % 2 == 0 ? (data[middle] + data[middle - 1]) / 2 : data[middle];

  return median;
}

void exercise3() {
  std::vector<std::string> data;
  std::vector<uint> occurences;
  std::cout << "enter words on one line (and then hit enter): ";

  std::string line;
  std::getline(std::cin, line);

  std::istringstream iss(line);
  std::string word;
  while (iss >> word) {
    std::vector<std::string>::size_type size = data.size();
    bool found = false;

    for (int i = 0; i != size; ++i) {
      if (word == data[i]) {
        found = true;
        ++occurences[i];
      }
    }

    if (!found) {
      data.push_back(word);
      occurences.push_back(1);
    }
  }

  std::cout << std::endl;
  std::cout << "word summary:" << std::endl;

  std::vector<std::string>::size_type size = data.size();
  for (int i = 0; i != size; ++i) {
    std::cout << data[i] << ": " << occurences[i] << " occurences" << std::endl;
  }
}

void exercise4() {
  std::string shortest = "";
  std::string longest = "";

  std::cout << "enter some words or a phrase on a line:" << std::endl;

  std::string line;
  std::getline(std::cin, line);
  std::istringstream iss(line);

  std::string word;
  int count = 0;
  while (iss >> word) {
    if (count == 0) {
      shortest = word;
      longest = word;
    }

    ++count;

    if (word.size() > longest.size()) {
      longest = word;
    }

    if (word.size() < shortest.size()) {
      shortest = word;
    }
  }

  if (count == 0) {
    throw std::domain_error("no words found");
  }

  std::cout << "shortest word: " << shortest << std::endl;
  std::cout << "longest word: " << longest << std::endl;
}
