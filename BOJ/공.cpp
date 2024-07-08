#include <iostream>

// 1547번 공

using namespace std;

int n, a, b, arr[4]={0, 1};

int main() {
  cin >> n;
  while(n--) {
    cin >> a >> b;
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
  }
  for(int i = 1; i <= 3; i++) {
    if(arr[i]) cout << i;
  }

  return 0;
}