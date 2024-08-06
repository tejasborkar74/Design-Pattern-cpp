#include <bits/stdc++.h>
using namespace std;

class DriveStrategy {
public:
	virtual void drive() = 0;
};

class NormalDrive: public DriveStrategy {
public:
	void drive() {
		cout << "Normal Drive" << endl;
	}
};

class FastDrive: public DriveStrategy {
public:
	void drive() {
		cout << "Fast Drive" << endl;
	}
};


class Vehicle {
	DriveStrategy *obj;
public:
	// constructor
	Vehicle(DriveStrategy *obj) {
		this->obj = obj;
	}

	void drive() {
		obj->drive();
	}
};

class SportVehicle: public Vehicle {
public:
	SportVehicle(DriveStrategy *obj): Vehicle(obj) {}
};

class OffRoadVehicle: public Vehicle {
public:
	OffRoadVehicle(DriveStrategy *obj): Vehicle(obj) {}
};

class FamilyVehicle: public Vehicle {
public:
	FamilyVehicle(DriveStrategy *obj): Vehicle(obj) {}
};


int32_t main()
{
	/*
	SOLUTION: Strategy Design Pattern
	Make a separe class for driveStrategy and use the object of
	driveStrategy to call drive in base Vehicle class
	*/

	DriveStrategy *normalObj = new NormalDrive();
	DriveStrategy *FastObj = new FastDrive();

	Vehicle *v1 = new SportVehicle(FastObj);
	v1->drive();

	Vehicle *v2 = new OffRoadVehicle(FastObj);
	v2->drive();

	FamilyVehicle fv(normalObj);
	Vehicle *v3 = &fv;
	v3->drive();
}
