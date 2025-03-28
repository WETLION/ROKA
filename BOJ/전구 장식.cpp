#include <iostream>
#include <algorithm>

// 5527번 전구 장식

using namespace std;

int n, arr[100000], cnt[100005], rev[100005], chk[100000], ans;

int main() {
	cin >> n >> arr[0];
	rev[1] = 1;
	for(int i = 1; i < n; i++) {
		cin >> arr[i];
		if(arr[i - 1] != arr[i]) rev[i + 1] = rev[i] + 1;
		else rev[i + 1] = 1;
	}
	cnt[n] = 1;
	for(int i = n - 1; i > 0; i--) {
		if(arr[i] != arr[i - 1]) cnt[i] = cnt[i + 1] + 1;
		else cnt[i] = 1;
		ans = max(ans, cnt[i]);
	}
//	cout << ans << endl;
//	for(int i = 0; i <= n + 1; i++) {
//		cout << rev[i] << " " << cnt[i] << endl;
//	}
	for(int i = 0; i < n; i++) {
		if(chk[i]) continue;
		int j;
		for(j = i + 1; j < n; j++) {
			if(arr[j - 1] != arr[j]) chk[j] = 1;
			else break;
		}
//		cout << i << " " << j << " " << rev[i] << " " << cnt[j + 1] << endl;
		ans = max(ans, j - i + cnt[j + 1] + (i && arr[i] == arr[i - 1] ? rev[i] : 0));
	}
	cout << ans;
	cin >> n;

	return 0;
} 