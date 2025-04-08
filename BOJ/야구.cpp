#include <iostream>
#include <cstdio>
#include <algorithm>

// 32195번 야구

using namespace std;

long long n, q, x, y, r[300000], input, a, b, cnt;

int main() {
	scanf("%lld", &n);
	for(int i = 0; i < n; i++) {
		scanf("%lld%lld", &x, &y);
		if(x >= 0 && y >= 0 && x <= y || x <= 0 && y >= 0 && -x <= y) r[cnt++] = x * x + y * y; // y축이 커지는 방향으로 부채꼴이므로.. x가 음수이고 y가 양수여야함. 
		else a++;
	}
	sort(r, r + cnt);
	scanf("%lld", &q);
	while(q--) {
		scanf("%lld", &input);
		input *= input;
		b = upper_bound(r, r + cnt, input) - r;
		printf("%lld %lld %lld\n", a, b, n - b - a);
	}

	return 0;
} 