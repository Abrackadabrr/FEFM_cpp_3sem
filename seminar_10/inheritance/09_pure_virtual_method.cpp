struct PolygonIntefrace {
    virtual double square() = 0;

    virtual ~PolygonIntefrace() {};
};

// это типичный пример ИНТЕРФЕЙСНОГО КЛАССА --
// класса, в котором все методы виртуальные

// Объекты класса, у которого хотя бы один
// метод чисто вируальный, нельзя создать

// Оно и понятно -- это просто тип "без метода"

struct Hexagon: public PolygonIntefrace {
    double square() override {
        return 0;
    }
};

// Теперь все наследнии ОБЯЗАНЫ переопределить 
// этот метод у себя в теле класса

struct Pentagon: public PolygonIntefrace {
    double square() override {
        return 1;
    }
};

// Иначе будет ошибка компиляции

int main() {

    Hexagon h{};
    Pentagon p{};
    SuperPentagon sp{};

    // PolygonIntefrace pi{};
}
