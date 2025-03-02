#include <cstdio>

// 16567번 바이너리 왕국

using namespace std;

int n, m, arr[1000001], cnt, input;

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    if(arr[i] && (i == 0 || !arr[i - 1])) cnt++;
  }
  while(m--) {
    scanf("%d", &input);
    if(input) {
      scanf("%d", &input);
      if(!arr[--input]) {
        arr[input] = 1;
        if(input && arr[input - 1] && input < n && arr[input + 1]) cnt--;
        else if(input && !arr[input - 1] && input < n && !arr[input + 1]) cnt++;
      }
    }
    else printf("%d\n", cnt);
  }
//	cin >> n;

  return 0;
} 