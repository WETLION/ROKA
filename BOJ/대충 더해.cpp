#include <iostream>
#include <cmath>
#include <string>

// 8949번 대충 더해

using namespace std;

string a, b;
int diff;

int main() {
  cin >> a >> b;
  diff = a.size() - b.size();
  if(diff < 0) {
    for(int i = 0; i < -diff; i++) {
      cout << b[i];
    }
    for(int i = 0; i < a.size(); i++) {
      cout << a[i] + b[i - diff] - '0' * 2;
    }
  }
  else {
    for(int i = 0; i < diff; i++) {
      cout << a[i];
    }
    for(int i = 0; i < b.size(); i++) {
      cout << a[i + diff] + b[i] - '0' * 2;
    }
  }

  return 0;
}