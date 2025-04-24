#include <iostream>
#include <vector>

// 12849번 본대 산책

using namespace std;

long long d, arr[10] = {1};
vector<int> road[10] = {{1, 2}, {0, 2, 3}, {0, 1, 3, 4}, {1, 2, 4, 5}, {2, 3, 5, 6}, {3, 4, 7}, {4, 7}, {5, 6}};

int main() {
	cin >> d;
	while(d--) {
		long long vv[10] = {};
		for(int i = 0; i < 8; i++) {
			for(int ii: road[i]) {
				vv[ii] += arr[i];
			}
		}
		for(int i = 0; i < 8; i++) {
			arr[i] = vv[i] % 1000000007;
//			cout << arr[i] << " ";
		}
//		cout << endl;
	}
	cout << arr[0];
	cin >> d;

	return 0;
} 