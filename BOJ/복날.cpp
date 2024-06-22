#include <iostream>
#include <cmath>
#include <queue>

// 1686번 복날

using namespace std;

struct node {
  int loca, count;
};

double arr[1010][1010], point[1010][2], input_x, input_y;
int cnt, v, m, visit[1010];
queue<node> q;

int main() {
  cin >> v >> m;
  v *= 60 * m; // m을 안곱함
  while(!cin.eof()) {
    cin >> input_x >> input_y;
    for(int i = 0; i < cnt; i++) {
      arr[cnt][i] = arr[i][cnt] = sqrt(pow(point[i][0] - input_x, 2) + pow(point[i][1] - input_y, 2));
    }
    point[cnt][0] = input_x;
    point[cnt++][1] = input_y;
  }
  q.push({0, 0});
  while(!q.empty()) {
    node now = q.front();
    q.pop();
    if(!visit[now.loca]) {
      visit[now.loca] = 1;
      for(int i = 1; i < cnt; i++) {
        if(arr[now.loca][i] < v && !visit[i]) {
          if(i == 1) {
            cout << "Yes, visiting " << now.count << " other holes.";
            return 0;
          }
          q.push({i, now.count + 1});
        }
      }
    }
  }
  cout << "No.";

  return 0;
}