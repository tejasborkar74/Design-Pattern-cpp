#include <bits/stdc++.h>
using namespace std;

class IButton {
public:
	virtual void press() = 0;
};
class MacButton: public IButton {
public:
	void press() {
		cout << "Mac button pressed" << endl;
	}
};
class WinButton: public IButton {
public:
	void press() {
		cout << "Windows button pressed" << endl;
	}
};


class ITextBox {
public:
	virtual void showText() = 0;
};
class MacTextBox: public ITextBox {
public:
	void showText() {
		cout << "Showing Mac text box" << endl;
	}
};
class WinTextBox: public ITextBox {
public:
	void showText() {
		cout << "Showing Windows text box" << endl;
	}
};


class IFactory {
public:
	virtual IButton* CreateButton() = 0;
	virtual ITextBox* CreateTextBox() = 0;
};
class MacFactory: public IFactory {
public:
	IButton* CreateButton() {
		return new MacButton();
	}
	ITextBox* CreateTextBox() {
		return new MacTextBox();
	}
};
class WinFactory: public IFactory {
public:
	IButton* CreateButton() {
		return new WinButton();
	}
	ITextBox* CreateTextBox() {
		return new WinTextBox();
	}
};

class GUIAbstractFactory {
public:
	static IFactory* CreateFactory(string osType) {
		if (osType == "mac") {
			return new MacFactory();
		} else if (osType == "windows") {
			return new WinFactory();
		}

		// default
		return new MacFactory();
	}
};


int32_t main()
{
	/*
	ABSTRACT PATTERN:
	1. We use the Factory pattern to create multiple objects from the same family
	   without having to deal with the creation process. The Abstract pattern is similar.
	   The difference is that it provides a constructor to create families of related objects.
	   It is abstract, which means that it does not specify concrete classes or constructors.
	2. Basically if the conditions of factory pattern becomes nested if else then use Abstract Pattern.
	*/

	string osType;
	cin >> osType;

	IFactory* fact = GUIAbstractFactory::CreateFactory(osType);

	IButton* button = fact->CreateButton();
	button->press();

	ITextBox* textBox = fact->CreateTextBox();
	textBox->showText();

}
