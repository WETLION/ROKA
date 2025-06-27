#include <iostream>

// 28418번 회장님께 바치는 합성함수 

using namespace std;

int f[3], g[2], p[3], chk;

int main() {
	cin >> f[0] >> f[1] >> f[2] >> g[0] >> g[1];
	p[0] = f[0] * g[0] * g[0] - f[0] * g[0];
	p[1] = f[0] * 2 * g[0] * g[1] + f[1] * g[0] - f[1] * g[0];
	p[2] = f[0] * g[1] * g[1] + f[1] * g[1] + f[2] - f[2] * g[0] - g[1]; // 원래 다른 식이었다가 합치는 과정에서 - g[1]을 해줘야하는데 + g[1] 그대로 있었음. 
	if(!p[0]) {
		if(!p[1]) {
			if(p[2]) cout << "Head on";
			else cout << "Nice";
		}
		else cout << "Remember my character";
	}
	else {
		chk = p[1] * p[1] - 4 * p[0] * p[2];
		if(chk > 0) cout << "Go ahead";
		else if(chk < 0) cout << "Head on";
		else cout << "Remember my character";
	}

	return 0;
}
