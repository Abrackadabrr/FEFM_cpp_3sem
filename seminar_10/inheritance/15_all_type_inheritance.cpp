// Как изменяются модификторы доступа в наследнике при 
// разных типах наследования

// --------------------------------|--------|-----------|---------|
// модификатор в базовом классе    | public | protected | private |
// ------------------------------| |        |           |         |
// модификатор наследования       \|        |           |         |
// --------------------------------|--------|-----------|---------|
// public                            public   protected   private 
//
// protected                             protected        private
//
// private                                  always  private 


class PublicBase {
public:
  int open = 0;

protected:
  int semiclosed = 1;

private:
  int closed = 2;
};

class ProtectedBase {
public:
  int open = 3;

protected:
  int semiclosed = 4;

private:
  int closed = 5;
};

class PrivateBase {
public:
  int open = 6;

protected:
  int semiclosed = 7;

private:
  int closed = 8;
};

// Наследование первого уровня

struct PublicDerive : public PublicBase {
  int get_open() const { return open; }
  int get_semiclosed() const { return semiclosed; }
  // int get_closed() const { return closed; }
};

struct ProtectedDerive : protected ProtectedBase {
  int get_open() const { return open; }
  int get_semiclosed() const { return semiclosed; }
  // int get_closed() const { return closed; }
};

struct PrivateDerive : private PrivateBase {
  int get_open() const { return open; }
  int get_semiclosed() const { return semiclosed; }
  // int get_closed() const { return closed; }
};

// Наследование второго уровня

struct PublicDerive2 : public PublicDerive {
  int get_open() const { return open; }
  int get_semiclosed() const { return semiclosed; }
  // int get_closed() const { return closed; }
};

struct ProtectedDerive2 : protected ProtectedDerive {
  int get_open() const { return open; }
  int get_semiclosed() const { return semiclosed; }
  // int get_closed() const { return closed; }
};

struct PrivateDerive2 : private PrivateDerive {
  // int get_open() const { return open; }
  // int get_semiclosed() const { return semiclosed; }
  // int get_closed() const { return closed; }
};

// Внешний доступ

int main() {
  PublicDerive a;
  a.open;
  // a.semiclosed;
  // a.closed;

  ProtectedDerive b;
  // b.open;
  // b.semiclosed;
  // b.closed;

  PrivateDerive c;
  // c.open;
  // c.semiclosed;
  // c.closed;
}