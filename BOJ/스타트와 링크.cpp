#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

// 14889번 스타트와 링크

using namespace std;

int n, arr[20][20];

int make_sum(vector<int> v) {
	int ret = 0;
	for(int i = 0; i < n / 2; i++) {
		for(int j = i + 1; j < n / 2; j++) {
			ret += arr[v[i]][v[j]] + arr[v[j]][v[i]]; // vector에서 값을 불러와야하는데 그냥 i와 j를 사용함. 
		}
	}
	return ret;
}

int make_diff(vector<int> v) {
	int chk[20] = {};
	vector<int> cmp;
//	cout << "#";
	for(int i = 0; i < v.size(); i++) {
		chk[v[i]] = 1;
//		cout << v[i] << " ";
	}
//	cout << endl;
	for(int i = 0; i < n; i++) {
		if(!chk[i]) {
			cmp.push_back(i);
//			cout << i << " ";
		}
	}
//	cout << endl;
//	cout << make_sum(v) << " " << make_sum(cmp) << endl;
	return abs(make_sum(v) - make_sum(cmp));
}

int make_ans(int start, vector<int> v) {
	if(v.size() == n / 2) return make_diff(v);
	int ret = 1000000000;
	for(int i = start; i < n; i++) { // 숫자의 범위는 n 미만이나 20까지로 설정함. 
		v.push_back(i);
		ret = min(ret, make_ans(i + 1, v));
		v.pop_back();
	}
	return ret;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cout << make_ans(1, vector<int>(1, 0));
	cin >> n;

	return 0;
} 