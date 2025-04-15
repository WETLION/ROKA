#include <iostream>
#include <vector>
#include <algorithm>

// 22953번 도도의 음식 준비

using namespace std;

long long n, k, c, a;
vector<long long> vv;

long long make_cnt(long long num, vector<long long> v) { // num을 int로 받는 실수;; 
	long long ret = 0;
	for(long long i: v) ret += num / i;
	return ret;
}

long long make_sum(vector<long long> v) {
	sort(v.begin(), v.end());
	long long left = 0, right = v.front() * k, ret = 0;
	while(left <= right) { // left가 right랑 같을 때까지 비교해야 비로소 mid가 한 값으로 통일됨. 
		long long mid = (left + right) / 2;
		if(make_cnt(mid, v) >= k) {
			ret = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	return ret;
}

long long make_ans(long long cnt, vector<long long> v, int start) {
	if(!cnt || start == v.size()) return make_sum(v); // 만약 vector 범위를 초과한다면 반드시 결과를 도출해야함. 
	long long ans = -1;
	for(int i = start; i < n; i++) {
		for(int j = 1; j <= cnt; j++) {
			if(v[i] - j > 0) {
				v[i] -= j;
//				for(int k: v) cout << k << " ";
				long long ret = make_ans(cnt - j, v, i + 1);
//				cout << ret << endl;
				if(ans < 0) ans = ret;
				else ans = min(ans, ret);
				v[i] += j;
			}
			else { // 만약 모든 값이 1인데 빼야하는 값이 있다면?? 
				long long ret = make_ans(cnt, v, i + 1);
				if(ans < 0) ans = ret;
				else ans = min(ans, ret);
				break;
			}
		}
	}
	return ans;
}

int main() {
	cin >> n >> k >> c;
	for(int i = 0; i < n; i++) {
		cin >> a;
		vv.push_back(a);
	}
	cout << make_ans(c, vv, 0);
	cin >> n;

	return 0;
} 