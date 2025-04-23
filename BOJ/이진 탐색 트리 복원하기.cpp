#include <iostream>
#include <deque>

// 18240번 이진 탐색 트리 복원하기

using namespace std;

int n, a, size[300000] = {1, 2}, ans[300000], now;
deque<int> v[300001];

void make_ans(int num) {
	if(v[num + 1].empty()) { // ??? 최댓값 비교 대신 다음이 비어있다면 안하기로 하니까 통과함 
		ans[v[num].front()] = ++now;
		v[num].pop_front();
		return;
	}
	make_ans(num + 1);
	ans[v[num].front()] = ++now;
	v[num].pop_front();
	if(v[num + 1].size()) make_ans(num + 1);
}

int main() {
	cin >> n;
	v[0].push_back(0);
	for(int i = 1; i < n; i++) {
		cin >> a;
		v[a].push_back(i);
		if(v[a].size() > size[a]) {
			cout << -1;
			return 0;
		}
		size[a + 1] += 2;
	}
	make_ans(0);
	for(int i = 0; i < n; i++) cout << ans[i] << " ";
	cin >> n;

	return 0;
} 