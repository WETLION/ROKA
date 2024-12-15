#include <iostream>
#include <cmath>

// 20436번 ZOAC 3

using namespace std;

int arr[30][2] = {{0, 1}, {4, 2}, {2, 2}, {2, 1}, {2, 0}, {3, 1}, {4, 1}, {5, 1}, {7, 0}, {6, 1}, {7, 1}, {8, 1}, {6, 2}, {5, 2}, {8, 0}, {9, 0}, {0, 0}, {3, 0}, {1, 1}, {4, 0}, {6, 0}, {3, 2}, {1, 0}, {1, 2}, {5, 0}, {0, 2}}, ans;
string str;
int l, r;

int main() {
  cin >> str;
  l = str[0] - 'a'; // - 'a' 빼먹음
  cin >> str;
  r = str[0] - 'a'; // - 'a' 빼먹음
  cin >> str;
  for(int i: str) {
    if(i == 'b' || i == 'u' || i == 'y' || 'h' <= i && i <= 'p') {
      ans += abs(arr[r][0] - arr[i - 'a'][0]) + abs(arr[r][1] - arr[i - 'a'][1]); // - 'a' 빼먹음
      r = i - 'a'; // - 'a' 빼먹음
    }
    else {
      ans += abs(arr[l][0] - arr[i - 'a'][0]) + abs(arr[l][1] - arr[i - 'a'][1]); // - 'a' 빼먹음
      l = i - 'a'; // - 'a' 빼먹음
    }
  }
  cout << ans + str.size();

  return 0;
}