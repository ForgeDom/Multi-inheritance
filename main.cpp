#include <iostream>

using namespace std;

class Square {
protected:
    int side;
public:
    Square(int s) : side(s) {}
    virtual ~Square() {
        cout << "Square destructor called" << endl;
    }
    virtual int getSide() const {
        return side;
    }

    virtual double getArea() const {
        return side * side;
    }
};

class Circle {
protected:
    int radius;
public:
    Circle(int r) : radius(r) {}
    virtual ~Circle() {
        cout << "Circle destructor called" << endl;
    }
    virtual int getRadius() const {
        return radius;
    }

    virtual double getArea() const {
        return 3.14 * radius * radius;
    }
};

class CircleInSquare : public Square, public Circle {
public:
    CircleInSquare(int side) : Square(side), Circle(side / 2) {}

    ~CircleInSquare() { 
        cout << "CircleInSquare destructor called." << endl;
    }
    void Show() const {
        cout << "Square side: " << getSide() << endl;
        cout << "Circle radius: " << getRadius() << endl;
        cout << "Square area: " << Square::getArea() << endl;
        cout << "Circle area: " << Circle::getArea() << endl;
    }
};

int main() {
    CircleInSquare* size = new CircleInSquare(10);
    size->Show();
    delete size;
    return 0;
}
//Images\background.png