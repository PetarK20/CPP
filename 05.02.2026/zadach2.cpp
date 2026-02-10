#include <iostream>
#include <string>
#include <map>
using namespace std;

class Configuration {
private:
    map<string, string> settings;

    Configuration(){}
    Configuration(const Configuration&) = delete;
    Configuration& operator=(const Configuration&) = delete;


public:
    static Configuration& getInstance() {
        static Configuration instance;
        return instance;
    }

    void setSetting(const string& key, const string& value) {
        settings[key] = value;
    }
    string getSetting(const string& key) {
        return settings[key];
    }

};

int main() {
    Configuration& config1 = Configuration::getInstance();
    Configuration& config2 = Configuration::getInstance();

     config1.setSetting("username", "Admin");
     config2.setSetting("theme", "Dark");

    cout << "Username: "<< config1.getSetting("username") << endl;
    cout << "Theme: "<<config2.getSetting("theme") << endl;

    cout << "Config1 address: " << &config1 << endl;
    cout << "Config2 address: " << &config2 << endl;

    return 0;
}