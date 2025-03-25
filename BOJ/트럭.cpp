#include <iostream>
#include <deque>

// 13335번 트럭

using namespace std;

struct node {
	int weight, len;
};

int n, w, l, a, ans;
deque<node> dq;

int main() {
	cin >> n >> w >> l;
	for(int i = 0; i < n; i++) {
		cin >> a;
		while(l < a) {
			int p = w - dq.front().len;
			l += dq.front().weight;
			dq.pop_front();
			if(p < 0) continue; // 만약 너무 많은 트럭이 지나갈만 해서 p가 음수가 되는 경우도 있을 수 있음. 
			ans += p;
			for(int i = 0; i < dq.size(); i++) dq[i].len += p;
//			cout << ans << " " << p << endl;
		}
		for(int i = 0; i < dq.size(); i++) dq[i].len++;
		dq.push_back({a, 1});
		l -= a;
		ans++;
//		cout << ans << endl;
	}
	cout << ans + w;
	cin >> n;

	return 0;
} 