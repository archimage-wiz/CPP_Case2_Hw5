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
    virtual void print_info() {  }

    Figure() : Figure(0){
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

protected:
    int _a, _b, _c, _A, _B, _C;

public:
    Triangle(int a, int b, int c, int A, int B, int C) : _a(a), _b(b), _c(c), _A(A), _B(B), _C(C), Figure(3) {
        x_name = "Треугольник";
     }
    virtual void print_info() override {
        std::cout << x_name << std::endl;
        std::cout << "Стороны:";
        std::cout << " a=" << _a << " b=" << _b << " c=" << _c << std::endl;
        std::cout << "Углы:";
        std::cout << " A=" << _A << " B=" << _B << " C=" << _C << std::endl;
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
        x_name = "Прямоугольный треугольник";
    }
};
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
        x_name = "Равнобедренный треугольник";
    }
};
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {
        x_name = "Равносторонний треугольник";
    }
};

class Quadrangle : public Figure {

protected:
    int _a, _b, _c, _d, _A, _B, _C, _D;

public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : _a(a), _b(b), _c(c), _d(d), _A(A), _B(B), _C(C), _D(D), Figure(4) { 
        x_name = "Четырехугольник";
    }
    virtual void print_info() override {
        std::cout << x_name << std::endl;
        std::cout << "Стороны:";
        std::cout << " a=" << _a << " b=" << _b << " c=" << _c << " d=" << _d << std::endl;
        std::cout << "Углы:";
        std::cout << " A=" << _A << " B=" << _B << " C=" << _C << " D=" << _D << std::endl;
    }
};
class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {
        x_name = "Параллелограмм";
    }
};
class Rhomb : public Parallelogram {
public:
    Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B) {
        x_name = "Ромб";
    }
};
class Rectangle : public Parallelogram {
public:
    Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) {
        x_name = "Прямоугольник";
    }
};
class Square : public Rectangle {
public:
    Square(int a) : Rectangle(a, a) {
        x_name = "Квадрат";
    }
};



int main() { setlocale(LC_ALL, "Ru");

    //Figure fig;
    //std::cout << fig.get_name() + ": " << fig.get_sides_count() << std::endl;


    Triangle fig1(10, 20, 30, 50, 60, 70);
    fig1.print_info();
    std::cout << std::endl;

    RightTriangle fig_rt(10, 20, 30, 50, 60);
    fig_rt.print_info();
    std::cout << std::endl;

    IsoscelesTriangle fig_it(10, 20, 50, 60); // a, b, A, B : c = a, C= A
    fig_it.print_info();
    std::cout << std::endl;

    EquilateralTriangle fig_et(30);
    fig_et.print_info();
    std::cout << std::endl;

    Quadrangle fig2(10, 20, 30, 40, 50, 60, 70, 80);
    fig2.print_info();
    std::cout << std::endl;

    Rectangle fig_rect(10, 20);
    fig_rect.print_info();
    std::cout << std::endl;

    Square fig_square(20);
    fig_square.print_info();
    std::cout << std::endl;

    Parallelogram fig_p(20, 30, 30, 40);
    fig_p.print_info();
    std::cout << std::endl;

    Rhomb fig_r(30, 30, 40);
    fig_r.print_info();
    std::cout << std::endl;
    
    return 0;
}
