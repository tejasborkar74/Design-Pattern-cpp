#include <bits/stdc++.h>
using namespace std;

// Your end product
class Plane {
	string _plane;
	string _body;
	string _engine;
public:
	Plane(string planeType): _plane{planeType} {}
	void setEngine(string type) { _engine = type; }
	void setBody(string body)   { _body = body;   }
	string getEngine()          { return _engine; }
	string getBody()            { return _body;   }

	void show() {
		cout << "Plane Type: " << _plane << endl
		     << "Body Type: " << _body << endl
		     << "Engine Type: " << _engine << endl << endl;
	}
};

// PlaneBuilder Abstract Class
// Means all builders should have atleast these methods
class PlaneBuilder {
protected:
	// important
	Plane *_plane;
public:
	virtual void getPartsDone() = 0;
	virtual void buildBody() = 0;
	virtual void buildEngine() = 0;
	// important return fn for obj
	Plane* getPlane() { return _plane; }
};

// PlaneBuilder concrete class
// knows only how to build Propeller Plane
class PropellerBuilder: public PlaneBuilder {
public:
	void getPartsDone() { _plane = new Plane("Propeller Plane"); }
	void buildEngine()  { _plane->setEngine("Propeller Engine");   }
	void buildBody()    { _plane->setBody("Propeller Body");   }
	//~PropellerBuilder(){delete _plane;}
};

// PlaneBuilder concrete class
// Knows only how to build Jet Plane
class JetBuilder: public PlaneBuilder {
public:
	void getPartsDone() { _plane = new Plane("Jet Plane"); }
	void buildEngine()  { _plane->setEngine("Jet Engine");   }
	void buildBody()    { _plane->setBody("Jet Body");   }
	//~JetBuilder(){delete _plane;}
};

// Defines steps and tells to the builder that build in given order.
class Director {
	PlaneBuilder *builder;
public:
	Plane* createPlane(PlaneBuilder *builder) {
		builder->getPartsDone();
		builder->buildBody();
		builder->buildEngine();
		return builder->getPlane();
	}
};

int32_t main()
{
	/*
	BUILDER PATTERN: Used when there is
		complex object,
		high configurations, or
		composition classes(object inside other classes)

	Factory Vs Builder
	1. In factory entire object created in single line, just there is 1 condition
	2. In builder pattern object creation has steps (nessaccary if composite class)
	*/
	Director dir;
	JetBuilder jb;
	PropellerBuilder pb;

	Plane *jet = dir.createPlane(&jb);
	Plane *pro = dir.createPlane(&pb);

	jet->show();
	pro->show();

	delete jet;
	delete pro;
}
