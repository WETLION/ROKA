#include <cstdio>

// 33466번 피타고라스 정리의 증명 

using namespace std;

long long t, n;

int main() {
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld", &n);
		printf("%lld\n", n % 2 ? (n - 1) * 2 + 1 : n * 2);
	}

	return 0;
}
