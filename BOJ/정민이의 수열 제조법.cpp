#include <cstdio>
#include <vector>
#include <algorithm>

// 32643번 정민이의 수열 제조법 

using namespace std;

int n, m, a, b, chk[5000001];
vector<int> v;

int main() {
	v.push_back(1);
	v.push_back(2);
	for(int i = 4; i <= 5000000; i = i + 2) chk[i] = 1;
	for(int i = 3; i <= 5000000; i = i + 2) {
		if(chk[i]) continue;
		v.push_back(i);
		for(int j = i * 2; j <= 5000000; j = j + i) chk[j] = 1;
	}
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		printf("%d\n", (upper_bound(v.begin(), v.end(), b) - v.begin()) - (lower_bound(v.begin(), v.end(), a) - v.begin()));
	}
//	cin >> n;

	return 0;
}