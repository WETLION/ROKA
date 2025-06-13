#include <iostream>

// 10252번 그리드 그래프 

using namespace std;

int t, n, m; 

void print(int i, int j) {
	cout << '(' << i << ',' << j << ")\n";
}

int main() {
	cin >> t;
		while(t--) {
		cin >> n >> m;
		cout << 1 << endl;
		if(n % 2) {
			int i = 0;
			if(m % 2) {
				for(int j = 0; j < m; j++) {
					if(j % 2) print(i--, j);
					else print(i++, j);
					print(i, j);
				}
				for(i = 2; i < n; i++) {
					if(i % 2) for(int j = 0; j < m; j++) print(i, j);
					else for(int j = m - 1; j >= 0; j--) print(i, j);
				}
			}
			else {
				print(0, 0);
				for(int j = 1; j < m; j++) {
					if(j % 2) print(i++, j);
					else print(i--, j);
					print(i, j);
				}
				for(i = 2; i < n; i++) {
					if(i % 2) for(int j = 1; j < m; j++) print(i, j);
					else for(int j = m - 1; j > 0; j--) print(i, j);
				}
				for(i = n - 1; i > 0; i--) print(i, 0);
			}
		}
		else {
			for(int i = 0; i < n; i++) {
				if(i % 2) for(int j = m - 1; j >= 0; j--) print(i, j);
				else for(int j = 0; j < m; j++) print(i, j);
			}
		}
	}
	cin >> n;

	return 0;
}