#include <iostream>

// 18129번 이상한 암호코드 

using namespace std;

string str, ans;
int k, arr[30], start;

int main() {
	cin >> str >> k;
	for(int i = 0; i < str.size(); i++) if(str[i] < 'a') str[i] += 32;
	for(int i = 1; i < str.size(); i++) {
		if(str[i - 1] != str[i]) {
			if(!arr[str[i - 1] - 'a']) ans.push_back(i - start < k ? '0' : '1');
			start = i;
			arr[str[i - 1] - 'a'] = 1;
		}
	}
	if(!arr[str.back() - 'a']) ans.push_back(str.size() - start < k ? '0' : '1');
	cout << ans;

	return 0;
}
