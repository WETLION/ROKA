#include <cstdio>
#include <vector>

// 17241번 Pineapple Advertising

using namespace std;

int n, m, q, a, b, chk[200001];
vector<int> v[200001];

int main() {
	scanf("%d%d%d", &n, &m, &q);
	while(m--) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	while(q--) {
		scanf("%d", &a);
		int cnt = !(chk[a]);
		chk[a] = 1;
		for(int i: v[a]) {
			if(chk[i]) continue;
			cnt++;
			chk[i] = 1;
		}
		v[a].clear(); // 이미 배달한 곳은 다시 들려도 결과가 같으므로 필요 없음. 
		printf("%d\n", cnt);
	}

	return 0;
}