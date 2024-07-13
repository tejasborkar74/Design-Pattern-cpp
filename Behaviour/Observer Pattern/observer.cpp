#include <bits/stdc++.h>
using namespace std;

class ISubscriber {
public:
	virtual void notify(string msg) = 0;
};

class User: public ISubscriber {
	int userId;
public:
	User(int userId) {
		this->userId = userId;
	}

	void notify(string msg) {
		cout << "User: " << userId << " received msg: " << msg << endl;
	}
};

class Group {
	list<ISubscriber*> users;
public:
	void subscribe(ISubscriber* user) {
		users.push_back(user);
	}
	void unSubscribe(ISubscriber* user) {
		users.remove(user);
	}
	void notify(string msg) {
		for (auto user : users) {
			user->notify(msg);
		}
	}
};



int32_t main()
{
	/*
	1. 	Observer Design Pattern:
	    The Observer pattern is an important behavioral design pattern.
	    It allows objects (observers) that have subscribed to an event to wait for input
	    and react to it when notified. Therefore, they don’t have to continuously keep
	    checking whether the input has been provided or not. The main subject maintains a
	    list of all the observers, and whenever the event occurs, it notifies the observers
	    so they can update their states accordingly.
	2.  Basically a publisher-consumer pattern, like group chat
	*/

	Group* grp = new Group();

	User* user1 = new User(1);
	User* user2 = new User(2);
	User* user3 = new User(3);

	grp->subscribe(user1);
	grp->subscribe(user2);
	grp->subscribe(user3);

	grp->notify("New Message from Grp !!");

	grp->unSubscribe(user1);

	grp->notify("Second New Message from Grp !!");
}
