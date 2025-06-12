#include <iostream>
#include <algorithm>

// 21275번 폰 호석만

using namespace std;

string a, b, str = "0123456789abcdefghijklmnopqrstuvwxyz";
long long aa, bb, ans[3], am, bm;

int make_number(char now) {
	for(int i = 0; i < 36; i++) if(str[i] == now) return i;
}

int find_minimum_base(string now) {
	int ret = 2;
	for(char i: now) ret = max(ret, make_number(i) + 1);
	return ret;
}

long long change_dec(string num, int n) {
	__int128_t ret = 0;
	for(char i: num) {
		ret = ret * n + make_number(i);
		if(ret >= 9223372036854775807) return -1;
	}
	return ret;
}

int main() {
	cin >> a >> b;
	am = find_minimum_base(a); 
	bm = find_minimum_base(b);
//	cout << am << " " << bm << endl;
	for(int i = am; i <= 36; i++) {
		aa = change_dec(a, i);
		if(aa < 0) break;
		for(int j = bm; j <= 36; j++) {
			if(i == j) continue;
			bb = change_dec(b, j);
//			cout << aa << " " << bb << endl;
			if(bb < 0) break;
			if(aa == bb) {
				if(!ans[1]) {
					ans[0] = aa;
					ans[1] = i;
					ans[2] = j;
					continue; // 반드시 한번 같았다고 해서 다음 진법에서는 다르라는 보장이 없음.(한자리일 경우 무조건 같은 숫자이므로) 
				}
				else {
					cout << "Multiple";
					cin >> a;
					return 0;
				}
			}
		}
	}
	if(!ans[1]) cout << "Impossible";
	else cout << ans[0] << " " << ans[1] << " " << ans[2];
	cin >> a;

	return 0;
}