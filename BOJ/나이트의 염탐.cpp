#include <iostream>
#include <queue>
#include <set>

// 11084번 나이트의 염탐 

using namespace std;

struct node {
	int x, y, cnt;
	bool operator < (const node &cmp) const {
		return x == cmp.x ? y > cmp.y : x > cmp.x;
	}
};

int r, c, chk[400][400], ans_cnt, dx[8] = {1, 2, -1, 2, 1, -2, -1, -2}, dy[8] = {2, 1, 2, -1, -2, 1, -2, -1}; // 되돌아 가는 경우가 빠른 경우가 있다???? 
long long map[400][400], ans;
queue<node> q;
set<node> s;

int main() {
	cin >> r >> c;
	r--;
	c--;
	if(!r && !c) {
		cout << 0 << " " << 1;
		cin >> r;
		return 0;
	}
	q.push({0, 0, 0});
	map[0][0] = 1;
	chk[0][0] = 1;
	while(!q.empty()) {
		while(!q.empty()) {
			node now = q.front();
			q.pop();
			for(int i = 0; i < 8; i++) {
				int xx = now.x + dx[i], yy = now.y + dy[i];
//				cout << yy << " " << xx << endl;
				if(0 <= xx && xx <= r && 0 <= yy && yy <= c && !chk[yy][xx]) {
					if(xx == r && yy == c) { // 끄트머리에 붙는 경우를 고려하기 위해 안에 있어야함. 
						ans += map[now.y][now.x]; // 덧셈 오류; 원 위치에서 받아와야 하는데 xx, yy 에서 받아옴
						ans %= 1000000009; // 나머지 숫자 오타 
						ans_cnt = now.cnt + 1;
						continue;
					}
					map[yy][xx] += map[now.y][now.x];
					map[yy][xx] %= 1000000009; // 나머지 숫자 오타 
					s.insert({xx, yy, now.cnt + 1});
				}
			}
		}
		if(!ans_cnt) {
			for(node i: s) {
				q.push(i);
				chk[i.y][i.x] = 1;
	//			cout << i.y << " " << i.x << " " << i.cnt << endl;
			}
			s.clear();
		}
	}
	if(!ans_cnt) cout << "None";
	else cout << ans_cnt << " " << ans;
	cin >> r;

	return 0;
} 