#include <iostream>
#include <algorithm>
#include <set>
#include <deque>

// 15823번 카드 팩 구매하기

using namespace std;

int n, m, arr[100000], len[100000], f, m_l;
set<int> s;
deque<int> dq;

bool count_len(int mid) { // 겹치는 경우를 제외하기 위해 점프하는 구간 추가 
	int ret = 0;
	for(int i = 0; i < n; i++) {
		if(len[i] >= mid) {
			i += mid - 1;
			ret++;
		}
	}
	return ret >= m;
}

int find_ans(int l, int r) {
	int ret = 0, mid;
	while(l <= r) {
		mid = (l + r) / 2;
		if(count_len(mid)) {
			ret = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ret;
}

int main() {
	cin >> n >> m >> arr[0];
	s.insert(arr[0]);
	dq.push_back(arr[0]);
	for(int i = 1; i < n; i++) {
		cin >> arr[i];
		if(s.find(arr[i]) != s.end()) {
			while(1) {
				len[f++] = dq.size();
				m_l = max(m_l, int(dq.size()));
//				cout << i << " " << cnt << " " << dq.front() << endl;
				if(dq.front() == arr[i]) break;
				s.erase(dq.front());
				dq.pop_front();
			}
			dq.pop_front();
		}
		s.insert(arr[i]);
		dq.push_back(arr[i]);
//		for(int j: dq) cout << j << " ";
//		cout << endl;
	}
	while(f < n) {
//		cout << cnt << endl;
		len[f++] = dq.size();
		m_l = max(m_l, int(dq.size())); // 마지막에 가장 클 경우 m_l을 수정해줘야함. 
		dq.pop_front();
	}
//	for(int i = 0; i < n; i++) {
//		cout << len[i] << " ";
//	}
//	cout << endl;
	cout << find_ans(1, m_l); // 가능한 갯수에 대해 이분탐색 
	cin >> n;

	return 0;
}