#include <iostream>

// 14649번 문홍안 

using namespace std;

int p, n, input, arr[101], ans[3];
string str;

int main() {
	cout << fixed;
	cout.precision(2);
	cin >> p >> n;
	while(n--) {
		cin >> input >> str;
		if(str == "L") for(int i = input - 1; i > 0; i--) arr[i]++;
		else for(int i = input + 1; i <= 100; i++) arr[i]++;
	}
	for(int i = 1; i <= 100; i++) ans[arr[i] % 3]++;
	for(int i = 0; i < 3; i++) cout << double(p) * ans[i] / 100 << endl; // 계산 오류, / (ans[i] / 100) 이 아니고 * (ans[i] / 100) 임. 

	return 0;
}
