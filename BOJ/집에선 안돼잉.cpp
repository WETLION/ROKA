#include <iostream>

// 29734번 집에선 안돼잉

using namespace std;

long long n, m, t, s; // 수 범위 오류 

int main()  {
	cin >> n >> m >> t >> s;
	if(n + (n / 8 - !(n % 8)) * s < m + (m / 8 - !(m % 8)) * (s + 2 * t) + t) cout << "Zip" << endl << n + (n / 8 - !(n % 8)) * s;
	else cout << "Dok" << endl << m + (m / 8 - !(m % 8)) * (s + 2 * t) + t;
	cin >> n;

	return 0;
}