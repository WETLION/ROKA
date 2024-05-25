#include <iostream>
#include <cstdlib>

// 10866번 덱

using namespace std;

class deque{
  public:
    deque() {
      cnt = 0;
    }
    void push_front(int number) {
      node *ne = (node*)malloc(sizeof(node));
      if(empty()) {
        start = end = ne;
      }
      else {
        ne -> next = start;
        start -> previous = ne;
        start = ne;
      }
      ne -> num = number;
      cnt++;
    }
    void push_back(int number) {
      node *ne = (node*)malloc(sizeof(node));
      if(empty()) {
        start = end = ne;
      }
      else {
        ne -> previous = end;
        end -> next = ne;
        end = ne;
      }
      ne -> num = number;
      cnt++;
    }
    int pop_front() {
      int re = front();
      if(re != -1) {
        node *del = start;
        start = start -> next;
        free(del);
        cnt--;
      }
      return re;
    }
    int pop_back() {
      int re = back();
      if(re != -1) {
        node *del = end;
        end = end -> previous;
        free(del);
        cnt--;
      }
      return re;
    }
    int size() {
      return cnt;
    }
    bool empty() {
      return !cnt;
    }
    int front() {
      return cnt ? start -> num : -1;
    }
    int back() {
      return cnt ? end -> num : -1;
    }
  private:
    int cnt;
    typedef struct _node {
      struct _node *previous, *next;
      int num;
    }node;
    node *start, *end;
};

int n, in;
string input;
deque dq;

int main() {
  cin >> n;
  while(n--) {
    cin >> input;
    if(input == "push_front") {
      cin >> in;
      dq.push_front(in);
    }
    else if(input == "push_back") {
      cin >> in;
      dq.push_back(in);
    }
    else if(input == "pop_front") {
      cout << dq.pop_front() << endl;
    }
    else if(input == "pop_back") {
      cout << dq.pop_back() << endl;
    }
    else if(input == "size") {
      cout << dq.size() << endl;
    }
    else if(input == "empty") {
      cout << dq.empty() << endl;
    }
    else if(input == "front") {
      cout << dq.front() << endl;
    }
    else {
      cout << dq.back() << endl;
    }
  }

  return 0;
}