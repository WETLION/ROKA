#include <iostream>
#include <vector>
#include <cstdio>

// 20302번 민트 초코

using namespace std;

int arr[100001], top[100001], bot[100001], n, input, zero_chk;
char symbol; 
vector<int> v;

void factorization(int num, int chk) {
  if(!num) { // input이 0일 경우 무한 루프의 가능성이 있음. 이거때문에 7퍼에서 시간초과 
    zero_chk = 1;
    return;
  }
  if(num < 0) num *= -1;
  for(int i: v) {
    if(num == 1) break;
    if(!arr[num]) {
      if(chk) top[num]++;
      else bot[num]++;
      break;
    }
    while(num % i == 0) {
      if(chk) top[i]++;
      else bot[i]++;
      num /= i;
    }
  }
}

int main() {
  arr[0] = arr[1] = 1;
  v.push_back(2);
  for(int i = 4; i <= 100000; i = i + 2) arr[i] = 1;
  for(int i = 3; i < 100000; i = i + 2) {
    if(arr[i]) continue;
    v.push_back(i);
    for(int j = i * 2; j < 100000; j = j + i) arr[j] = 1;
  }
  cin >> n >> input;
  factorization(input, 1);
  for(int i = 1; i < n; i++) {
    scanf(" %c %d", &symbol, &input);
//		cout << symbol << "!!!" << input << endl;
    factorization(input, symbol == '*');
  }
  for(int i: v) {
//		if(top[i] || bot[i]) cout << i << " " << top[i] << " " << bot[i] << endl;
    if(top[i] < bot[i] && !zero_chk) { // 만약 분자가 0이면 무조건 0임 
      cout << "toothpaste";
      cin >> n;
      return 0;
    }
  }
  cout << "mint chocolate";
  cin >> n;

  return 0;
}