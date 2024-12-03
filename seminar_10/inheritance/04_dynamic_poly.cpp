enum PolygonTypes {
    PENTAGON = 5,
    HEXAGON = 6
};

struct PolygonBasePart {
    std::vector<Point> points;  

    PolygonTypes type;   // это ДИНАМИЧЕСКИЙ ТИП
    void * real_implementation;
};

struct Hexagon {
    PolygonBasePart base_part;
    const static int number_of_vertex = 6;

    Hexagon(): base_part{std::vector<Point>{}, PolygonTypes::HEXAGON, this} {};
};

struct Pentagon {
    PolygonBasePart base_part;
    const static int number_of_vertex = 5;

    Pentagon(): base_part{std::vector<Point>{}, PolygonTypes::PENTAGON, this} {};
};

int get_number_of_vertex(PolygonBasePart* base) {
    return base->square();
}

int main() {
    std::vector<PolygonBasePart*> flat_figures;
    flat_figures.reserve(10);

    for (int i = 0; i < 5; i++) {
        Pentagon* p_ptr = new Pentagon();
        flat_figures.push_back(&p_ptr->base_part);  
                                                               
        Hexagon* h_ptr = new Hexagon();
        flat_figures.push_back(&h_ptr->base_part);
    }
    // Статический тип flat_figures[i] -- это PolygonBasePart*
    // Именно этот тип известен на этапе компиляции программы
    
    // При этом динамический тип (HEXAGON или PENTAGON) будет 
    // определяться динамически в процессе исполнения программы

    // Отсюда и название -- жинамический полиморфизм 
}