struct subforwardlist {
     int data;
     subforwardlist* next;
};


// Список функций к реализации, вместо "@" нужно всатвить столько звездочек, сколько необходимо вам для реализации
bool init(subforwardlist @sfl); 	//инициализация пустого недосписка 
bool push_back(subforwardlist @sfl, int d); 	//добавление элемента в конец недосписка				
int pop_back(subforwardlist @sfl); 	//удаление элемента с конца недосписка, если пустой - возвращать 0
bool push_forward(subforwardlist @sfl, int d); 	//добавление элемента в начало недосписка				
int pop_forward(subforwardlist @sfl); 	//удаление элемента из начала недосписка, если пустой - возвращать 0
bool push_where(subforwardlist @sfl, unsigned int where, int d); //добавление элемента с порядковым номером where		
int erase_where(subforwardlist @sfl, unsigned int where);	//удаление элемента с порядковым номером where, если пустой - возвращать 0

unsigned int size(subforwardlist  @sfl);	//определить размер недосписка

void clear(subforwardlist  @sfl);	//очистить содержимое недосписка
