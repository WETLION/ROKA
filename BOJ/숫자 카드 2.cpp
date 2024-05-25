#include <cstdio>
#include <unordered_map>

// 10816번 숫자 카드 2 

using namespace std;

int n, M, input;
unordered_map<int, int> m;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &input);
    if(m.find(input) != m.end()) m[input]++;
    else m[input] = 1;
  }
  scanf("%d", &M);
  for(int i = 0; i < M; i++) {
    scanf("%d", &input);
    if(m.find(input) == m.end()) printf("0 ");
    else printf("%d ", m[input]);
  }

  return 0;
}