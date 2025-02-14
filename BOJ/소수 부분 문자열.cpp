#include <iostream>
#include <string>
#include <algorithm>

// 5636번 소수 부분 문자열 

using namespace std;

int arr[100000], ans;
string str;

int main() {
  arr[1] = arr[0] = 1;
  for(int i = 4; i <= 100000; i = i + 2) arr[i] = 1;
  for(int i = 3; i <= 100000; i = i + 2) {
    if(arr[i]) continue;
    for(int j = i * 2; j <= 100000; j = j + i) arr[j] = 1;
  }
//	for(int i = 0; i <= 100000; i++) if(!arr[i]) cout << i << " "; // 에라토스테네스의 체 검증 
  while(1) {
    cin >> str;
    if(str == "0") break;
    ans = 0;
    for(int i = min(5, int(str.size())); i > 0; i--) {
      for(int j = 0; j < str.size() - i; j++) {
        if(str[j] == '0') continue;
        int num = stoi(str.substr(j, i)); // 내가 평소에 풀던 부분 문자열이 아니라 그냥 일정 토막이었음 
        if(!arr[num]) ans = max(ans, num);
      }
      if(ans) {
        cout << ans << endl;
        break;
      }
    }
  }

  return 0;
}