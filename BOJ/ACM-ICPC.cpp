#include <iostream>
#include <algorithm>

// 11946번 ACM-ICPC 

using namespace std;

struct node {
	int solve, time, num;
};

int n, m, q, t, num, p, time[101][20], chk[101][20];
string str;
node arr[101];

bool cmp(node a, node b) {
	return a.solve == b.solve ? a.time < b.time : a.solve > b.solve;
}

int main() {
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++) arr[i].num = i;
	while(q--) {
		cin >> t >> num >> p >> str;
		if(str == "AC" && !chk[num][p]) {
			chk[num][p] = 1;
			arr[num].solve++;
			arr[num].time += time[num][p] * 20 + t;
		}
		else time[num][p]++;
	}
	stable_sort(arr + 1, arr + n + 1, cmp); // 병합 정렬 미사용 
	for(int i = 1; i <= n; i++) {
		cout << arr[i].num << " " << arr[i].solve << " " << arr[i].time << endl;
	}
	cin >> n;

	return 0;
}