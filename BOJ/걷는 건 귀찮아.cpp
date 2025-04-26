#include <iostream>
#include <queue>
#include <algorithm>

// 20928번 걷는 건 귀찮아 

using namespace std;

struct node {
	int len, cnt;
};

int n, m, p[100001], x[100001], chk[100001], ans = -1, start, fin; 
queue<node> q;

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> p[i];
	for(int i = 0; i < n; i++) cin >> x[i];
	q.push({p[0] + x[0], 0});
	while(!q.empty()) {
		node now = q.front();
		q.pop();
		if(now.len >= m) {
			ans = now.cnt;
			break;
		}
		fin = upper_bound(p, p + n, now.len) - p;
		if(chk[fin]) continue;
		for(int i = start; i < fin; i++) q.push({p[i] + x[i], chk[i] = now.cnt + 1}); // chk[i] = 1로 넣어버리니 무조건 환승 횟수가 1로 잡혀버림. 
		start = fin;
	}
	cout << ans;
	cin >> n;

	return 0;
} 