#include <iostream>
#include <string>
#include <vector>

// 13140번 Hello World!

using namespace std;

long long n, u, d, arr[5] = {1, 10, 100, 1000, 10000};

bool cmp_b(int num, int cnt, vector<int> v, int f) {
	if(cnt < 0) {
		if(num + f == n) {
			u = f;
			d = num;
			return true;
		}
		return false;
	}
	if(cnt == 1 || cnt == 3) {
		if(cmp_b(num, cnt - 1, v, f)) return true;
		return false;
	}
	for(int i = 0; i < 10; i++) {
		if(cnt == 4 && !i || v[i]) continue;
		num += i * arr[cnt];
		v[i] = 1;
		if(cmp_b(num, cnt - 1, v, f)) return true;
		num -= i * arr[cnt];
		v[i] = 0;
	}
	return false;
}

bool isit_true(int num, int cnt, vector<int> v, int b) {
	if(cnt < 0) {
		if(cmp_b(b, 4, v, num)) return true;
		return false;
	}
	for(int i = 0; i < 10; i++) {
		if(cnt == 4 && !i || v[i]) continue;
		if(cnt != 1) {
			num += i * arr[cnt];
			v[i] = 1;
		}
		if(cnt == 2) {
			b += i * arr[1];
			num += i * arr[1];
		}
		if(cnt == 0) {
			b += i * arr[3];
		}
		if(isit_true(num, cnt - 1, v, b)) return true;
		if(cnt != 1) {
			num -= i * arr[cnt];
			v[i] = 0;
		}
		if(cnt == 2) {
			b -= i * arr[1];
			num -= i * arr[1];
		}
		if(cnt == 0) {
			b -= i * arr[3];
		}
	}

	return false;
}

string make_ans(int a, int b) {
	return "  " + to_string(a) + '\n' + "+ " + to_string(b) + '\n' + "-------\n " + (a + b < 100000 ? " " : "") + to_string(a + b); // 만약 6자리 수일 경우 띄어쓰기 하나가 적어야함.
}

int main() {
	cin >> n;
	cout << (isit_true(0, 4, vector<int>(10), 0) ? make_ans(u, d) : "No Answer");

	return 0;
}