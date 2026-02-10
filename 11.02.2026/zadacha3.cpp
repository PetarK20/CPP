#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Pizza{
protected:
    string dimension;

public:
    Pizza(const string& dimension) : dimension(dimension) {}
    
    virtual void prepare() = 0;
    virtual ~Pizza() = default;
};

class Margherita : public Pizza {
public:
    Margherita(const string& dimension) : Pizza(dimension) {}
    void prepare() override {
        cout << "Preparing " << dimension << " Margherita: Tomato, Mozzarella, Basil\n";
    }
};

class Pepperoni : public Pizza {
public:
    Pepperoni(const string& dimension) : Pizza(dimension) {}
    void prepare() override {
        cout << "Preparing " << dimension << " Pepperoni: Tomato, Cheese, Spicy Pepperoni\n";
    }
};

class PizzaFactory {
public:
    static unique_ptr<Pizza> createPizza(const string& type, const string& dimension) {
        if (type == "margherita") return make_unique<Margherita>(dimension);
        if (type == "pepperoni") return make_unique<Pepperoni>(dimension);
        return nullptr;
    }
};

int main(){
    unique_ptr<Pizza> p1 = PizzaFactory::createPizza("margherita", "large");
    unique_ptr<Pizza> p2 = PizzaFactory::createPizza("pepperoni", "small");

    if (p1) p1->prepare();
    if (p2) p2->prepare();

    return 0;
}
