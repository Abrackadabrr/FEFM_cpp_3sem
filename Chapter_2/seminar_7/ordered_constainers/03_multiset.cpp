#include <set>
#include <iostream>

// Multiset -- это дерево, которое
// позволяет хранить одинаковые элементы и 
// сортироваться с их учетом

int main() {
  std::multiset<int> s = {67, 42, 141, 23, 42, 106, 15, 50};
  auto itb = s.lower_bound(30);
  auto ite = s.upper_bound(100);
  for (auto it = itb; it != ite; ++it)
    std::cout << *it << std::endl;
}
