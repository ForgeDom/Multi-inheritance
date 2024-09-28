#include <iostream>

using namespace std;

class Square {
protected:
    int side;
public:
    Square(int s) : side(s) {}

    int getSide() const {
        return side;
    }

    double getArea() const {
        return side * side;
    }
};

class Circle {
protected:
    int radius;
public:
    Circle(int r) : radius(r) {}

    int getRadius() const {
        return radius;
    }

    double getArea() const {
        return 3.14 * radius * radius;
    }
};

class CircleInSquare : public Square, public Circle {
public:
    CircleInSquare(int side) : Square(side), Circle(side / 2) {}

    void Show() const {
        cout << "Square side: " << getSide() << endl;
        cout << "Circle radius: " << getRadius() << endl;
        cout << "Square area: " << Square::getArea() << endl;
        cout << "Circle area: " << Circle::getArea() << endl;
    }
};

int main() {
    CircleInSquare size(10);
    size.Show();
    return 0;
}
//Images\background.png