#include <iostream>

// 32864번 지나칠 수 없는 지하철 게임

using namespace std;

int n, chk, win, now;
string ans[2] = {"mnx", "alsdkffhgk"};

int main() {
	cin >> n >> now;
	chk = 1;
	for(int i = 1; i < n; i++) {
		cin >> now;
		if(chk && now) win = !win;
		else chk = 0;
	}
	cout << ans[win];
	cin >> n;

	return 0;
}