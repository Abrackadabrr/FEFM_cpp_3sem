#include <iostream>
#include <unordered_map>

// Рассмотрим стандартные обходы unordered map

int main () {
  std::unordered_map<int, int> m;
  m.reserve(10);
  m.max_load_factor(10.0);
  for (int i = 0; i < 30; ++i)
    m.insert(std::make_pair(i, i));

// Подряд поэлементно
  for (auto it = m.begin(); it != m.end(); ++it)
    std::cout << it->first << " ";
  std::cout << std::endl;
// Подряд по бакетам
  for (int i = 0; i < m.bucket_count(); ++i) {
    std::cout << "Bucket #" << i << std::endl;
    for (auto it = m.begin(i); it != m.end(i); ++it)
      std::cout << it->first << " ";
    std::cout << std::endl;
  }
}
