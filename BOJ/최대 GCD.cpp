#include <iostream>
#include <string>
#include <algorithm>

// 9417번 최대 GCD

using namespace std;

int n;
string str;

int gcd(int a, int b) {
  return a % b ? gcd(b, a % b) : b;
}

int main() {
  cin >> n;
  getchar();
  while(n--) {
    int arr[101] = {}, cnt = 0, MAX = 0, num = 0; // num 0으로 초기화 안함
    getline(cin, str);
    for(char i: str) {
      if(i == ' ') {
        arr[cnt++] = num;
        num = 0;
        continue;
      }
      num = num * 10 + i - '0'; 
    }
    if(!cnt) { // 한개일 경우 처리 안함
      cout << num << endl;
      continue;
    }
    arr[cnt++] = num;
    sort(arr, arr + cnt, greater<int>()); // 내림차순 정렬 안함
    for(int i = 0; i < cnt; i++) {
      for(int j = i + 1; j < cnt; j++) {
        MAX = max(MAX, gcd(arr[i], arr[j]));
      }
    }
    cout << MAX << endl;
  }

  return 0;
}