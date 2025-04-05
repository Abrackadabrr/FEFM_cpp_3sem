#include <unordered_map>
#include <string>
#include <iostream>

using ht = std::unordered_map<std::string, int>;


int main() {
    ht table{};

    table.max_load_factor(3);

    table.insert({"Alice", 10});
    table.insert({"Anora", 12});
    table.insert({"Wayne", 894});
    table.insert({"Wan", 895});
    table.insert({"Alex", 892});
    table.insert({"Alina", 892});
    table.insert({"Forest", 892});
    table.insert({"Any", 892});

    std::cout << table.load_factor() << std::endl;

    std::cout << table.size() << std::endl;
    std::cout << table.bucket_count() << std::endl;

    std::cout << "Buckets searching" << std::endl;
    for (int i = 0; i < table.bucket_count(); i++)
        std::cout << table.bucket_size(i) << std::endl;
}
