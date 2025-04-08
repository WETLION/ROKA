#include <iostream>
#include <vector>
#include <algorithm>

// 14629번 숫자 조각

using namespace std;

struct node {
	long long num;
	int chk[10];
};

long long n;
vector<long long> v;

void make_v(node now, int cnt) {
	if(!cnt) {
		v.push_back(now.num);
		return;
	}
	for(int i = 0; i < 10; i++) {
		if(now.chk[i]) continue;
		node temp = now;
		temp.num = temp.num * 10 + i;
		temp.chk[i] = 1;
		make_v(temp, cnt - 1);
	}
}

int main() {
	cin >> n;
	for(int j = 0; j < 10; j++) {
		for(int i = 1; i < 10; i++) {
			node now = {i, {}};
			now.chk[i] = 1;
			make_v(now, j);
		}
	}
	auto iter = lower_bound(v.begin(), v.end(), n);
	if(iter == v.end()) cout << v.back();
	else if(*iter == n) cout << n;
	else if(n - *(iter - 1) <= *iter - n) cout << *(iter - 1); // 만약 차이가 같은 경우 작은 수 출력 
	else cout << *iter;

	return 0;
} 