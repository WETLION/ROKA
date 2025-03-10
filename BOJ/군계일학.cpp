#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>

// 15966번 군계일학 

using namespace std;

struct node {
	int num, location;
};

int n, arr[100010], cnt[100010], ans;
vector<node> v;

bool cmp(node a, node b) {
	return a.num == b.num ? a.location < b.location : a.num < b.num; // sort는 퀵정렬이므로 불안정 정렬됨. stable_sort를 쓰면 순서도 유지됨. 
}

node find_next(node now, int left, int right) {
	node ret = {0, -1};
	while(left <= right) {
		int mid = (left + right) / 2;
		if(v[mid].num == now.num) {
			if(v[mid].location < now.location) left = mid + 1;
			else if(v[mid].location > now.location) {
				right = mid - 1;
				if(ret.location != -1 && ret.location > v[mid].location || ret.location == -1) ret = v[mid];
			}
		}
		else if(v[mid].num < now.num) left = mid + 1;
		else right = mid - 1;
	}
	return ret;
}

void make_cnt(int num) {
	node now = {arr[num], num};
	int count = 1;
	deque<int> temp = {num};
	while(1) {
		now.num++;
		node next = find_next(now, 0, v.size() - 1);
		if(next.location == -1) break;
		if(cnt[next.location]) {
			count += cnt[next.location];
			break;
		}
		now = next;
		temp.push_back(next.location);
		count++;
		if(next.location == n - 1) break;
	}
	ans = max(ans, count);
	while(!temp.empty()) {
		cnt[temp.front()] = count--;
		temp.pop_front();
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		v.push_back({arr[i], i});
	}
	sort(v.begin(), v.end(), cmp);
	for(int i = 0; i < n; i++) {
		if(cnt[i]) continue;
		make_cnt(i);
	}
	cout << ans;
//	cin >> n;

	return 0;
}