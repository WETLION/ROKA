#include <cstdio> // cin cout 시간초과
#include <algorithm>

// 3943번 헤일스톤 수열

using namespace std;

int t, n, ans;

int main() {
	scanf("%d", &t); // t를 안받아버림
	while(t--) {
		scanf("%d", &n);
		ans = n;
		while(n > 1) {
			if(n % 2) n = n * 3 + 1;
			else n /= 2;
			ans = max(ans, n);
		}
		printf("%d\n", ans);
	}

	return 0;
}