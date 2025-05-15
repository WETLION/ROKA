#include <iostream>
#include <vector>
#include <algorithm>

// 24481번 알고리즘 수업 - 깊이 우선 탐색 3

using namespace std;

int n, m, r, a, b, ans[100001];
vector<int> v[100001];

void dfs(int now, int cnt) {
	ans[now] = cnt;
	for(int i: v[now]) {
		if(ans[i] < 0) dfs(i, cnt + 1);
	}
}

int main() {
	cin >> n >> m >> r;
	for(int i = 1; i <= n; i++) ans[i] = -1;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	} 
	for(int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());
	dfs(r, 0);
	for(int i = 1; i <= n; i++) cout << ans[i] << '\n';
	cin >> n;

	return 0;
} 