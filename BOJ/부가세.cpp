#include <iostream>

// 27357번 부가세 

using namespace std;

long long t, x, x_1, n, sum, chk;
double p;

int main() {
  cin >> t;
  while(t--) {
    cin >> n >> x;
    sum = chk = 0;
    for(int i = 0; i < n; i++) {
      cin >> p;
      sum += p * 1000000;
    }
    x *= 1000000; // 정밀도 문제로 인해 10000에서 두자리 추가
    x -= sum;
    x_1 = x + 1000000;
//		cout << "###" << x << " " << x_1 << endl;
    for(long long i = 0; i <= 10001; i++) { // 10001까지 안가면 10000이 상한선인 경우 출력을 못함
      if(chk) {
        if(sum / 100 * i < x_1) continue;
//				cout << "$$$" << sum / 100 * i << endl;
        cout << i - 1;
        break;
      }
      else {
        if(sum / 100 * i < x - 9999) continue;
//				cout << "$$$" << sum / 100 * i << endl; 
        cout << i << ' ';
        chk = 1;
      }
    }
    cout << endl;
  }
  cin >> n;

  return 0;
}