#include <iostream>
#include <queue>

// 4179번 불!

using namespace std;

struct node {
  int x, y;
};

queue<node> human, fire;
int r, c, map[1001][1001];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, chk, cnt;
string input;

void print_map() {
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < r; j++) {
      cout << map[i][j];
    }
    cout << endl;
  }
}

int main() {
  cin >> c >> r;
  for (int i = 0; i < c; i++) {
    cin >> input;
    for (int j = 0; j < r; j++) {
      switch (input[j]) {
      case '.':
        map[i][j] = 0;
        break;
      case '#':
        map[i][j] = -1;
        break;
      case 'F':
        map[i][j] = 2;
        fire.push({j, i});
        break;
      default:
        map[i][j] = 1;
        human.push({j, i});
      }
    }
  }
  while (!human.empty()) {
    queue<node> __fire, __human;
    swap(__fire, fire);
    swap(__human, human);
    while (!__fire.empty()) {
      node fire_now = __fire.front();
      __fire.pop();
      for (int i = 0; i < 4; i++) {
        int xx = fire_now.x + dx[i];
        int yy = fire_now.y + dy[i];
        if (xx >= 0 && yy >= 0 && xx < r && yy < c && map[yy][xx] != -1 &&
            map[yy][xx] != 2) {
          map[yy][xx] = 2;
          fire.push({xx, yy});
        }
      }
    }
    while (!__human.empty()) {
      node human_now = __human.front();
      __human.pop();
      for (int i = 0; i < 4; i++) {
        int xx = human_now.x + dx[i];
        int yy = human_now.y + dy[i];
        if (xx < 0 || yy < 0 || xx >= r || yy >= c) {
          cout << cnt + 1;
          chk = 1;
          break;
        } else if (map[yy][xx] == 0) {
          map[yy][xx] = 1;
          human.push({xx, yy});
        }
      }
      if (chk)
        break;
    }
    // print_map();
    if (chk)
      break;
    cnt++;
  }
  if (!chk)
    cout << "IMPOSSIBLE";

  return 0;
}