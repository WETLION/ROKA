#include <algorithm>
#include <cstdio>
#include <iostream>
#include <unordered_map>

// 1270번 전쟁 - 땅따먹기

using namespace std;

int n, m;
long long int input;

int main() {
  cin >> n;
  while (n--) {
    unordered_map<long long int, int> mm;
    int MAX = 0, MAX_NUM, chk = 0, standard;
    scanf("%d", &m);
    standard = m / 2;
    for (int i = 0; i < m; i++) {
      scanf("%lld", &input);
      if (mm.find(input) != mm.end()) {
        mm[input]++;
      } else
        mm.insert({input, 1});
      if (mm[input] > standard) {
        cout << input << '\n';
        chk = 1;
        string temp;
        getline(cin, temp);
        break;
      }
    }
    if (chk)
      continue;
    cout << "SYJKGW\n";
    // for (auto i : mm) {
    //   // cout << "# " << i.first << " " << i.second << endl;
    //   if (i.second > m / 2) {
    //     cout << i.first << "\n";
    //     break;
    //   }
    // }
    // if (MAX > m / 2)
    //   printf("%d\n", MAX_NUM);
    // else
    //   printf("SYJKGW\n");
  }

  return 0;
}