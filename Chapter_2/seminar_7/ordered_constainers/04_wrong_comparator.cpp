#include <set>
#include <iostream>

// Multimap -- это дерево, которое
// позволяет хранить одинаковые элементы и 
// сортироваться с их учетом

int main() {
  std::multiset<int, std::less_equal<int>> s = {67, 42, 141, 23, 42, 106, 15, 50};
  auto itb = s.lower_bound(42);
  auto ite = s.upper_bound(42);
  for (auto it = itb; it != ite; ++it)
    std::cout << *it << std::endl;
}
