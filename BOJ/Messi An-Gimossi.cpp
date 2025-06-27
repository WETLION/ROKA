#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>

// 17355번 Messi An-Gimossi

using namespace std;

long long n, a, b, arr[10000], cnt[10000][2], ans[2] = {1, 1};
vector<int> prime;
deque<int> dq[2];

void split_prime(int num, int now) {
	for(int i: prime) {
//		cout << num << " " << i << endl;
		while(!(num % i)) {
//			cout << num << " " << i << endl;
			cnt[i][now]++;
			num /= i;
		}
	}
	if(num) dq[now].push_back(num);
}

int main() {
	prime.push_back(2);
	for(int i = 4; i < 10000; i = i + 2) arr[i] = 1;
	for(int i = 3; i < 10000; i = i + 2) {
		if(arr[i]) continue;
		prime.push_back(i);
		for(int j = i * 2; j < 10000; j = j + i) arr[j] = 1;
	}
//	for(int i: prime) cout << i << endl;
	cin >> n;
	while(n--) {
		cin >> a >> b;
		split_prime(b - a, 0);
		split_prime(b, 1);
	}
	for(int i = 0; i < 2; i++) sort(dq[i].begin(), dq[i].end());
	for(int i: prime) {
		int m = min(cnt[i][0], cnt[i][1]);
		for(int j = 0; j < 2; j++) {
			cnt[i][j] -= m;
			for(int k = 0; k < cnt[i][j]; k++) ans[j] = ans[j] * i % 1000000007;
		}
	}
	while(!dq[0].empty() && !dq[1].empty()) {
		if(dq[0].front() == dq[1].front()) {
			dq[0].pop_front();
			dq[1].pop_front();
			continue;
		}
		else {
			int chk = dq[0].front() > dq[1].front();
			ans[chk] = ans[chk] * dq[chk].front() % 1000000007;
			dq[chk].pop_front();
		}
	}
	for(int i = 0; i < 2; i++) for(int j: dq[i]) ans[i] = ans[i] * j % 1000000007;
	cout << ans[0] << " " << ans[1];

	return 0;
}
