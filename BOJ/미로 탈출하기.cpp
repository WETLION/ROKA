#include <cstdio> // cin cout 시간초과 
#include <vector>

// 17090번 미로 탈출하기 

using namespace std;

struct node {
	int x, y;
};

int n, m, map[500][500], arr[500][500], ans, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, chk[500][500];
char str[500];

int dfs(int y, int x) {
	vector<node> v;
	v.push_back({x, y});
	while(1) {
		node now = v.back();
		int point = map[now.y][now.x], xx = now.x + dx[point], yy = now.y + dy[point];
		if(0 > xx || xx >= m || 0 > yy || yy >= n || arr[yy][xx] > 0) {
			for(node i: v) arr[i.y][i.x] = 1;
			return 1;
		}
		else if(chk[yy][xx] || arr[yy][xx] < 0) {
			for(node i: v) arr[i.y][i.x] = -1;
			return 0;
		}
		else {
			v.push_back({xx, yy});
			chk[yy][xx] = 1;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf(" %s", &str);
		for(int j = 0; j < m; j++) {
			if(str[j] == 'R') map[i][j] = 0;
			else if(str[j] == 'L') map[i][j] = 1;
			else if(str[j] == 'D') map[i][j] = 2;
			else map[i][j] = 3;
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(arr[i][j] > 0) ans++;
			else if(!arr[i][j]) ans += dfs(i, j);
		}
	}
	printf("%d", ans);

	return 0;
} 