#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class big_int {
  public:
    big_int() {
      num = "0";
    }
    string plus(string str) {
      string temp = num;
      reverse(str.begin(), str.end());
      reverse(temp.begin(), temp.end());
      if(str.size() < temp.size()) {
        str.resize(temp.size(), '0');
      }
      else if(str.size() > temp.size()) {
        temp.resize(str.size(), '0');
      }
      bool chk = 0;
      for(int i = 0; i < temp.size(); i++) {
        int str_temp = temp[i] + str[i] - '0' * 2 + chk;
        chk = 0;
        if(str_temp >= 10) {
          chk = 1;
          str_temp -= 10;
        }
        temp[i] = str_temp + '0';
      }
      if(chk) {
        temp.resize(temp.size() + 1);
        temp[temp.size() - 1] = '1';
      }
      reverse(temp.begin(), temp.end());
      return temp;
    }
    string operator+=(string str) {
      return num = plus(str);
    }
    string operator*=(long long n) {
      vector<big_int> v;
      big_int temp, ret;
      temp = num;
      v.push_back(temp);
      for(int i = 1; i <= log_2(n); i++) {
        big_int sum;
        sum = v[i - 1].plus(v[i - 1].now());
        v.push_back(sum);
//				cout << '#' << sum.now() << endl;
      }
      while(n) {
        ret += v[log_2(n)].now();
//				cout << '@' << ret.now() << " " << log2(n) << endl;
        n -= pow(2, log_2(n)); // int 형변환 오류, pow는 소수도 리턴함. 

      }
      return num = ret.now();
    }
    string now(){
      return num;
    }
    string operator=(string str) {
      num = str;
      return num;
    }
  private:
    string num;
    long long log_2(long long n) {
      long long cnt = 0;
      while(n) {
        cnt++;
        n /= 2;
      }
      return cnt - 1;
    }
};

big_int ans;
string a;
long long b, t;

int main() {
  getline(cin, a, '.');
  ans = a;
  if(a == "0") {
    int zero_cnt = 1;
    cout << "0.";
    cin >> a >> b;
    t = stoll(a);
    ans = to_string(t);
    for(int i = 1; i < b; i++) {
      ans *= t;
    }
//		cout << zero_cnt << endl;
//		cout << '#' << ans.now().size() << '#' << endl; 
//		zero_cnt -= ans.now().size();
    for(int i = 0; i < a.size() * b - ans.now().size(); i++) cout << '0'; // 0의 개수 틀림 
    cout << ans.now();
//		cin >> a;
    return 0;
  }
  cin >> a >> b;
  ans = ans.now() + a;
  t = stoll(ans.now());
//	cout << t << endl;
  for(int i = 1; i < b; i++) {
//		cout << b << endl;
    ans *= t;
  }
  for(int i = 0; i < ans.now().size(); i++) {
    if(i == ans.now().size() - a.size() * b) cout << '.';
    cout << ans.now()[i];
  }
//	cout << endl << ans.now().size();
//	cin >> a;

  return 0;
}