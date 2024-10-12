#include <iostream>
#include <cmath>

// 17205번 진우의 비밀번호 

using namespace std;

int n;
long long ans;
string str;

int main() {
	cin >> n >> str;
	for(char i: str) {
		long long sum = 0;
		for(int j = n - 1; j >= 0; j--) {
			sum += pow(26, j);
		}
		ans += sum * (i - 'a') + 1;
		n--;
	}
	cout << ans;
	
	return 0;
}
