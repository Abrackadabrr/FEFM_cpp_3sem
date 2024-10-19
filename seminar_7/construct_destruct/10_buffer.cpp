#include <iostream>

class CBuffer {
	char *m_buffer;
 	int m_size = 10;
 public:
 	CBuffer(int size): m_size(size), m_buffer(new char[size]) {}

	 ~CBuffer() { delete[] m_buffer; }

	 char &get(int x) { 
		if(x >= 0 && x < m_size)
			std::cout << "Flaliure: x >= 0 && x < m_size" << std::endl; 
		return m_buffer[x]; 
	}
};

void wrong() {
	CBuffer b1{10};
	CBuffer b2 = b1;
} /* Segfault here */


int main() {
	wrong();
}
