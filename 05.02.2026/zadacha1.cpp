// Каква е основната цел на шаблона Singleton?
// Основната цел на шаблона Singleton е да осигури, 
// че даден клас има само един екземпляр и да предостави 
// глобална точка за достъп до този екземпляр. 
// Защо конструктурът на Singleton трябва да е private?
// Конструкторът на Singleton трябва да е private,
// за да се предотврати създаването на нови екземпляри
// на класа отвън, което гарантира, че само един екземпляр
// може да съществува.
// Как доказваме в "main()", че получаваме една и съща инстанция 
// при всяко извикване на getInstance()?
// В "main()" можем да докажем, че получаваме една и съща
// инстанция при всяко извикване на getInstance(),
// като сравним адресите на върнатите обекти.



#include <iostream>
#include <string>

using namespace std;

class Logger{
private:
    Logger() {}
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

public:

    static Logger& getInstance(){
        static Logger instance;
        return instance;
    }

    void log(const string& message) {
        cout << "[LOG]: " << message << endl;
    }

};

int main(){

    Logger& logger1 = Logger::getInstance();
    Logger& logger2 = Logger::getInstance();


    logger1.log("Application started.");
    logger2.log("This message is logged from the same object.");

    cout << "Logger1 address: " << &logger1 << endl;
    cout << "Logger2 address: " << &logger2 << endl;



    return 0;
}