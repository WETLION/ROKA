#include <iostream>

// 5575번 타임 카드 

using namespace std;

int h_s, m_s, s_s, h_f, m_f, s_f;

int main() {
  for(int i = 0; i < 3; i++) {
    cin >> h_s >> m_s >> s_s >> h_f >> m_f >> s_f;
    s_f -= s_s;
    if(s_f < 0) {
      s_f += 60;
      m_f--;
    }
    m_f -= m_s;
    if(m_f < 0) {
      m_f += 60;
      h_f--;
    }
    cout << h_f - h_s << " " << m_f << " " << s_f << endl;
  }
//	cin >> h_s;

  return 0;
}