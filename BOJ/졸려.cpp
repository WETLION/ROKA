#include <iostream>
#include <algorithm>

// 9519번 졸려 

using namespace std;

int x;
string arr[10000];

string convert(string str) {
	string ret, rev;
	for(int i = 0; i < str.size(); i = i + 2) {
		ret.push_back(str[i]);
	}
	for(int i = 1; i < str.size(); i = i + 2) {
		rev.push_back(str[i]);
	}
	reverse(rev.begin(), rev.end());
	return ret + rev;
}

int main() {
	cin >> x >> arr[0];
	for(int i = 1; i <= x; i++) {
		arr[i] = convert(arr[i - 1]);
		if(arr[i] == arr[0]) {
			cout << arr[x % i];
			cin >> x;
			return 0;
		}
	}
	cout << arr[x];
	cin >> x;

	return 0;
}