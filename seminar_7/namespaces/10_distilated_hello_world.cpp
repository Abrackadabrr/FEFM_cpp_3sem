#include <iostream>

namespace hwapp {
	const char * const str = "Hello, World!";
}
// main должна быть в глобальном пространстве имен, иначе операционка не сможет оперделеиться
// где точка входа в вашу программу

int main() {
	std::cout << hwapp::str << std::endl;
}

// больших программах такая аккуратность просто вынуждена, поскольку её пишут миллион программистов, 
// и всем не хочется конфликтов по именам, после которых нужно ходить по офису и выяснять кто и что сделал
// в маленьких примерах, конечно, такое излишне