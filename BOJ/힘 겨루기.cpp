#include <iostream>

// 17251번 힘 겨루기 

using namespace std;

int n, r, b, arr[1000000], cmp_l[1000000], cmp_r[1000000];

int main() {
	cin >> n >> arr[0];
	cmp_l[0] = arr[0];
	for(int i = 1; i < n; i++) {
		cin >> arr[i];
		if(cmp_l[i - 1] < arr[i]) cmp_l[i] = arr[i];
		else cmp_l[i] = cmp_l[i - 1];
	}
	cmp_r[n - 1] = arr[n - 1];
	for(int i = n - 2; i >= 0; i--) {
		if(cmp_r[i + 1] < arr[i]) cmp_r[i] = arr[i];
		else cmp_r[i] = cmp_r[i + 1];
	}
	for(int i = 1; i < n; i++) {
		if(cmp_l[i - 1] < cmp_r[i]) b++;
		else if(cmp_l[i - 1] > cmp_r[i]) r++;
	}
	if(r > b) cout << 'R';
	else if(r < b) cout << 'B';
	else cout << 'X';

	return 0;
} 