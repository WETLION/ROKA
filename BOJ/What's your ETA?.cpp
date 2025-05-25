#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

// 30974번 What's your ETA?

using namespace std;

struct node {
	int dest;
	long long dist;
};

struct cmp {
	bool operator() (const node &a, const node &b) {
		return a.dist > b.dist; // 오름차순 방향 오류 
	}
};

int n, m, prime[10000001], d[400001], u, v, w;
long long len[400001];
vector<node> road[400001];
priority_queue<node, vector<node>, cmp> pq;

int main() {
	prime[0] = prime[1] = 1;
	for(int i = 4; i <= 10000000; i = i + 2) prime[i] = 1;
	for(int i = 3; i <= 10000000; i = i + 2) {
		if(prime[i]) continue;
		for(int j = i * 2; j <= 10000000; j = j + i) prime[j] = 1; // 소수 판별 오류 
	}
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &d[i]);
	for(int i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &w); // %d를 %%d로 적는 오타 
		if(prime[d[u] + d[v]]) continue;
//		printf("%d %d %d\n", u, v, w);
		road[u].push_back({v, w});
		road[v].push_back({u, w});
	}
	pq.push({1, 0});
	while(!pq.empty()) {
		node now = pq.top();
		pq.pop();
//		printf("%d %d\n", now.dest, now.dist);
		if(len[now.dest] < now.dist) continue;
		for(node i: road[now.dest]) {
			if(!len[i.dest] || len[i.dest] > now.dist + i.dist) pq.push({i.dest, len[i.dest] = now.dist + i.dist});
		}
	}
	if(len[n]) printf("%lld", len[n]);
	else printf("Now where are you?");
	scanf("%d", &n);

	return 0;
} 