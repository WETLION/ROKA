#include <iostream>
#include <queue>

// 21938번 영상처리 

using namespace std;

struct node {
	int x, y;
};

int n, m, t, ans, sum[1000][1000], input, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
queue<node> q;

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			for(int k = 0; k < 3; k++) {
				cin >> input;
				sum[i][j] += input;
			}
		}
	}
	cin >> t;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			sum[i][j] = sum[i][j] / 3 >= t;
		}
	}
	// 인접 부분은 동일 도형 인식 부분 안만듬
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) { // m을 n으로 적음
			if(sum[i][j]) {
				ans++;
				sum[i][j] = 0;
				q.push({j, i});
				while(!q.empty()) {
					node now = q.front();
					q.pop();
					for(int k = 0; k < 4; k++) {
						int xx = now.x + dx[k], yy = now.y + dy[k];
						if(xx >= 0 && yy >= 0 && xx < m && yy < n && sum[yy][xx]) { // n, m 범위 틀림
							sum[yy][xx] = 0;
							q.push({xx, yy});
						}
					}
				}
			}
		}
	}
	cout << ans;
	cin >> n; 

	return 0;
}