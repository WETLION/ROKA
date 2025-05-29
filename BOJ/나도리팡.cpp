#include <iostream>
#include <algorithm>

// 24508번 나도리팡 

using namespace std; 

int n, k, t, a[100000], f, b;

int main() {
	cin >> n >> k >> t;
	for(int i = 0; i < n; i++) cin >> a[i];
	b = n - 1;
	sort(a, a + n);
	while(t > 0 && f < b) {
		if(a[f] + a[b] >= k) {
			t -= k - a[b];
			a[f] -= k - a[b];
			a[b--] = 0;
			if(!a[f]) f++;

		}
		else {
			t -= a[f];
			a[b] += a[f];
			a[f++] = 0;
		}
	}
	if(a[f] || a[b] || t < 0) cout << "NO";
	else cout << "YES";

	return 0;
}
