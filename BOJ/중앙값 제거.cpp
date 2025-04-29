#include <cstdio>
#include <algorithm>
#include <cmath>

// 23758번 중앙값 제거

using namespace std;

int n, arr[2000000];
long long ans;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
	sort(arr, arr + n);
	for(int i = 0; i < (n + 1) / 2; i++) {
		if(arr[i] == 1) continue;
		ans += log2(arr[i]);
	}
	printf("%lld", ans + 1);
	scanf("%d", &n);

	return 0;
} 