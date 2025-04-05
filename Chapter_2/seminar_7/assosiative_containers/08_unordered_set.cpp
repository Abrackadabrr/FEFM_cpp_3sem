#include <iostream>
#include <unordered_set>

// Unordered set хранит в себе только 
// ключи и не хранит значение

// Это буквально "неупорядоченное множество" 
// из уникальных элементов

template<typename Cont>
void print(const Cont& set)
{
    for (const auto& elem : set)
        std::cout << elem << ' ';
    std::cout << '\n';
}
 
int main()
{
    // Создаем сет из интов
    std::unordered_set<int> mySet{2, 7, 1, 8, 2, 8};
    print(mySet);
 
    // Добавляем элемент
    mySet.insert(5);
    print(mySet);
 
    // Удаляем элемент по итератору
    auto iter = mySet.find(5); 
    if (iter != mySet.end())
        mySet.erase(iter);
    print(mySet);
 
    // Удаляем элемент по значению
    mySet.erase(7);
    print(mySet);

    std::cout << std::endl << "--- rehash ---" << std::endl;
    mySet.rehash(10);
    std::cout << mySet.load_factor()<<  " vs max " << mySet.max_load_factor() << std::endl;
    std::cout << mySet.size() << std::endl;
    std::cout << mySet.bucket_count() << std::endl;
    print(mySet);
}

// Unordered set удаляет лишние ключи автоматически
