#include <iostream>

// 2251번 물통

using namespace std;

int arr[10000][3][201], ans[201];
int a, b, c, cnt;

void find_list(int aa, int bb, int cc) {
  for (int i = 0; i < cnt; i++) {
    if (arr[i][0][aa] && arr[i][1][bb] && arr[i][2][cc])
      return;
  }
  arr[cnt][0][aa] = arr[cnt][1][bb] = arr[cnt][2][cc] = 1;
  cnt++;
  if (aa == 0)
    ans[cc] = 1;
  // cout << aa << " " << bb << " " << cc << endl;
  if (cc - (b - bb) < 0)
    find_list(aa, bb + cc, 0);
  else
    find_list(aa, b, cc - (b - bb));

  if (cc - (a - aa) < 0)
    find_list(aa + cc, bb, 0);
  else
    find_list(a, bb, cc - (a - aa));

  if (bb - (a - aa) < 0)
    find_list(aa + bb, 0, cc);
  else
    find_list(a, bb - (a - aa), cc);

  if (aa - (b - bb) < 0)
    find_list(0, bb + aa, cc);
  else
    find_list(aa - (b - bb), b, cc);

  find_list(0, bb, cc + aa);
  find_list(aa, 0, cc + bb);
}

int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> a >> b >> c;
  find_list(0, 0, c);

  for (int i = 0; i <= 200; i++) {
    if (ans[i])
      cout << i << " ";
  }

  return 0;
}