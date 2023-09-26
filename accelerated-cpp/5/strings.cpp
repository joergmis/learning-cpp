#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string &s);
std::vector<std::string> frame(const std::vector<std::string> &v);
std::vector<std::string> hcat_col(const std::vector<std::string> &left,
                                  const std::vector<std::string> &right);
std::vector<std::string> hcat_line(const std::vector<std::string> &left,
                                   const std::vector<std::string> &right);

int main() {
  std::vector<std::string> left = {"hello", "world"};
  std::vector<std::string> right = {"hello world", "hello", "world"};

  left = frame(left);
  right = frame(right);

  std::vector<std::string> res = hcat_line(left, right);

  for (std::vector<std::string>::const_iterator it = res.begin();
       it != res.end(); ++it) {
    std::cout << *it << std::endl;
  }

  res = hcat_col(left, right);

  for (std::vector<std::string>::const_iterator it = res.begin();
       it != res.end(); ++it) {
    std::cout << *it << std::endl;
  }

  return 0;
}

std::vector<std::string> split(const std::string &s) {
  std::vector<std::string> ret;
  typedef std::vector<std::string>::size_type string_size;

  string_size i = 0;
  while (i != s.size()) {
    while (i != s.size() && std::isspace(s[i])) {
      ++i;
    }

    string_size j = i;
    while (i != s.size() && std::isspace(s[i])) {
      j++;
      if (i != j) {
        ret.push_back(s.substr(i, j - i));
        i = j;
      }
    }
  }

  return ret;
}

std::string::size_type width(const std::vector<std::string> &v) {
  std::string::size_type maxlen = 0;
  for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i) {
    maxlen = std::max(maxlen, v[i].size());
  }

  return maxlen;
}

std::vector<std::string> frame(const std::vector<std::string> &v) {
  std::vector<std::string> ret;
  std::string::size_type maxlen = width(v);
  std::string border(maxlen + 4, '*');

  ret.push_back(border);

  for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i) {
    ret.push_back("* " + v[i] + std::string(maxlen - v[i].size(), ' ') + " *");
  }

  ret.push_back(border);
  return ret;
}

std::vector<std::string> vcat(const std::vector<std::string> &top,
                              const std::vector<std::string> &bottom) {
  std::vector<std::string> ret = top;

  // manually appending it
  /* for (std::vector<std::string>::const_iterator it = bottom.begin(); */
  /*      it != bottom.end(); ++it) { */
  /*   ret.push_back(*it); */
  /* } */

  // the library method
  ret.insert(ret.end(), bottom.begin(), bottom.end());

  return ret;
}

// checking line by line across the different images
std::vector<std::string> hcat_line(const std::vector<std::string> &left,
                                   const std::vector<std::string> &right) {

  std::vector<std::string> ret;
  std::vector<std::string>::size_type padding = width(left) + 1;

  std::vector<std::string>::size_type i = 0;

  for (std::vector<std::string>::size_type i = 0;
       i < std::max(left.size(), right.size()); ++i) {
    std::string line;

    if (i < left.size()) {
      line = left[i] + std::string(padding - left[i].size(), ' ');
    } else {
      line = std::string(padding, ' ');
    }

    if (i < right.size()) {
      line += right[i];
    }

    ret.push_back(line);
  }

  return ret;
}

// treating each image as a "column" - not running line by line
// more like one image at a time
std::vector<std::string> hcat_col(const std::vector<std::string> &left,
                                  const std::vector<std::string> &right) {
  // assumption: all images are "filled" meaning that all lines of the image
  // have the same size
  std::vector<std::string> ret = left;
  if (left.size() < right.size()) {
    std::vector<std::string>::size_type missing = right.size() - left.size();

    for (std::vector<std::string>::size_type i = 0; i < missing; ++i) {
      ret.push_back(std::string(width(left), ' '));
    }
  }
  for (std::vector<std::string>::size_type i = 0; i < right.size(); ++i) {
    ret[i] += " " + right[i];
  }

  return ret;
}
