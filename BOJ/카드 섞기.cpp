#include <iostream>

// 1091번 카드 섞기

using namespace std;

struct node {
  int num, player;
};

int first_card[50], mix[50], card_arr[50];

int n;

bool card_arr_is_first() {
  for (int i = 0; i < n; i++) {
    if (card_arr[i] != first_card[i])
      return 0;
  }
  return 1;
}

bool card_arr_is_ans() {
  for (int i = 0; i < n; i++) {
    if (card_arr[i] != i % 3)
      return 0;
  }
  return 1;
}

void copy_card_arr(int copy[], int arr[]) {
  for (int i = 0; i < n; i++) {
    copy[i] = arr[i];
  }
}

void card_arr_mix() {
  int copy[50] = {};
  copy_card_arr(copy, card_arr);
  for (int i = 0; i < n; i++) {
    card_arr[mix[i]] = copy[i];
  }
}

void print_card() {
  for (int i = 0; i < n; i++) {
    cout << card_arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> card_arr[i];
    first_card[i] = card_arr[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> mix[i];
  }
  while (1) {
    if (card_arr_is_ans()) {
      cout << cnt;
      break;
    }
    card_arr_mix();
    cnt++;
    // print_card();
    if (card_arr_is_first()) {
      cout << -1;
      break;
    }
  }

  return 0;
}