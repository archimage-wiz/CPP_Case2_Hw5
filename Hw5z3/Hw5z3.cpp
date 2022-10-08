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
    virtual bool check() {  
        return x_sides_count == 0 ? true : false;
    }
    virtual void print_info(Figure * p_base) {
        std::cout << x_name + ":" << std::endl;
        std::cout << (p_base->check() == true ? "Правильная" : "Неправильная") << std::endl;
        std::cout << "Количество сторон: " << get_sides_count() << std::endl;
    }

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
    virtual bool check() { 
        //std::cout << "вызван чек у треугольника" << std::endl;
        return (get_sides_count() == 3 && (_A + _B + _C) == 180) ? true : false;
    }
    virtual void print_info(Figure * p_base) override {
        Figure::print_info(p_base);
        std::cout << "Стороны:";
        std::cout << " a=" << _a << " b=" << _b << " c=" << _c << std::endl;
        std::cout << "Углы:";
        std::cout << " A=" << _A << " B=" << _B << " C=" << _C << std::endl;
    }

};

class RightTriangle : public Triangle {
public:
    virtual bool check() { 
        //std::cout << "вызван чек у райт триангле" << std::endl;
        if (Triangle::check())
            return (_C == 90) ? true : false;
        else
            return false;
    }

    RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
        x_name = "Прямоугольный треугольник";
    }
};
class IsoscelesTriangle : public Triangle {
public:
    virtual bool check() { 
        if (Triangle::check())
            return (_a == _c && _A == _C) ? true : false;
        else
            return false;
    }
    IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
        x_name = "Равнобедренный треугольник";
    }
};
class EquilateralTriangle : public Triangle {
public:
    virtual bool check() { 
        if (Triangle::check())
            return (_a == _b && _a == _c && _A == _B && _A == _C && _C == 60) ? true : false;
        else
            return false;
    }
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
    virtual bool check() { 
        return (get_sides_count() == 4 && (_A + _B + _C + _D) == 360) ? true : false;
    }
    virtual void print_info(Figure * p_base) override {
        Figure::print_info(p_base);
        std::cout << "Стороны:";
        std::cout << " a=" << _a << " b=" << _b << " c=" << _c << " d=" << _d << std::endl;
        std::cout << "Углы:";
        std::cout << " A=" << _A << " B=" << _B << " C=" << _C << " D=" << _D << std::endl;
    }
};
class Parallelogram : public Quadrangle {
public:
    virtual bool check() { 
        if (Quadrangle::check())
            return (_a == _c && _b == _d && _A == _C && _B == _D) ? true : false;
        else
            return false;
    }
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {
        x_name = "Параллелограмм";
    }
};
class Rectangle : public Parallelogram {
public:
    virtual bool check() { 
        if (Parallelogram::check())
            return (_A == _B && _B == _C && _C == _D && _D == 90) ? true : false;
        else
            return false;
    }
    Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) {
        x_name = "Прямоугольник";
    }
};
class Rhomb : public Parallelogram {
public:
    virtual bool check() { 
        if (Parallelogram::check())
            return (_a == _b && _b == _c && _c == _d) ? true : false;
        else
            return false;
    }
    Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B) {
        x_name = "Ромб";
    }
};
class Square : public Rectangle {
public:
    virtual bool check() { 
        if (Rectangle::check())
            return (_a == _b && _b == _c && _c == _d) ? true : false;
        else
            return false;
    }
    Square(int a) : Rectangle(a, a) {
        x_name = "Квадрат";
    }
};



int main() { setlocale(LC_ALL, "Ru");

    Figure fig;
    Triangle fig1(10, 20, 30, 50, 60, 70);
    RightTriangle fig_rt(10, 20, 30, 50, 60);
    RightTriangle fig_rt2(10, 20, 30, 50, 40);
    IsoscelesTriangle fig_it(10, 20, 50, 60); // a, b, A, B : c = a, C= A
    EquilateralTriangle fig_et(30);
    Quadrangle fig2(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle fig_rect(10, 20);
    Square fig_square(20);
    Parallelogram fig_p(20, 30, 30, 40);
    Rhomb fig_r(30, 30, 40);

    Figure * p_base;
    p_base = &fig;
    p_base->print_info(p_base);
    std::cout << std::endl;

    p_base = &fig1;
    p_base->print_info(p_base);
    std::cout << std::endl;

    p_base = &fig_rt;
    p_base->print_info(p_base);
    std::cout << std::endl;

    p_base = &fig_rt2;
    p_base->print_info(p_base);
    std::cout << std::endl;

    p_base = &fig_it;
    p_base->print_info(p_base);
    std::cout << std::endl;

    p_base = &fig_et;
    p_base->print_info(p_base);
    std::cout << std::endl;

    p_base = &fig2;
    p_base->print_info(p_base);
    std::cout << std::endl;

    p_base = &fig_rect;
    p_base->print_info(p_base);
    std::cout << std::endl;

    p_base = &fig_square;
    p_base->print_info(p_base);
    std::cout << std::endl;

    p_base = &fig_p;
    p_base->print_info(p_base);
    std::cout << std::endl;

    p_base = &fig_r;
    p_base->print_info(p_base);
    std::cout << std::endl;

    return 0;
}
