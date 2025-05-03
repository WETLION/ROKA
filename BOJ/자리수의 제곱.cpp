#include <iostream>
#include <unordered_map>
#include <cmath>
#include <algorithm>

// 4881번 자리수의 제곱

using namespace std;

long long a, b, aa, bb, ans;

long long make_pow(long long n) {
	long long ret = 0;
	while(n) {
		ret += pow(n % 10, 2);
		n /= 10;
	}
	return ret;
}

int main() {
	while(1) {
		cin >> a >> b;
		if(!a && !b) break;
		unordered_map<long long, long long> sa, sb;
		aa = a;
		bb = b;
		ans = 0;
		for(int i = 1; ; i++) {
			if(sa.find(aa) != sa.end()) break;
			sa.insert({aa, i});
			aa = make_pow(aa);
//			cout << "@" << aa << " " << i << endl;
		}
		for(int i = 1; ; i++) {
			if(sa.find(bb) != sa.end()) { // 처음 만나는 sa의 값이 반드시 최솟값이 아닐 수 있음. 
				if(!ans) ans = sa[bb] + i;
				else ans = min(ans, sa[bb] + i);
			}
			if(sb.find(bb) != sb.end()) break;// b -> bb 오류
			sb.insert({bb, i});
			bb = make_pow(bb);
//			cout << "#" << bb << " " << i << endl;
		}
		cout << a << " " << b << " " << ans << endl;
	}

	return 0;
} 