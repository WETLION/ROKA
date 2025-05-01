#include <iostream>

// 30087번 진흥원 세미나 

using namespace std;

int n;
string str; 

int main() {
	cin >> n;
	while(n--) { // endl 안함
		cin >> str;
		if(str == "Algorithm") cout << 204 << endl;
		if(str == "DataAnalysis") cout << 207 << endl;
		if(str == "ArtificialIntelligence") cout << 302 << endl;
		if(str == "CyberSecurity") cout << "B101" << endl;
		if(str == "Network") cout << 303 << endl;
		if(str == "Startup") cout << 501 << endl;
		if(str == "TestStrategy") cout << 105 << endl;
	}
	cin >> n;

	return 0;
}