#include <cstring>
#include <iostream>

// 1662번 압축

using namespace std;

char word[100];
int len, i;

int how_long(int open) {
  int sum = 0;
  //, open = 0;
  for (; i < len; i++) {
    // cout << "i : " << i << endl; //segfault 해결용
    if (word[i] == ')') {
      // i++;
      // cout << ") " << sum << " " << open << endl;
      return open > 0 ? sum : -1;
    } else if (word[i] == '(') {
      if (i == 0 || word[i - 1] < '0' && word[i - 1] > '9')
        return -1;
      int backup = i - 1;
      i++;
      sum--;
      int now = how_long(open + 1);
      // cout << "( " << now << " " << word[backup] - '0' << endl;
      if (now < 0)
        return -1;
      else if (word[backup] - '0' > 0 && now > 0)
        sum += (word[backup] - '0') * now;
    } else
      sum++;
  }
  return open == 0 ? sum : -1;
}

int main() {
  cin >> word;
  len = strlen(word);
  cout << how_long(0);

  return 0;
}