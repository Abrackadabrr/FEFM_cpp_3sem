#include <set>
#include <iostream>

// std::set -- это упорядоченное множество
// которое представляется внутри с помощью 
// поискового дереваю (AVL, Красно-Черное и тд)

// Два ключевых метода -- upper_bound, lower_bound
// Позволяют найти даиназон внутри set

int main() {
  std::set<int> s = {67, 42, 141, 23, 42, 106, 15, 50};
  auto itb = s.lower_bound(30);
  auto ite = s.upper_bound(100);
  for (auto it = itb; it != ite; ++it)
    std::cout << *it << std::endl;
}
