#include <iostream>
#include <deque>
#include <algorithm>
#include <queue>

// 30054번 웨이팅 

using namespace std;

struct node {
	int t1, t2;
};

int n, t1, t2, time, ans, visit[200001], line[200001];
deque<node> dq;
queue<node> q;

bool cmp(node a, node b) {
	return a.t2 == b.t2 ? a.t1 < b.t1 : a.t2 < b.t2;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> t1 >> t2;
		dq.push_back({t1, t2});
	}
	sort(dq.begin(), dq.end(), cmp);
	while(!dq.empty() || !q.empty()) {
		if(q.empty()) time = dq.front().t2;
		while(!dq.empty() && time >= dq.front().t2) {
			q.push(dq.front());
			line[dq.front().t1] = dq.front().t2;
			dq.pop_front();
		}
		if(time <= 200000 && line[time] && !visit[time]) { // time > 200000일 경우 out of bounds. 
//			cout << "time " << time << " " << line[time] << endl;
			ans = max(ans, time - line[time]);
			visit[time++] = 1; // time++ 이후 visit check 오류 
		}
		else {
			visit[q.front().t1] = 1;
//			cout << time << " " << q.front().t1 << " " << line[q.front().t1] << endl;
			ans = max(ans, time++ - line[q.front().t1]);
			q.pop();
		}
		while(!q.empty() && visit[q.front().t1]) q.pop();
	}
	cout << ans;

	return 0;
}
