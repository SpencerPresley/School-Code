#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, string> pMap;

	pMap.insert(pair<string,string>("Maryland", "Salisbury"));
	pMap.insert(pair<string,string>("Virginia", "Richmond"));
	pMap.insert(pair<string,string>("Florida", "Miami"));
	pMap.insert(pair<string,string>("New York", "New York City"));
	pMap.insert(pair<string,string>("Ohio", "Cleveland"));

	string place;
	cout << "Enter state: ";
	getline(cin, place);

	if(!(pMap.find(place) == pMap.end()))
	{
		cout << pMap.find(place)->second << ", " << pMap.find(place)->first << endl;
	}

	else
	{
		cout << place << " is not present in the map." << endl;
	}

	return 0;
}
