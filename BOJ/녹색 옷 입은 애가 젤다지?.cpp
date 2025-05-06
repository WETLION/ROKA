#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

// 4485번 녹색 옷 입은 애가 젤다지?

using namespace std;

struct node {
	int x, y, sum;
};

struct cmp {
	bool operator() (const node &a, const node &b) {
		return a.sum > b.sum;
	}
};

int n, map[130][130], arr[130][130], dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main() {
	for(int k = 1; ; k++) {
		cin >> n;
		if(!n) break;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> map[i][j];
				arr[i][j] = -1;
			}
		}
		priority_queue<node, vector<node>, cmp> pq;
		pq.push({0, 0, map[0][0]});
		while(!pq.empty()) {
			node now = pq.top();
			pq.pop();
			for(int i = 0; i < 4; i++) {
				int xx = now.x + dx[i], yy = now.y + dy[i];
				if(xx >= 0 && yy >= 0 && xx < n && yy < n && (arr[yy][xx] == -1 || arr[yy][xx] > now.sum + map[yy][xx])) pq.push({xx, yy, arr[yy][xx] = now.sum + map[yy][xx]});
			}
		}
		cout << "Problem " << k << ": " << arr[n - 1][n - 1] << endl;
	}

	return 0;
} 