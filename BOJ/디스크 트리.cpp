#include <iostream>
#include <vector>
#include <algorithm>

// 7432번 디스크 트리

using namespace std;

struct node {
  string name;
  vector<node> v;
};

int n, before;
string str;
node *now, start;

bool cmp(node a, node b) {
  return a.name < b.name;
}

void node_push(string temp) {
  for(int i = 0; i < now -> v.size(); i++) {
    if(now -> v[i].name == temp) {
      now = &(now -> v[i]);
      return;
    }
  }
  now -> v.push_back({temp, vector<node>()});
  now = &(now -> v[now -> v.size() - 1]);
}

void print_node(node now, int num) {
  sort(now.v.begin(), now.v.end(), cmp);
  for(node i: now.v) {
    for(int j = 0; j < num; j++) cout << " ";
    cout << i.name << endl;
    if(!i.v.empty()) print_node(i, num + 1);
  }
}

int main() {
  cin >> n;
  while(n--) {
    cin >> str;
    before = 0;
    now = &start;
    for(int i = 0; i < str.size(); i++) {
      if(str[i] == '\\') {
        string folder = str.substr(before, i - before);
        before = ++i;
        node_push(folder);
      }
    }
    string folder = str.substr(before, str.size() - before);
    node_push(folder);
  }
  print_node(start, 0);
//	cin >> n;

  return 0;
} 