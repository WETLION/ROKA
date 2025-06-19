#include <iostream>
#include <vector>
#include <queue>

// 14284번 간선 이어가기 2 

using namespace std;

struct node {
	int num, len;
};

int n, m, a, b, c, s, t, map[5001];
vector<node> v[5001];
queue<node> q;

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	cin >> s >> t;
	q.push({s, 0});
	while(!q.empty()) {
		node now = q.front();
		q.pop();
		if(map[now.num] && map[now.num] <= now.len) continue;
		map[now.num] = now.len;
		for(node i: v[now.num]) q.push({i.num, i.len + now.len});
	}
	cout << map[t];

	return 0;
}
