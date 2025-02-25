#include <iostream>
#include <vector>
#include <queue>

// 17225번 세훈이의 선물가게 

using namespace std;

struct node {
    int t, m;
    char c;
};

node input;
int a, b, n, b_cnt, r_cnt, t, b_task, r_task, cnt;
char c;
vector<int> ans_b, ans_r;
queue<node> q;

int main() {
    cin >> a >> b >> n;
    while(n--) {
        cin >> input.t >> input.c >> input.m;
        q.push(input);
    }
    for(int i = 1; !q.empty() || b_task || r_task; i++) {
        if(q.front().t == i && q.front().c == 'B') { // 순서 바꾸니까 통과 : Blue를 무조건 우선적으로 처리하고 Red를 처리하는 방식으로 변경하니 해결
            node now = q.front();
            q.pop();
            b_cnt += now.m;
            if(!a) while(now.m--) ans_b.push_back(++cnt);
            else b_task += now.m * a;
        }
        if(b_task) {
            if(!(b_task % a)) ans_b.push_back(++cnt);
            b_task--;
        }
        if(q.front().t == i && q.front().c == 'R') {
            node now = q.front();
            q.pop();
            r_cnt += now.m;
            if(!b) while(now.m--) ans_r.push_back(++cnt);
            else r_task += now.m * b;
        }
        if(r_task) {
            if(!(r_task % b)) ans_r.push_back(++cnt);
            r_task--;
        }
    }
    cout << b_cnt << endl;
    for(int i: ans_b) cout << i << " ";
    cout << endl << r_cnt << endl;
    for(int i: ans_r) cout << i << " ";

    return 0;
}