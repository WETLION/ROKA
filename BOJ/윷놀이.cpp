#include <iostream>

// 2490번 윷놀이

using namespace std;

char arr[5] = {'D', 'C', 'B', 'A', 'E'};

int main() {
  for(int i = 0; i < 3; i++) {
    int sum = 0, input;
    for(int j = 0; j < 4; j++) {
      cin >> input;
      sum += input;
    }
    cout << arr[sum] << endl;
  }

  return 0;
}