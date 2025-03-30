#include <iostream>

// 15726번 이칙연산

using namespace std;

double arr[3];

int main() {
	for(int i = 0; i < 3; i++) cin >> arr[i];
	if(arr[1] < arr[2]) cout << int(arr[0] / arr[1] * arr[2]);
	else cout << int(arr[0] * arr[1] / arr[2]);

	return 0;
}