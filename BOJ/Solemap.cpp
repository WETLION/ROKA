#include <cstdio>

// 32114번 Solemap 

using namespace std;

struct node {
	int a, b, car;
};

long long n, m, w[500000], vi, vj, x, sum[500001], fin[500001], now; // 10^9의 제곱까지 가능하므로 long long을 이용해야함. 

long long powll(long long x, long long y) { // cmath의 pow는 double 형이므로 오차가 발생할수 있음. 따라서 함수를 제작해야함. 
	long long ret = 1;
	while(y--) ret *= x;
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i < n; i++) scanf("%d", &w[i]);
	for(int i = 0; i < m; i++) {
		scanf("%d%d%d", &vi, &vj, &x);
		sum[vi] += x;
		fin[vj] += x;
	}
	for(int i = 1; i < n; i++) {
		now += sum[i] - fin[i];
		printf("%lld\n", powll(now / w[i] + 1, 2) * (now % w[i]) + powll(now / w[i], 2) * (w[i] - now % w[i]));
	}

	return 0;
}
