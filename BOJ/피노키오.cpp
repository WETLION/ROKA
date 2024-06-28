#include <iostream>

// 12866번 피노키오

using namespace std;

int n;
long long arr[4];
string word;

int main() {
  cin >> n >> word;
  for(char i: word) {
    switch(i) {
      case 'A':
        arr[0]++;
        break;
      case 'C':
        arr[1]++;
        break;
      case 'G':
        arr[2]++;
        break;
      case 'T':
        arr[3]++;
    }
  }
  cout << (((arr[0] * arr[1]) % 1000000007) * ((arr[2] * arr[3]) % 1000000007)) % 1000000007;

  return 0;
}