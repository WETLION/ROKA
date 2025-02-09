#include <iostream>
#include <vector>
#include <algorithm>

// 11067번 모노톤길

using namespace std;

int t, n, m, c_x, c_y, k, n_y, len;
vector<int> v[100001];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        len = n_y = 0;
        for(int i = 0; i < n; i++) {
            cin >> c_x >> c_y;
            v[c_x].push_back(c_y);
            len = max(len, c_x);
        }
        for(int i = 0; i <= len; i++) {
            if(v[i].size() > 1) {
                sort(v[i].begin(), v[i].end());
                if(v[i].front() != n_y) sort(v[i].begin(), v[i].end(), greater<int>());
                n_y = v[i].back();
            }
        }
        cin >> m;
        while(m--) {
            cin >> k;
            k--;
            for(int i = 0; i <= len; i++) {
                if(v[i].size() > k) {
                    cout << i << " " << v[i][k] << endl;
                    break;
                }
                k -= v[i].size();
            }
        }
        for(int i = 0; i <= len; i++) v[i].clear(); // 모든 vector를 clear 하지 않음(i < len으로 표기했으나, i <= len이 맞음) 
    }
    cin >> t;

    return 0;
} 