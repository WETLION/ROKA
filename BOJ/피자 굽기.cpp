#include <cstdio>
#include <algorithm>

// 1756번 피자 굽기

using namespace std;

int d, n, input, top, arr[300001], m[300001], ans;

bool isit_over(int num) {
	for(int i = d - top; i >= 0; --i) {
		if(m[i] >= num) {
//			printf("#%d\n", i);
			top = d - i + 1;
			ans = i + 1;
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d%d", &d, &n);
	scanf("%d", &arr[0]);
	m[0] = arr[0];
	for(int i = 1; i < d; i++) {
		scanf("%d", &arr[i]);
		m[i] = min(m[i - 1], arr[i]); // 일종의 누적합 이용 
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &input);
		if(isit_over(input)) {
			printf("0");
			return 0;
		}
//		printf("%d\n", top);
	}
	printf("%d", ans);
	scanf("%d", &n);

	return 0;
} 