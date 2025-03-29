#include <initializer_list>
#include <sstream>
#include <cmath>
#include <stdexcept>

template <typename T>
class f_list {

    struct Node {
        T data;
        Node* next;
    };

    Node* begin_;
    Node* end_;
    unsigned int top_;
    unsigned int capacity_;


// Давайте напишем класс, который будет вести себя "как будто указатель"
    class Iterator {
        Node* ptr_;

    public:
        Iterator(Node* ptr): ptr_(ptr) {}

        // pre-increment
        Iterator operator++() {
            if (!ptr_)
                throw std::runtime_error("End of list is reached");
            ptr_ = ptr_->next;
            return *this;
        }

        T& operator*() {
            if (!ptr_)
                throw std::runtime_error("Trying to get the end of list");
            return ptr_->data; 
        }

        const T& operator*() const {
            if (!ptr_)
                throw std::runtime_error("Trying to get the end of list");
            return ptr_->data; 
        }

        bool operator!=(const Iterator& other) {
            return ptr_ != other.ptr_;
        }

        bool operator==(const Iterator& other) {
            return ptr_ == other.ptr_;
        }
    };

    void swap(f_list& other);

   public:
    f_list() : begin_(nullptr), end_(nullptr), top_(0), capacity_(0) {}//default ctor

    f_list(const f_list& other);

    f_list(f_list&& other);

    f_list& operator=(const f_list& other);

    f_list& operator=(f_list&& other) noexcept;

    ~f_list() {clear();}

    void push_back(const T& data);
    T pop_back();
    void push_forward(const T& data);
    T pop_forward();

    void clear();
    unsigned int size() const { return top_;}
    unsigned int capacity() const { return capacity_;}
    void print(std::ostream& os) const;

    Iterator begin() const { return Iterator{begin_}; }
    Iterator end() const { return Iterator{end_}; }
};


// --- Implementation of methods --- //

template<typename T>
f_list<T>::f_list(const f_list& other) : f_list() {
        Node* copy = other.begin_;

        while (copy != other.end_) {
            push_back(copy->data);
            copy = copy->next;
        }
}//copy ctor

template<typename T>
f_list<T>::f_list(f_list&& other) : f_list() {
        swap(other);
}//move ctor

template<typename T>
f_list<T>& f_list<T>::operator=(const f_list<T>& other) {
        if (this == &other) {
            return *this;
        }
        clear();
        Node* copy = other.begin_;

        while (copy != other.end_) {
            push_back(copy->data);
            copy = copy->next;
        }
        return *this;
}//assign operator

template<typename T>
f_list<T>& f_list<T>::operator=(f_list<T>&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        clear();
        swap(other);
        return *this;
}//move assign operator

template<typename T>
void f_list<T>::swap(f_list<T>& other) {
        std::swap(begin_, other.begin_);
        std::swap(end_, other.end_);
        std::swap(top_, other.top_);
        std::swap(capacity_, other.capacity_);
}

template<typename T>
void f_list<T>::push_back(const T& data) {//в отличие от push forward, не делаем new при каждом push_back, 
        top_++;                    //если конечно после end есть ещё аллоцированные nodes
        if (end_ != nullptr) {
            if (end_->next != nullptr) {
                end_->data = data;
                end_ = end_->next;
                return;
            }
            capacity_++;
            end_->next = new Node{T{}, nullptr};
            end_->data = data;
            end_ = end_->next;
            return;
        }
        capacity_ += 2;

        Node* new_node = new Node{data, nullptr};
        Node* new_end = new Node{T{}, nullptr};
        new_node->next = new_end;
        begin_ = new_node;
        end_ = new_end;
}

template<typename T>
T f_list<T>::pop_back() {// в отличие от pop_forward просто сдвигаем конец на 1 влево
        //делаем значение удалённой node дефолтным
        //так мы не делаем delete при каждом popback
        if (top_ == 0) {
            return T{};
        }
        top_--;
        Node* copy = begin_;
        if (copy->next == end_) {
            T x = copy->data;
            copy->data = T{};
            end_ = copy;
            return x;
        }
        while (copy->next->next != end_) {
            copy = copy->next;
        }
        T x = copy->next->data;
        copy->next->data = T{}; //делаем значение удалённой node дефолтным
        end_ = copy->next;
        copy->next = end_;//просто сдвигаем конец листа на 1 влево
        return x;
    }

template<typename T>
void f_list<T>::clear() {
        if (top_ == 0) {
            return;
        }
        end_ = begin_;
        top_ = 0;
    }

template<typename T>
void f_list<T>::push_forward(const T& data) {
        if (top_ == 0) {
            push_back(data);
            return;
        }
        top_++;
        capacity_++;
        Node* new_node = new Node{data, begin_};//создали node с заданным значением(её добавляем)
        begin_ = new_node;//добавили node, которую сделали начальной
    }

template<typename T>
T f_list<T>::pop_forward() {
        if (top_ == 0) {
            return T{};
        }
        top_--;
        capacity_--;
        T x = begin_->data;//берём значение удаляемого элемента
        Node* copy = begin_;
        begin_ = begin_->next;//делаем следующий после удаляемого элемента начальным
        delete copy;//удаляем node
        return x;//возвращаем значение удалённого элемента
    }

template<typename T>
void f_list<T>::print(std::ostream& os) const {
        auto* sub_head = begin_; 
        while (sub_head->next) {
            os << sub_head->data << ' ';
            sub_head = sub_head->next;
        }
}

template<typename T>
std::ostream& operator<<(std::ostream & os, const f_list<T>& l) {
    l.print(os);
    return os;
}
