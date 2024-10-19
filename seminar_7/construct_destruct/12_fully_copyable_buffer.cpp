#include <iostream>
#include <cassert>

class CCopyableBuffer {
public:
	CCopyableBuffer(int size) : m_size (size), m_buffer (new char[size]) {
		std::cout << "Ctor" << std::endl;
	}

	~CCopyableBuffer() {
		delete[] m_buffer;
		std::cout << "Dtor" << std::endl;
	}

	//  нетривиальный конструктор копирования
	CCopyableBuffer(const CCopyableBuffer& rhs) {
		m_size = rhs.m_size;
		m_buffer = new char[m_size];
		std::copy(m_buffer, m_buffer + m_size, rhs.m_buffer);
		
		std::cout << "Copy Ctor" << std::endl;
	}

	CCopyableBuffer& operator=(const CCopyableBuffer & rhs) {
		// добавили проверку на копирование в себя
		if (this == &rhs) return *this;
		m_size = rhs.m_size;
		// освободили свою память
		delete [] m_buffer;
		// начали копировать в себя из правой части, которая теперь точно не this
		m_buffer = new char[m_size];
		std::copy(m_buffer, m_buffer + m_size, rhs.m_buffer);
		
		std::cout << "Assign optor" << std::endl;
		
		return *this;
	}

	char &get(int x) {
		assert(x >= 0 && x < m_size);
		return m_buffer[x];
	}

private:
	char *m_buffer;
	int m_size;
};

void wrong() {
        CCopyableBuffer b1{10};
        CCopyableBuffer b2 = b1;
 } 
/*
	 Segfault here now???
*/

int main() {
	wrong();
	CCopyableBuffer a{10};
	CCopyableBuffer c(a);
	c = c;
	return 0;
}

