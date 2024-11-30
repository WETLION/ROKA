#include <iostream>

// 17478번 재귀함수가 뭔가요? 

using namespace std;

int n;
string arr[10] = {"\"재귀함수가 뭔가요?\"", "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.", "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"", "라고 답변하였지."},
last[5] = {"\"재귀함수가 뭔가요?\"", "\"재귀함수는 자기 자신을 호출하는 함수라네\"", "라고 답변하였지."};

void recursion(int num) {
  if(num == n) {
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < num; j++) {
        cout << "____";
      }
      cout << last[i] << endl;
    }
    return;
  }
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < num; j++) {
      cout << "____";
    }
    cout << arr[i] << endl;
    if(i == 3) recursion(num + 1);
  }
}

int main() {
  cin >> n;
  cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;
  recursion(0);
  cin >> n;

  return 0;
} 