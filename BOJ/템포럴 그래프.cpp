#include <cstdio> // cin cout 시간초과 해결
#include <algorithm>

// 25953번 템포럴 그래프

using namespace std;

int n, t, m, s, e, a, b, w, arr[10001][1001];

int main() {
	scanf("%d%d%d%d%d", &n, &t, &m, &s, &e);
	for(int i = 0; i < n; i++) arr[i][0] = -1;
	arr[s][0] = 0;
	for(int i = 1; i <= t; i++) {
		for(int ii = 0; ii < n; ii++) arr[ii][i] = arr[ii][i - 1]; // 과거 값을 현재로 가져오지 않으면 현재 값이 없어지게 되므로 복사해야함.
		for(int ii = 0; ii < m; ii++) {
			scanf("%d%d%d", &a, &b, &w);
			if(arr[a][i - 1] < 0 && arr[b][i - 1] < 0) continue;
			if(arr[a][i - 1] < 0) arr[a][i] = arr[b][i - 1] + w;
			else if(arr[b][i - 1] < 0) arr[b][i] = arr[a][i - 1] + w;
			else if(arr[a][i - 1] < arr[b][i - 1]) arr[b][i] = min(arr[b][i], arr[a][i - 1] + w); // 현재 값과 비교하며 계속 최신화 해줘야함
			else if(arr[a][i - 1] > arr[b][i - 1]) arr[a][i] = min(arr[a][i], arr[b][i - 1] + w);
//			cout << a << " " << b << " " << arr[a][i - 1] << " " << arr[b][i - 1] << " " << arr[a][i] << " " << arr[b][i] << endl;
		}
	}
	printf("%d", arr[e][t]);
	scanf("%d", &n);

	return 0;
} 