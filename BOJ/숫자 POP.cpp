#include <iostream>
#include <vector>
#include <algorithm>

// 32713번 숫자 POP

using namespace std;

struct node {
	int num, len;
};

int n, k, input, ans;
vector<node> v;

int main() {
	cin >> n >> k >> input;
	v.push_back({input, 1});
	for(int i = 1; i < n; i++) {
		cin >> input;
		if(v.back().num == input) v.back().len++;
		else v.push_back({input, 1});
	}
	for(int i = 0; i < v.size(); i++) {
		node now = v[i];
		int jump = 0;
		for(int j = i + 1; j < v.size() && jump <= k; j++) {
			if(v[j].num == now.num) now.len += v[j].len;
			else jump += v[j].len;
		}
		ans = max(ans, now.len);
	}
	cout << ans;
	cin >> n;

	return 0;
} 