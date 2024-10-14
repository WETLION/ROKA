#include <iostream>

// 25705번 돌림판 문자열 

using namespace std;

int n, m, now, ans;
string o, s;

int main() {
  cin >> n >> o >> m >> s;
  now = n - 1;
  for(char i: s) {
  	int j;
  	now = (now + 1) % n;
    for(j = 1; j <= n; j++) {
    	if(o[now] == i) {
    		ans += j;
    		break;
		}
		now = (now + 1) % n;
	}
	if(j == n + 1) {
		cout << -1;
		return 0;
	}
  }
  cout << ans;

  return 0;
}
