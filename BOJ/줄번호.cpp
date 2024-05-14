#include <iostream>
#include <string>

// 4470번 줄번호

using namespace std;

int n;
string input;

int main() {
  cin >> n;
  getchar();
  for(int i = 1; i <= n; i++) {
    getline(cin, input);
    cout << i << ". " << input << endl;
  }

  return 0;
}