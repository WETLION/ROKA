#include <iostream>
#include <vector>
#include <string>

// 27649번 토크나이저

using namespace std;

string str;
vector<string> v;

int main() {
	while(1) {
		cin >> str;
		if(cin.eof()) break;
		string temp;
		for(int i = 0; i < str.length(); i++) {
			if(str[i] == '&' || str[i] == '|') {
				if(!temp.empty()) v.push_back(temp);
				temp = "";
				temp += str[i];
				temp += str[i++];
				v.push_back(temp);
				temp = "";
			}
			else if(str[i] == '<' || str[i] == '>' || str[i] == '(' || str[i] == ')') {
				if(!temp.empty()) v.push_back(temp);
				temp = "";
				temp += str[i];
				v.push_back(temp);
				temp = "";
			}
			else {
				temp += str[i];
			}
		}
		if(!temp.empty()) v.push_back(temp);
	}
	for(string i: v) {
		cout << i << " ";
	}

	return 0;
}
