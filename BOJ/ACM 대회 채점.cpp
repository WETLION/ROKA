#include <iostream>

// 11531번 ACM 대회 채점 

using namespace std;

int n, arr[30], chk[30], ans, cnt;
char alpha;
string str;

int main() {
  while(1) {
    cin >> n;
    if(n == -1) break;
    cin >> alpha >> str;
    alpha -= 'A';
    if(str == "right") {
      arr[alpha] += n;
      chk[alpha] = 1;
      cnt++;
    }
    else arr[alpha] += 20;
  }
  for(int i = 0; i < 26; i++) {
    if(chk[i]) ans += arr[i];
  }
  cout << cnt << " " << ans;

  return 0;
}