#include <iostream>

// 15947번 아기 석환 뚜루루 뚜루

using namespace std;

int n;
string arr[14] = {"baby", "sukhwan", "tururu", "turu", "very", "cute", "tururu", "turu", "in", "bed", "tururu", "turu", "baby", "sukhwan"};

int main() {
  cin >> n;
  n--;
  if(n % 14 == 2 || n % 14 == 6 || n % 14 == 10) {
    if(n / 14 > 2) {
      cout << "tu+ru*" << n / 14 + 2;
    }
    else {
      cout << arr[n % 14];
      for(int i = 0; i < n / 14; i++) cout << "ru";
    }

  }
  else if(n % 14 == 3 || n % 14 == 7 || n % 14 == 11) {
    if(n / 14 > 3) {
      cout << "tu+ru*" << n / 14 + 1;
    }
    else {
      cout << arr[n % 14];
      for(int i = 0; i < n / 14; i++) cout << "ru";
    }
  }
  else cout << arr[n % 14]; // 2 3 6 7 10 11

  return 0;
} 