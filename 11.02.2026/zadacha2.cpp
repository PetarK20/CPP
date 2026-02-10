#include <iostream>
#include <string>
#include <memory>
using namespace std;


class Car {
public:
    virtual ~Car() = default;
    virtual void drive() = 0; 
};

class Tesla : public Car {
public:
    void drive() override {
        cout << "Tesla Model S Plaid: 0-100 km/h in 2.1s. Silent but deadly!⚡\n";
    }
};

class Lamborghini : public Car {
public:
    void drive() override {
        cout << "Lamborghini Revuelto: V12 Hybrid screaming at 9000 RPM! 🇮🇹\n";
    }
};

class CarFactory {
public:
    static unique_ptr<Car> createCar(const string& type) {
        if (type == "electric") return make_unique<Tesla>();
        if (type == "beast") return make_unique<Lamborghini>();
        return nullptr;
    }
};

int main(){
    unique_ptr<Car> c1 = CarFactory::createCar("electric");
    unique_ptr<Car> c2 = CarFactory::createCar("beast");

    if (c1) c1->drive();
    if (c2) c2->drive();

    return 0;
}