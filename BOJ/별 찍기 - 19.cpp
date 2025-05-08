#include <iostream>

// 10994번 별 찍기 - 19

using namespace std;

int n, arr[1000][1000];

void recursion(int num) {
	if(!num) return;
	int x = (n + 1 - num--) * 2, y = x;
	for(int i = 0; i < num * 4 + 1; i++) arr[y][x + i] = 1;
	for(int i = 1; i < num * 4; i++) {
		if(i == 2) recursion(num);
		arr[y + i][x] = arr[y + i][n * 4 - x] = 1;
	}
	for(int i = 0; i < num * 4 + 1; i++) arr[n * 4 - y][x + i] = 1;
}

int main() {
	cin >> n;
	recursion(n--);
	for(int i = 0; i <= n * 4; i++) {
		for(int j = 0; j <= n * 4; j++) {
			cout << (arr[i][j] ? '*' : ' ');
		}
		cout << endl;
	}
	cin >> n;

	return 0;
} 