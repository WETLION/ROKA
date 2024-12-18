#include <iostream>

// 9324번 진짜 메시지 

using namespace std;

int n;
string str;

bool check() {
  int arr[30] = {};
  for(int i = 0; i < str.size(); i++) {
    if(++arr[str[i] - 'A'] == 3) {
      if(i == str.size() - 1 || str[i + 1] != str[i]) {
        cout << "FAKE";
        return 0;
      }
      arr[str[i++] - 'A'] = 0;			
    }
  }
  return 1;
}

int main() {
  cin >> n;
  while(n--) {
    cin >> str;
    if(check()) cout << "OK";
    cout << endl;
  }

  return 0;
}