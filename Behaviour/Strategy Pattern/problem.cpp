#include <bits/stdc++.h>
using namespace std;

class Vehicle {
public:
	virtual void drive() {
		cout << "Base class drive" << endl;
	}
};

class SportVehicle: public Vehicle {
public:
	void drive() {
		cout << "Fast drive" << endl;
	}
};

class OffRoadVehicle: public Vehicle {
public:
	void drive() {
		cout << "Fast drive" << endl;
	}
};

class FamilyVehicle: public Vehicle {
public:
};

int32_t main()
{
	/*
	Problem: If child on same inheritance level want same capability then from base while overiding
			 then it can cause Duplication

	Here offroad and sporty want same drive(), but have to override and the code is duplicate
	*/

	Vehicle *v1 = new SportVehicle();
	v1->drive();

	Vehicle *v2 = new OffRoadVehicle();
	v2->drive();

	FamilyVehicle fv;
	Vehicle *v3 = &fv;
	v3->drive();
}
