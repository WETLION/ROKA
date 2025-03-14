#include <iostream>
#include <algorithm>

// 11943번 파일 옮기기

using namespace std;

int a, b, c, d;

int main() {
	cin >> a >> b >> c >> d;
	cout << min(b + c, a + d);

	return 0;
}