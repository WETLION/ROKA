#include <iostream>
#include <string>

// 31403번 $A + B - C$

using namespace std;

int a, b, c;

int main() {
  cin >> a >> b >> c;
  cout << a + b - c << endl << stoi(to_string(a) + to_string(b)) - c;

  return 0;
}