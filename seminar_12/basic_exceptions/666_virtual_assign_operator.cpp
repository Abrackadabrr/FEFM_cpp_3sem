const int bad_assignment = 0;

class A {
public:
  virtual A& operator= (const A& a) {
    assign(a);
    return *this;
  }

protected:
  void assign(const A& a) {
    // copy members of A from a to this
  }
};

class B : public A {
public:
  virtual B& operator= (const A& a) {
    if (const B* b = dynamic_cast<const B*>(&a))
      assign(*b);
    else
      throw bad_assignment;
    return *this;
  }

protected:
  void assign(const B& b) {
    A::assign(b); // Let A's assign() copy members of A from b to this
    // copy members of B from b to this
  }
};

int main() {

}