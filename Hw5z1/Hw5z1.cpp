#include <iostream>


class Figure {

private:
    int x_sides_count = 0;

protected:
    std::string x_name;
    Figure(int sides_count) {
        x_sides_count = sides_count > 0 ? sides_count : 0;
    }

public:
    Figure() {
        Figure(0);
        x_name = "Фигура";
     }
    virtual int get_sides_count() {
        return x_sides_count;
    }
    virtual std::string get_name() {
        return x_name;
    }

};

class Triangle : public Figure {

public:
    Triangle() : Figure(3) {
        x_name = "Треугольник";
     }
};

class Quadrangle : public Figure {

public:
    Quadrangle() : Figure(4) { 
        x_name = "Четырехугольник";
    }
};


int main() { setlocale(LC_ALL, "Ru");

    Figure fig;
    std::cout << fig.get_name() + ": " << fig.get_sides_count() << std::endl;
    Triangle fig1;
    std::cout << fig1.get_name() + ": " << fig1.get_sides_count() << std::endl;
    Quadrangle fig2;
    std::cout << fig2.get_name() + ": " << fig2.get_sides_count() << std::endl;

    
    return 0;
}
