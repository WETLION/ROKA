#include <iostream>
#include <algorithm>

// 11945번 뜨거운 붕어빵

using namespace std;

string str[100];
int n, m;

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> str[i];
		reverse(str[i].begin(), str[i].end());
	}
	for(int i = 0; i < n; i++) cout << str[i] << endl;

	return 0;
}