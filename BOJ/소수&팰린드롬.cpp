#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// 1747번 소수&팰린드롬

using namespace std;

int n, chk[2000001];
vector<int> v;

bool palindrome(int num) {
	string str = to_string(num);
	for(int i = 0; i < str.size() / 2; i++) {
		if(str[i] != str[str.size() - i - 1]) return false;
	}
	return true;
}

int main() {
	v.push_back(2); // 2를 까먹고 안넣음.. 
	for(int i = 4; i <= 2000000; i = i + 2) chk[i] = 1;
	for(int i = 3; i < 2000000; i = i + 2) {
		if(chk[i]) continue;
		if(palindrome(i)) v.push_back(i);
		for(int j = i * 2; j < 2000000; j = j + i) chk[j] = 1;
	}
	cin >> n;
	cout << *(lower_bound(v.begin(), v.end(), n));
	cin >> n;

	return 0;
} 