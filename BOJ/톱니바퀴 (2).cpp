#include <iostream>
#include <deque>

// 15662번 톱니바퀴 (2)

using namespace std;

int t, k, n, spin, ans;
string str;
deque<int> dq[1000];

int main() {
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> str;
    for(char j: str) dq[i].push_back(j == '1'); // i를 두군데에 사용해서 오류남 
  }
  cin >> k;
  while(k--) {
    cin >> n >> spin;
    int temp = spin;
//		cout << n << " " << spin << endl;
    for(int i = n - 1; i < t - 1; i++) {
//			cout << "#" << i << endl;
      if(dq[i][2] == dq[i + 1][6] || i == t - 2) {
//				cout << "!" << i << endl;
        int chk = i == t - 2 && dq[i][2] != dq[i + 1][6]; // 이런식으로 값을 저장하지 않으면 돌면서 중간에 값이 바뀌면서 끝까지 안가는 경우가 생김 
        for(int j = n; j <= i + chk; j++) {
//					cout << "!!" << j << " " << temp << " " << dq[j].front() << " " << dq[j].back() << endl;
          temp *= -1;
          if(temp == 1) {
            dq[j].push_front(dq[j].back());
            dq[j].pop_back();
          }
          else {
            dq[j].push_back(dq[j].front());
            dq[j].pop_front();
          }
//					cout << "!!!" << endl;
        }
        break;
      }
    }
    temp = spin;
    for(int i = n - 1; i > 0; i--) {
      if(dq[i][6] == dq[i - 1][2] || i == 1) {
//				cout << "@" << i << endl;
        int chk = dq[i][6] != dq[i - 1][2] && i == 1; // 이런식으로 값을 저장하지 않으면 돌면서 중간에 값이 바뀌면서 끝까지 안가는 경우가 생김 
        for(int j = n - 2; j >= i - chk; j--) {
          temp *= -1;
          if(temp == 1) {
            dq[j].push_front(dq[j].back());
            dq[j].pop_back();
          }
          else {
            dq[j].push_back(dq[j].front());
            dq[j].pop_front();
          }
        }
        break;
      }
    }
    if(spin == 1) {
      dq[n - 1].push_front(dq[n - 1].back());
      dq[n - 1].pop_back();
    }
    else {
      dq[n - 1].push_back(dq[n - 1].front());
      dq[n - 1].pop_front();
    }
//		cout << "#########" << endl;
//		for(int i = 0; i < t; i++) {
//			for(int j: dq[i]) {
//				cout << j;
//			}
//			cout << endl;
//		}
//		cout << "#########" << endl;
  }
  while(t--) {
    ans += dq[t].front();
  }
  cout << ans;
  cin >> n;

  return 0;
} 