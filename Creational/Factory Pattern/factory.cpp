#include <bits/stdc++.h>
using namespace std;

class Vehicle {
public:
    // pure virtual function
    virtual void createVehicle() = 0;
};

class Car: public Vehicle {
public:
    void createVehicle() {
        cout << "Car created !!" << endl;
    }
};

class Bike: public Vehicle {
public:
    void createVehicle() {
        cout << "Bike created !!" << endl;
    }
};

class VehicleFactory {
public:
    /*
    static fn not associated with class (so this class is like an interface)
    we can call this fn without using object of class, just use name of class
    */
    static Vehicle* getVehicle(string vehicleType) {
        Vehicle* v;
        if (vehicleType == "Car") {
            v = new Car();
        }
        else if (vehicleType == "Bike") {
            v = new Bike();
        }

        return v;
    }
};


int32_t main()
{
    /*
    Problem:
    When ever we create a new vehical class we need to change logic in client (main, side if else condition)
    Client should not care about how we are doing this, he should just pass vehicle type and object shall be created
    To solve this we can use factory Pattern
    */

    Vehicle *v;
    string vehicleType; cin >> vehicleType;

    if (vehicleType == "Car") {
        v = new Car();
    }
    else if (vehicleType == "Bike") {
        v = new Bike();
    }

    v->createVehicle();

    /*
    Solution:
    We can move the logic of creation to a factory type interface
    So client would not be bothered by changes in out vehicle library
    */
    Vehicle *obj = VehicleFactory::getVehicle(vehicleType);
    obj->createVehicle();


    /*
    DEFINATION OF FACTORY PATTERN:

    The Factory pattern is a creational pattern that provides a template that can be used
    to create objects. It is used in complex situations where the type of the object required
    varies and needs to be specified in each case.

    It does not use the new keyword directly to instantiate objects.
    This means that it does not explicitly require the use of a constructor to create objects.
    Instead, it provides a generic interface that delegates the object creation responsibility
    to the corresponding subclass.
    */


}
