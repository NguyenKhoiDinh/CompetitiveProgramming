#include <iostream>

using namespace std;

struct segment {
  int left, right;
};
const int MAX_N = 100005;
const int MAX_DIMENSION = 70;
long long a[MAX_N];
int dp[MAX_DIMENSION][MAX_DIMENSION][2], count[MAX_DIMENSION][MAX_DIMENSION];
segment rangeValue[MAX_DIMENSION];
int n;

bool checkContinuous() {
  if (count[0][0] == 0) {
    return false;
  }
  for (int y = 0; y < MAX_DIMENSION; y++) {
    int l = -1;
    int r = -1;
    for (int x = 0; x < MAX_DIMENSION; x++) {
      if (count[x][y] > 0) {
        r = x;
      }
    }
    for (int x = MAX_DIMENSION - 1; x >= 0; x--) {
      if (count[x][y] > 0) {
        l = x;
      }
    }
    if (l != -1 && r != -1) {
      for (int x = l; x <= r; x++) {
        if (count[x][y] == 0) {
          return false;
        }
      }
    }
  }
  bool check = true;
  for (int y = 0; y < MAX_DIMENSION; y++) {
    if (rangeValue[y].left == -1 && rangeValue[y].right == -1) {
      check = false;
    }
    else {
      if (check == true) {
        return false;
      }
    }
  }
  return true;
}

void DynamicProgramming() {

}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  while (true) {
    cin >> n;
    if (n == 0) {
      break;
    }
    for (int x = 0; x < MAX_DIMENSION; x++) {
      for (int y = 0; y < MAX_DIMENSION; y++) {
        count[x][y] = 0;
        dp[x][y][0] = dp[x][y][1] = 0;
      }
    }
    for (int y = 0; y < MAX_DIMENSION; y++) {
      rangeValue[y].left = -1;
      rangeValue[y].right = -1;
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    bool check = true;
    for (int i = 1; i <= n; i++) {
      long long val = a[i];
      int numb2 = 0, numb3 = 0;
      while (val % 2 == 0) {
        numb2++:
        val /= 2;
      }
      while (val % 3 == 0) {
        numb3++;
        val /= 3;
      }
      if (val != 1) {
        check = false;
        break;
      }
      count[numb2][numb3]++;
    }
    if (check == false) {
      cout << "NO" << endl;
      continue;
    }
    if (checkContinuous() == false) {
      cout << "NO" << endl;
      continue;
    }
    DynamicProgramming();
  }
  return 0;
}