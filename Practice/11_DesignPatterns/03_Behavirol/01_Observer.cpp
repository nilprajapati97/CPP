/*
✅ 01. Observer Pattern
Use Case: Notification system (e.g., news, stock price updates)

        +-------------------+
        |   Subject         |
        +-------------------+
        | +addObserver()    |
        | +removeObserver() |
        | +notifyObservers()|
        +-------------------+
                 ▲
                 |
        +-------------------+
        |   ConcreteSubject |
        +-------------------+
        | -state            |
        | +setState()       |
        +-------------------+
                 |
                 ▼
        +------------------+
        |   Observer       |
        +------------------+
        | +update()        |
        +------------------+
                 ▲
                 |
        +------------------+
        | ConcreteObserver |
        +------------------+
        | -state           |
        | +update()        |
        +------------------+



*/
#include <iostream>
#include <vector>
using namespace std;

class Observer {
public:
    virtual void update(int temp) = 0;
};

class WeatherStation {
    int temperature;
    vector<Observer*> observers;
public:
    void addObserver(Observer* o) { observers.push_back(o); }
    void setTemperature(int t) {
        temperature = t;
        for (auto o : observers) o->update(temperature);
    }
};

class Display : public Observer {
public:
    void update(int temp) override {
        cout << "Display updated: Temp = " << temp << endl;
    }
};

int main() {
    WeatherStation station;
    Display screen;
    station.addObserver(&screen);
    station.setTemperature(25);
}
