struct subvector {
    int * mas;
    unsigned top;
    unsigned capacity;
};

bool init(subvector* qv) {
     qv->mas = nullptr;
     qv->top = 0;
     qv->capacity = 0;
     return true;
 }

void destructor(subvector* qv) {
      delete[] qv->mas;
      qv->mas = nullptr;
      qv->top = 0;
      qv->capacity = 0;
}

// или ещё

void destructor(subvector *qv) {
     delete[] qv->mas;
     init(qv);
}


// кому что не нравится в приведенных выше функциях?

int main() {
	int i = 0;
	int *i_p = new int[2];
	i_p[0] = 0;
	i_p[1] = 1;
// 1 case
	i++;
	std::cout << i_p[i-1] << std::endl;

	i = 0;
// 2 case
	std::cout << i_p[i++] << std::endl;	
// что на экране?
}

