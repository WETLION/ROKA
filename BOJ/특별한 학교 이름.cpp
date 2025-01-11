#include <iostream>

// 27889번 특별한 학교 이름 

using namespace std;

string str;

int main() {
  cin >> str;
  if(str == "NLCS")
    cout << "North London Collegiate School";
  if(str == "BHA")
    cout << "Branksome Hall Asia";
  if(str == "KIS")
    cout << "Korea International School";
  if(str == "SJA")
    cout << "St. Johnsbury Academy";

  return 0;
}