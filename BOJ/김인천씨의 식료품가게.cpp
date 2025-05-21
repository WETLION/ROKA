#include <iostream>
#include <algorithm>

// 12034번 김인천씨의 식료품가게 

using namespace std;

int t, n, arr[201]; // n이 100 이하이므로 200개 이하의 값이 들어옴. 

int main() {
	cin >> t;
	for(int k = 1; k <= t; k++) {
		int chk[201] = {}; // n이 100 이하이므로 200개 이하의 값이 들어옴. 
		cin >> n;
		for(int i = 0; i < 2 * n; i++) cin >> arr[i];
		cout << "Case #" << k << ":";
		for(int i = 0; i < 2 * n; i++) {
			if(chk[i]) continue;
			cout << " " << arr[i];
			int location = lower_bound(arr, arr + 2 * n, arr[i] / 3 * 4) - arr;
			while(chk[location]) location++;
			chk[location] = 1;
		}
		cout << endl;
	}
	cin >> t;

	return 0;
}