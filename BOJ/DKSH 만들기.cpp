#include <iostream>

// 29766번 DKSH 찾기 

using namespace std;

string str, cmp = "KSH";
int ans;

int main() {
	cin >> str;
	for(int i = 0; i < str.size();) {
		if(str[i] == 'D') {
			ans++;
			for(int j = 0; j < 3; j++) {
				if(++i == str.size() || str[i] != cmp[j]) {
					ans--;
					break;
				}
			}
		}
		else i++;
	}
	cout << ans;
	cin >> str;

	return 0;
}