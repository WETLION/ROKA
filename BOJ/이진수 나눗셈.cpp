#include <iostream>

// 22950번 이진수 나눗셈 

using namespace std;

string str;
int n, k; 

int main() {
	cin >> n >> str >> k;
	for(int i = 0; i < k && i < n; i++) { // 나누어 떨어지는 수는 나누는 수의 자릿수까지만 나눠지면 됨(여기선 K)
		if(str[n - i - 1] == '1') {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}