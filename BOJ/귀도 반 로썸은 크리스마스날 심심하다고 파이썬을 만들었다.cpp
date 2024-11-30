#include <iostream>

// 6568번 귀도 반 로썸은 크리스마스날 심심하다고 파이썬을 만들었다

using namespace std;

struct computer{
  unsigned char pc : 5;
  unsigned char cnt;
};

string input;
unsigned char mem[32], now;

int main() {
  while(1) { // 입력이 여러개 
    computer process = {}; // 구조체 초기화 이슈 
    for(int i = 0; i < 32; i++) {
      cin >> input;
      if(cin.eof()) return 0; // 여러 입력 안받음 
      for(int j = 0; j < 8; j++) {
        mem[i] <<= 1;
        mem[i] |= input[j] == '1';
      }
    }
    while(1) {
      now = mem[process.pc++];
      int type = 0, num = 0;
      for(int i = 7; i >= 5; i--) {
        type <<= 1;
        type |= now >> i & 1;
      }
      if(type == 7) break;
      for(int i = 4; i >= 0; i--) {
        num <<= 1;
        num |= now >> i & 1;
      }
      switch(type) {
        case 0:
          mem[num] = process.cnt;
          break;
        case 1:
          process.cnt = mem[num];
          break;
        case 2:
          if(!process.cnt) process.pc = num;
          break;
        case 4:
          process.cnt--;
          break;
        case 5:
          process.cnt++;
          break;
        case 6:
          process.pc = num;
      }
    }
    for(int j = 7; j >= 0; j--) {
      cout << (process.cnt >> j & 1);
    }
    cout << endl;
  }
  return 0;
} 