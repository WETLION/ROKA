#include <iostream>

// 11575번 Affine Cipher

using namespace std;

int t, a, b;
string input;

int main() {
  cin >> t;
  while(t--) {
    cin >> a >> b >> input;
    for(int i = 0; i < input.size(); i++) {
      input[i] = (((input[i] - 'A') * a + b) % 26) + 'A';
    }
    cout << input << endl;
  }

  return 0;
}