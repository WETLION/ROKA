#include <iostream>

// 9336번 아스키 아트 표

using namespace std;

int m, n, r, c, len;

int main() {
	while(1) {
		cin >> m;
		if(!m) break;
		int arr[500][500] = {};
		for(int i = 0; i < m; i++) {
			cin >> n;
			if(!i) len = n;
			for(int j = 0; j < len; j++) {
				if(arr[i][j]) continue;
				cin >> r >> c;
				if(c > 1) {
					if(!i) len += c - 1;
					if(r > 1) {
						for(int k = 0; k < r; k++) {
							for(int l = k == 0; l < c; l++) {
								arr[i + k][j + l] = k == 0 ? -1 : l == 0 ? 2 : 1;
							}
						}
					}
					else {
						for(int k = 1; k < c; k++) {
							arr[i][j + k] = -1;
						}
					}
				}
				else if(r > 1) {
					for(int k = 1; k < r; k++) {
						arr[i + k][j] = 2;
					}
				}
			}
		}
		for(int i = 0; i < m; i++) {
			int cnt = 0;
			for(int j = 0; j < len; j++) {
				if(arr[i][j] <= 0) {
					while(cnt--) cout << "   ";
					cnt = 0;
					cout << " --";
				}
				else cnt++;
			}
			cout << endl;
			for(int j = 0; j < len; j++) {
				if(arr[i][j] == 2) cout << "|  ";
				else if(arr[i][j]) cout << "   ";
				else cout << '|' << i + 1 << j + 1;
			}
			cout << '|' << endl;
		}
		for(int j = 0; j < len; j++) {
			cout << " --";
		}
		cout << endl << endl;
	}

	return 0;
}