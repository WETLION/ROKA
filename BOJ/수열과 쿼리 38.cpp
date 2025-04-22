#include <cstdio>

// 18917번 수열과 쿼리 38 

using namespace std;

long long m, a, x, sum, xo;

int main() {
	scanf("%lld", &m);
	while(m--) {
		scanf("%lld", &a);
		if(a < 3) {
			scanf("%lld", &x);
			if(a == 1) sum += x;
			else sum -= x;
			xo ^= x;
		}
		else if(a == 3) printf("%lld\n", sum);
		else printf("%lld\n", xo);
	}

	return 0;
}