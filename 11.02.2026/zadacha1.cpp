// 1
// Фабриката отделя създаването на обекта от неговата употреба. 
// Клиентът работи само с общ интерфейс, без да познава конкретните класове.

// 2
// Можете да добавяте нови видове функционалност,
// без да променяте стария, работещ код на клиента.

// 3
// Кодът става по-гъвкав (слаба свързаност) и логиката 
// за създаване е събрана на едно място.

// 4
// Излишно е при малки проекти или когато даден клас
// винаги ще е само един вид. Води до бавен код и по-трудно четене.

#include <iostream>
#include <string>
#include <memory>
using namespace std;


class Animal {
public:
    virtual ~Animal() = default;
    virtual void speak() = 0; 
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog says: Woof!\n";
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat says: Meow!\n";
    }
};

class AnimalFactory {
public:
    static unique_ptr<Animal> create(const string& name) {
        if (name == "dog") return make_unique<Dog>();
        if (name == "cat") return make_unique<Cat>();
        return nullptr;
    }
};

int main(){
    unique_ptr<Animal> a1 = AnimalFactory::create("dog");
    unique_ptr<Animal> a2 = AnimalFactory::create("cat");

    if (a1) a1->speak();
    if (a2) a2->speak();

    return 0;
}

