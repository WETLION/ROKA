#include <iostream>
#include <stack>

// 4900번 7 더하기 

using namespace std;

string str;
int i, temp, a, b, arr[10] = {0b0111111, 0b0001010, 0b1011101, 0b1001111, 0b1101010, 0b1100111, 0b1110111, 0b0001011, 0b1111111, 0b1101011};
stack<int> s;

int main() {
  while(1) {
    cin >> str;
    if(str == "BYE") break;
    a = b = 0;
    for(i = 0; ; i++) {
      if(i % 3 == 0) {
        for(int i = 0; i < 10; i++) if(arr[i] == temp) a = a * 10 + i;
        temp = 0;
      }
      if(str[i] == '+') break;
      temp = temp * 10 + str[i] - '0';
    }
    for(i = i + 1; ; i++) {
      if(i % 3 == 1) {
        for(int i = 0; i < 10; i++) if(arr[i] == temp) b = b * 10 + i;
        temp = 0;
      }
      if(i == str.size()) break;
      temp = temp * 10 + str[i] - '0';
    }
    cout << str;
    a += b;
    while(a) {
      s.push(arr[a % 10]);
      a /= 10;
    }
    while(!s.empty()) {
      int now = s.top();
      s.pop();
      if(now < 10) cout << "00" << now;
      else if(now < 100) cout << "0" << now;
      else cout << now;
    }
    cout << endl;
  }

  return 0;
}