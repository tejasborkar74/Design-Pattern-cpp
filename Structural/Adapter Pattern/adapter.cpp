#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
We have a XML data object and DataAnalyticsTool class
DataAnalyticsTool only analyse data in json format
So we need an adapter which convert the xml/or any other data form to json then pass it to tool
*/


class XMLData {
	string xmlData;
public:
	XMLData(string pXMLdata) {
		xmlData = pXMLdata;
	}
	string getXMLData() {
		return xmlData;
	}
};

class DataAnalyticsTool {
	string jsonData;
public:
	DataAnalyticsTool() {} // default constructor
	DataAnalyticsTool(string pJsonData) {
		jsonData = pJsonData;
	}

	virtual void analyseData() {
		cout << "Analysing Data .... \n" << jsonData << endl;
	}
};

// Adapter class
class Adapter: public DataAnalyticsTool {
	XMLData* xmlData;
public:
	Adapter(XMLData* pXMLdata) {
		xmlData = pXMLdata;
	}

	void analyseData() {
		cout << "Converting XML data " << xmlData->getXMLData() << " to JSON data" << endl;
		cout << "Analysing the converted data";
	}
};

class Client {
public:
	void ProcessData(DataAnalyticsTool* tool) {
		tool->analyseData();
	}
};




int32_t main()
{
	/*
	ADAPTER PATTERN:
	1. when there are 2 incompatible objects, but client can satisfy but the problem
	   is incompatible
	2. client will not know adapter is put in between (important)
	3. In this example we are having object inside the adapter (composition)
	   therefore it is called object adapter pattern
	   if we have done multiple inheritance then it would be class Adatper pattern
	*/

	XMLData* xmlData = new XMLData("Sample XML Data");

	// problem
	// DataAnalyticsTool* tool = new DataAnalyticsTool(/*expects json data */);

	// Solution - we will create object of adapter (inherite from DataAnaluticsTool)
	DataAnalyticsTool* tool = new Adapter(xmlData);


	Client* client = new Client;
	client->ProcessData(tool);
}
