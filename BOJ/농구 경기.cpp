#include <iostream>

// 1159번 농구 경기

using namespace std;

int n, arr[30], chk;
string input;

int main() {
	cin >> n;
	while(n--) {
		cin >> input;
		arr[input[0] - 'a']++;
	}
	for(int i = 0; i < 26; i++) {
		if(arr[i] >= 5) {
			cout << (char)('a' + i);
			chk = 1;
		}
	}
	if(!chk) cout << "PREDAJA";
	
	return 0;
}
