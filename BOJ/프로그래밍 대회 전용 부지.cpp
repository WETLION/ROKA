#include <iostream>
#include <vector>
#include <algorithm>

// 9414번 프로그래밍 대회 전용 부지

using namespace std;

int t, input, sum, chk;

int main() {
    cin >> t;
    while(t--) {
        vector<int> v;
        sum = chk = 0;
        while(1) {
            cin >> input;
            if(!input) break;
            v.push_back(input);
        }
        sort(v.begin(), v.end(), greater<int>());
        for(int i = 0; i < v.size(); i++) {
            int temp = 2;
            for(int j = 0; j <= i; j++) {
                temp *= v[i];
                if(sum + temp > 5000000) {
                    chk = 1;
                    break;
                }
            }
            if(chk) break;
            sum += temp;
        }
        if(chk) cout << "Too expensive" << endl;
        else cout << sum << endl;
    }   

    return 0;
}
