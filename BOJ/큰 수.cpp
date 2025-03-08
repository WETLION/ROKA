#include <iostream>
#include <cmath>

// 7894번 큰 수

using namespace std;

int n, m;
double arr[10000001];

int main() {
	cin >> n;
	for(int i = 2; i <= 10000000; i++) {
		arr[i] = arr[i - 1] + log10(i);
	}
	cout << fixed;
	cout.precision(0);
	while(n--) {
		cin >> m;
		if(m == 1) cout << 1 << endl; // 1일 경우 1 출력하도록 해야함 안그러면 0 출력함
		else cout << floor(arr[m]) + 1 << endl;
	}
	cin >> n;

	return 0;
}

// 아래는 스털링 근사

#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

// 7894번 큰 수

using namespace std;

int n, m;

int main() {
	cin >> n;
	cout << fixed;
	cout.precision(0);
	while(n--) {
		cin >> m;
		if(m == 1) cout << 1 << endl; // 1일 경우 1 출력하도록 해야함 안그러면 0 출력함
		else cout << floor((log10(2) + log10(M_PI) + log10(m)) / 2 + m * (log10(m) - log10(M_E))) + 1 << endl; // 개행 문자 출력 안함
	}
	cin >> n;

	return 0;
}