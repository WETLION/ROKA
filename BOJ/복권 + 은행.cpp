#include <iostream>

// 13258번 복권 + 은행 

using namespace std;

int n, j, c, sum, input, g;

int main() {
	cout << fixed;
	cout.precision(12);
	cin >> n >> g;
	sum = g;
	while(--n) {
		cin >> input;
		sum += input;
	}
	cin >> j >> c;
//	cout << g << " " << sum << " " << j << " " << c << endl;
	cout << double(g) / sum * j * c + g;
	cin >> n;

	return 0;
}