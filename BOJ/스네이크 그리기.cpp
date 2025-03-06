#include <iostream>

// 27513번 스네이크 그리기

using namespace std;

int n, m, x, y, way;

int main() {
	cin >> n >> m;
	cout << n * m - (n % 2 && m % 2) << endl;
	for(int i = 1; i <= n; i++) cout << i << " " << 1 << endl;
	for(int i = n; i > 0; i--) {
		if(way) for(int j = m; j > 1; j--) cout << i << " " << j << endl;
		else {
			for(int j = 2; j <= m; j++) cout << i << " " << j << endl;
			if(i == 3 && m != 2) { // 세로가 2인 경우는 따로 배제해야함. 
				for(int j = m; j > 2 - !(m % 2); j--) { // 만약 가로만 홀수고 세로가 짝수인 경우를 배제해야함. 
					cout << 1 + !way << " " << j << endl << 1 + way << " " << j << endl;
					way = !way;
				}
				if(m % 2) cout << 1 << " " << 2 << endl; // 만약 가로만 홀수고 세로가 짝수인 경우를 배제해야함. 
				break;
			}
		}
		way = !way;
	}
	cin >> n;

	return 0;
} 