#include <iostream>
#include <algorithm>

// 32373번 장난감 자물쇠

using namespace std;

int n, k, arr[200000];

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for(int i = 0; i < n; i++) {
    if(arr[i] % k != i % k) {
      cout << "No";
//			cin >> n;
      return 0;
    } 
  }
  cout << "Yes";
//	cin >> n;

  return 0;
}