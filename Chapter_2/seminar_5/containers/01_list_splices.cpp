#include <algorithm>
#include <forward_list>
#include <iostream>
#include <iterator>

int main() {
  std::ostream_iterator<int> icout{std::cout, " "};
  std::forward_list<int> first = {1, 2, 3};
  std::forward_list<int> second = {10, 20, 30};
  auto it = first.begin();

// Полностью вставить второй список куда-то в первый 
  first.splice_after(first.before_begin(), second);
  std::cout << "1." << std::endl;
  std::copy(first.begin(), first.end(), icout);
  std::cout << std::endl;

// 
  second.splice_after(second.before_begin(), first, first.begin(), it);
  std::cout << "2." << std::endl;
  std::copy(first.begin(), first.end(), icout);
  std::cout << std::endl;
  std::copy(second.begin(), second.end(), icout);
  std::cout << std::endl;

  first.splice_after(first.before_begin(), second, second.begin());
  std::cout << "3." << std::endl;
  std::copy(first.begin(), first.end(), icout);
  std::cout << std::endl;
  std::copy(second.begin(), second.end(), icout);
  std::cout << std::endl;
}