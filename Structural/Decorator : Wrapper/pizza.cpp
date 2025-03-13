#include <bits/stdc++.h>
using namespace std;

// base Pizza abstract
class pizza {
public:
	int virtual cost() = 0;
};

class margheritaPizza: public pizza {
public:
	int cost() override {
		return 100;
	}
};

class vegDelightPizza: public pizza {
public:
	int cost() override {
		return 150;
	}
};

class chikenPizza: public pizza {
public:
	int cost() override {
		return 200;
	}
};

// Now toppings decorator
class toppingDecorator: public pizza {
};

class extraCheese: public toppingDecorator {
	pizza *basePizza;
public:
	extraCheese(pizza *p) {
		basePizza = p;
	}

	int cost() override {
		return basePizza->cost() + 10;
	}
};

class extraVegies: public toppingDecorator {
	pizza *basePizza;
public:
	extraVegies(pizza *p) {
		basePizza = p;
	}

	int cost() override {
		return basePizza->cost() + 30;
	}
};

class extraChiken: public toppingDecorator {
	pizza *basePizza;
public:
	extraChiken(pizza *p) {
		basePizza = p;
	}

	int cost() override {
		return basePizza->cost() + 50;
	}
};



int32_t main()
{
	pizza *p1 = new chikenPizza();
	cout << "Cost of p1: " << p1->cost() << endl; // 200

	pizza *p2 = new extraCheese(new chikenPizza());
	cout << "Cost of p2: " << p2->cost() << endl; // 210

	pizza *p3 = new extraCheese( new extraChiken(new extraCheese(new margheritaPizza())));
	cout << "Cost of p3: " << p3->cost() << endl; // 170


}
