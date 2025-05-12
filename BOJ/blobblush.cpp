#include <iostream>
#include <cmath>

// 24500번 blobblush 

using namespace std;

long long n, k, chk, cnt;

int main() {
	cin >> n;
	k = n;
	while(k) {
		if(!(k & 1)) chk = 1;
		k >>= 1;
		cnt++;
	}
	if(chk) cout << 2 << endl << (n ^ (long long)(pow(2, cnt)) - 1) << " " << n;
	else cout << 1 << endl << n;

	cin >> n;

	return 0;
}