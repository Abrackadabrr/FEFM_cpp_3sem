struct subforwardlist {
     int data;
     subforwardlist* next;
};
void init(subforwardlist **start); // инициализация пустого стека
bool push_forward(subforwardlist **sfl, int d); 	//добавление элемента в начало
int pop_forward(subforwardlist **sfl); 	//удаление элемента из начала
