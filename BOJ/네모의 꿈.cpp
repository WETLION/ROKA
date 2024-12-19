#include <iostream>

// 32205번 네모의 꿈 

using namespace std;

int arr[1000001], n, a, b, c;

int main() {
  cin >> n;
  while(n--) {
    cin >> a >> b >> c;
    if(++arr[a] == 2 || ++arr[b] == 2 || ++arr[c] == 2) {
      cout << '1';
      return 0;
    }
  }
  cout << '0';

  return 0;
}