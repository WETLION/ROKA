#include <iostream>
#include <cstdio>

// 16139번 인간-컴퓨터 상호작용 

using namespace std;

int n, l, r, arr[30][200010];
string str;
char word[10];

int main() {
  cin >> str >> n;
  arr[str.front() - 'a'][1]++;
  for(int i = 1; i < str.size(); i++) {
    for(int j = 0; j < 26; j++) {
      arr[j][i + 1] = arr[j][i]; // 부분합 왼쪽 값이 한칸 밀려야함
      if(str[i] - 'a' == j) arr[j][i + 1]++;
    }
  }
  while(n--) {
    scanf(" %s%d%d", word, &l, &r); // cin 속도 문제
    printf("%d\n", arr[word[0] - 'a'][r + 1] - arr[word[0] - 'a'][l]); // cout 속도 문제, 개행문자, 부분 합 왼쪽 이슈
  }

  return 0;
}