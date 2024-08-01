#include <iostream>

// 28235번 코드마스터 2023

using namespace std;

string input;

int main() {
  cin >> input;
  if(input == "SONGDO") cout << "HIGHSCHOOL";
  else if(input == "CODE") cout << "MASTER";
  else if(input == "2023") cout << "0611";
  else cout << "CONTEST";

  return 0;
}