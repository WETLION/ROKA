#include <iostream>

// 33497번 저녁 태권도 

using namespace std;

int n, m, a, b, cnt;
string ans[100];

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		int chk[1000] = {};
		for(int j = 0; j < n - a - b && cnt < n; j++) {
			chk[cnt] = 1;
			ans[cnt++].push_back('X');
		}
		if(a + b > n || m - 1 == i && cnt < n) { // 모든 학생이 반드시 종이 카드를 사용해야함. 
			cout << "NO";
			return 0;
		}
		for(int j = 0; j < a; j++) {
			if(chk[j]) {
				a++;
				continue;
			}
			ans[j].push_back('+');
		}
		for(int j = a; j < n; j++) {
			if(chk[j]) continue;
			ans[j].push_back('-');
		}
	}
	cout << "YES" << endl;
	for(int i = 0; i < n; i++) cout << ans[i] << endl;
	cin >> n;

	return 0;
} 