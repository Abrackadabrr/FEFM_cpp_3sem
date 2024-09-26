#include<iostream> 

// а давайте теперь представим, что это очень большой код, 
// который запускается на общем большом сервере 
// и считает большую серьёзную задачу, 
// например, расчет трехмерного течения около самолёта или решение большущей СЛАУ


// это один шаг итерационного алгоритма
int some_difficult_stuff() {
    int n = 520000;
    int **p = new int*[n];
    for (int i = 0; i < n; i++)
        // например, нам нужно из файла считать скалярное поле и поизвести над ним расчет. 
        // очень много циферок и мы выделяем память в куче
        p[i] = new int[n];
        
        // и тут куча работы по вычислениям
    std::cout << "Fuf..., stuff has been done." << std::endl;
    return 1;
}

int main() {
    
    // а здесь итерация вычислительного алгоритма
    int b = some_difficult_stuff();

    int s = some_difficult_stuff();
    int i = some_difficult_stuff();
//    i = some_difficult_stuff();

    int c = some_difficult_stuff();
    int a;
    std::cin >> a;
}
