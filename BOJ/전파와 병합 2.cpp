#include <iostream>
#include <vector>
#include <queue>

// 23302번 전파와 병합 2 

using namespace std;

struct node {
	int r, c;
	node(string str, int a, int b) {
		r = c = 0;
		for(int i = a; i < b; i++) {
			if('A' <= str[i] && str[i] <= 'Z') c = c * 26 + str[i] - 'A' + 1;
			else r = r * 10 + str[i] - '0';
		}
		r--; // 헹은 A가 0 포지션이지만 열은 1이 0포지션이므로 1을 깎아야함.
		c--; // AA와 같은 상황을 해결하기 위해 강제로 1을 더해줬으므로 빼줘야함. 
	}
	node(int a, int b) {
		r = a;
		c = b;
	}
};

int r, c, cnt[1000][1000], ans;
string str;
vector<node> v[1000][1000];
queue<node> q;

int main() {
	cin >> r >> c;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cin >> str;
			if(str == ".") continue;
			for(int k = 0; k < str.size(); k++) {
				if(str[k] == '+') {
					v[i][j].push_back(node(str, 0, k));
					cnt[v[i][j].back().r][v[i][j].back().c]++;
					v[i][j].push_back(node(str, k + 1, str.size()));
					cnt[v[i][j].back().r][v[i][j].back().c]++;
					ans += 2;
					break; 
				}
				if(k == str.size() - 1) {
					v[i][j].push_back(node(str, 0, str.size()));
					cnt[v[i][j].back().r][v[i][j].back().c]++;
					ans++;
				}
			}
		}
	}
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(!cnt[i][j] && v[i][j].size()) q.push({i, j});
		}
	}
	while(!q.empty()) {
		node now = q.front();
		q.pop();
		ans -= v[now.r][now.c].size();
		for(node i: v[now.r][now.c]) if(!--cnt[i.r][i.c]) q.push(i);
	}
	cout << (ans ? "yes" : "no");

	return 0;
}
