#include <iostream>

// 2083번 럭비 클럽

using namespace std;

string name;
int age, weight;

int main() {
  while (1) {
    cin >> name >> age >> weight;
    if (name == "#" && !age && !weight)
      break;
    cout << name;
    if (age > 17 || weight >= 80)
      cout << " Senior" << endl;
    else
      cout << " Junior" << endl;
  }
}