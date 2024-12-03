#include <iostream>
#include <cassert>
#include <unistd.h>

class CCopyableBuffer {
public:
	CCopyableBuffer(int size) : m_size (size), m_buffer (new int[size]) {
		std::cout << "Ctor" << std::endl;
	}

	~CCopyableBuffer() {
		delete[] m_buffer;
		std::cout << "Dtor" << std::endl;
	}

	//  нетривиальный конструктор копирования
	CCopyableBuffer(const CCopyableBuffer& rhs) {
		m_size = rhs.m_size;
		m_buffer = new int[m_size];
		std::copy(m_buffer, m_buffer + m_size, rhs.m_buffer);
		
		std::cout << "Copy Ctor" << std::endl;
	}

	CCopyableBuffer& operator=(const CCopyableBuffer & rhs) {
		m_size = rhs.m_size;
		std::cout << m_buffer << ' ' << rhs.m_buffer << std::endl;
		// освободили свою память
		delete [] m_buffer;
		sleep(1);
		m_buffer = new int[m_size];
		std::cout << m_buffer << std::endl;
		for (int i = 0; i < m_size; i++) { 
			m_buffer[i] = rhs.m_buffer[i];
		}
		std::cout << "Assign optor" << std::endl;
		
		return *this;
	}
private:
	int *m_buffer;
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
	CCopyableBuffer a{1000000000};
	a = a;
	return 0;
}

