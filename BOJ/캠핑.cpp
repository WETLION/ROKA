#include <iostream>

// 4796번 캠핌

using namespace std;

int l, p, v;

int main() {
	for(int i = 1; ; i++) {
		cin >> l >> p >> v;
		if(!l && !p && !v) break;
		cout << "Case " << i << ": " << l * (v / p) + (v % p <= l ? v % p : l) << endl;
	}

	return 0;
} 