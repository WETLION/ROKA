#include <iostream>

// 31566번 힘세고 강한 아침 

using namespace std;

int n, m, q, b, t, c, s, k, e, arr[101][101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) for(int l = 1; l <= n; l++) arr[i][j][l] = 10000000;
	while(m--) {
		cin >> b >> t >> c;
		for(int i = 1; i <= n; i++) {
			if(i == b || i == t) continue;
			arr[b][i][t] = c;
		}
	}
	for(int i = 1; i <= n; i++) { // 결국 플로이드-워셜이 답이었다.. 
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			for(int l = 1; l <= n; l++) {
				if(i == l) continue;
				for(int o = 1; o <= n; o++) {
					if(i == o) continue;
					if(arr[l][i][o] > arr[l][i][j] + arr[j][i][o]) arr[l][i][o] = arr[l][i][j] + arr[j][i][o];
				}
			}
		}
	}
	while(q--) {
		cin >> s >> k >> e;
		if(arr[s][k][e] != 10000000) cout << arr[s][k][e] << '\n';
		else cout << "No\n";
	}

	return 0;
}
