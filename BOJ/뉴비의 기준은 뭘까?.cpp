#include <iostream>

// 19944번 뉴비의 기준은 뭘까? 

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    if(m <= 2) cout << "NEWBIE!";
    else if(m <= n) cout << "OLDBIE!";
    else cout << "TLE!";

    return 0;
}
