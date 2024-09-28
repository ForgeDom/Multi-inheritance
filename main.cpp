#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
class Base {
protected:
    T1 value1;
    T2 value2;

public:
    Base(T1 v1, T2 v2) : value1(v1), value2(v2) {
        cout << "Base constructor called: value1 = " << value1 << ", value2 = " << value2 << endl;
    }

    virtual ~Base() {
        cout << "Base destructor called" << endl;
    }

    void display() {
        cout << "Base: value1 = " << value1 << ", value2 = " << value2 << endl;
    }
};

template <typename T1, typename T2, typename T3, typename T4>
class Child : public Base<T1, T2> {
protected:
    T3 value3;
    T4 value4;

public:
    Child(T1 v1, T2 v2, T3 v3, T4 v4) : Base<T1, T2>(v1, v2), value3(v3), value4(v4) {
        cout << "Child constructor called: value3 = " << value3 << ", value4 = " << value4 << endl;
    }

    ~Child() {
        cout << "Child destructor called" << endl;
    }

    void display() {
        Base<T1, T2>::display();
        cout << "Child: value3 = " << value3 << ", value4 = " << value4 << endl;
    }
};

template <typename T1, typename T2, typename T5, typename T6>
class Child2 : public Base<T1, T2> {
protected:
    T5 value5;
    T6 value6;
public:
    Child2(T1 v1, T2 v2, T5 v5, T6 v6) : Base<T1, T2>(v1, v2), value5(v5), value6(v6) {
        cout << "Child2 constructor called: value5 = " << value5 << ", value6 = " << value6 << endl;
    }

    ~Child2() {
        cout << "Child2 destructor called" << endl;
    }

    void display() {
        Base<T1, T2>::display();
        cout << "Child2: value5 = " << value5 << ", value6 = " << value6 << endl;
    }
};

int main() {
    Child<int, double, string, char> child(10, 20.5, "Hello", 'A');
    child.display();

    Child2<int, double, float, bool> child2(5, 15.75, 3.14f, true);
    child2.display();

    return 0;
}
