#include <bits/stdc++.h>
using namespace std;

template<typename T>
class VectorWrapper {
	vector<T> v;
public:
	void addElement(const T& element) {
		v.push_back(element);
	}

	size_t getSize() const {
		return v.size();
	}

	void printVector() const {
		for (auto i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
};

int32_t main()
{

	/*
	DECORATOR/WRAPPER pattern:
	It is wrapper in an existing class, to add new functionality to the existing class
	*/

	VectorWrapper<int> vw;

	vw.addElement(10);
	vw.addElement(20);
	vw.addElement(30);

	cout << "Vector size: " << vw.getSize() << endl;

	vw.printVector();
}
