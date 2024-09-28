#include <iostream>
using namespace std;

class Wheels {
protected:
	int wheels_amount;
public:
	Wheels(int amount) : wheels_amount(amount) {};
	virtual ~Wheels() {
		cout << "Wheel destructor called" << endl;
	}
	void wheelRotate() const {
		cout << "Your car has " << wheels_amount << " wheels" << endl;
	}
};

class Engine {
protected:
	int cylinders;
public:
	Engine(int v_amount) : cylinders(v_amount) {}
	virtual ~Engine() {
		cout << "Engine destructor called" << endl;
	}
	void enginePower() const{
		cout << "Your car is rather powerful, it has " << cylinders << " cylinders" << endl;
	}
};

class Doors {
protected:
	int door_count;
public:
	Doors(int doors) : door_count(doors) {};
	virtual ~Doors() {
		cout << "Doors destructor called" << endl;
	}
	void openingDoors() {
		cout << "Your car has " << door_count << ", but only " << door_count - 1 << " can open(" << endl;
	}
};

class Car : public Wheels, public Engine, public Doors {
protected:
	string car_model;
public:
	Car(int wheels, int cylinders, int doors, string model) : Wheels(wheels), Engine(cylinders), Doors(doors), car_model(model){}

	void showcar() {
		cout << "Your car is:" << car_model << endl;
		wheelRotate();
		enginePower();
		openingDoors();
	}
};

int main() {
	Car*  mycar = new Car(4, 16, 2, "Toyota Mark-2");
	mycar->showcar();
	cout << endl << "<<------------------------------------------------>>" << endl << endl;;
	delete mycar;
	return 0;
}