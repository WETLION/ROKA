#include <iostream>
#include <algorithm>

// 8949번 Numerically Speaking

using namespace std;

ostream &operator<<(ostream &dest, __int128_t value) {
  ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(ios_base::badbit);
    }
  }
  return dest;
}

void print_num(string n) {
  for(int i = 0; i < n.size(); i++) {
    if(i % 3 == n.size() % 3 && i != 0) cout << ",";
    cout << n[i];
  }
  cout << endl;
}

void convert_string(__int128_t num) {
  string n;
  while(num > 0) {
    n += num % 10 + '0';
    num /= 10;
  }
  reverse(n.begin(), n.end());
  print_num(n);
}

void print_word(string w) {
  cout << w;
  for(int i = w.size(); i < 22; i++) {
    cout << " ";
  }
}

__int128_t convert_int128(string s) {
  __int128_t ret = 0;
  for(char i: s) {
    ret = ret * 10 + i - '0';
  }
  return ret;
}

__int128_t make_num(string w) {
  __int128_t num = 0;
  string ret;
  for(char i: w) {
    num = num * 26 + i - 'a' + 1;
  }
  return num;
}

string make_word(__int128_t num) {
  string ret;
  while(make_num(ret) < num) {
    ret += 'z';
  }
  // cout << "##" << ret << endl;
  if(make_num(ret) != num) {
    // cout << "@@";
    for(int i = 0; i < ret.size(); i++) {
      while(make_num(ret) >= num && ret[i] > 'a') {
        ret[i]--;
        // cout << make_num(ret) << endl;
      }
      if(make_num(ret) < num) {
        ret[i]++;
      }
      if(make_num(ret) == num) break;
      // cout << ret << " " << endl;
    }
  }
  // cout << "??";
  return ret;
}

int main() {
  string input;
  while(1) {
    cin >> input;
    if(input == "*") break;
    if(input[0] >= '0' && input[0] <= '9') {
      print_word(make_word(convert_int128(input)));
      print_num(input);
    }
    else {
      print_word(input);
      // print_word(make_word(make_num(input)));
      convert_string(make_num(input));
    }
  }

  return 0;
}