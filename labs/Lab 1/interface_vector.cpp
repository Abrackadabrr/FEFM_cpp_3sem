struct subvector {
     int *mas;
     unsigned int top; 
     unsigned int capacity;
};

bool init(subvector *qv); // инициализация пустого недовектора (top и capacity по нулям, а mas это NULL)
bool push_back(subvector *qv, int d); // добавление элемента в конец недовектора с выделением дополнительной памяти при необходимости
int pop_back(subvector *qv); // удаление элемента с конца недовектора, значение удаленного элемента вернуть (если недовектор пустой, вернуть ноль)
bool resize(subvector *qv, unsigned int new_capacity); // увеличить емкость недовектора (можно использовать и для уменьшения - тогда, в рамках данной реализации, если top меньше новой capacity, то копируем только то, что влезает, и уменьшаем top до capacity)
void shrink_to_fit(subvector *qv); // очистить неиспользуемую память, переехав на новое место с уменьшением capacity до top
void clear(subvector *qv); // очистить содержимое недовектора, занимаемое место при этом не меняется
void destructor(subvector *qv);	// очистить всю используемую память, инициализировать недовектор как пустой
