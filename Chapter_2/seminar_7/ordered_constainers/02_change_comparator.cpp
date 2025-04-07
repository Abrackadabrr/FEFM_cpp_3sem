#include <set>
#include <iostream>

// На самом деле объявление 
// std::set выглядит вот так

/* template<
    class Key,
    class Compare = std::less<Key>,
> class set;
*/

// Это значит, что мы можем передать туда 
// произвольный компаратор

int main() {
  std::set<int, std::greater<int>> s = 
              {67, 42, 141, 23, 106, 15, 50};
  // 141 106 67 42 23 15
  auto itb = s.lower_bound(100);
  auto ite = s.upper_bound(30);
  for (auto it = itb; it != ite; ++it)
    std::cout << *it << std::endl;
}
