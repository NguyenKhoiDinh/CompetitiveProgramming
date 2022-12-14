#include <iostream>
#include <string>
#include <math.h>

using namespace std;
const int MAX_N = 100005;
int dp[MAX_N][4][4][4];
int shipment[MAX_N];
string dish;
int n;

int calc(int a, int b, int c) {
  int res = 0;
  if (a == 1 || b == 1 || c == 1) {
    res++;
  }
  if (a == 2 || b == 2 || c == 2) {
    res++;
  }
  if (a == 3 || b == 3 || c == 3) {
    res++;
  }
  return res;
}

void updateMax(int &a, int b) {
  a = max(a, b);
}

int main () {
  cin >> n;
  cin >> dish;
  for (int i = 1; i <= n; i++) {
    if (dish[i - 1] == 'M') {
      shipment[i] = 1;
    }
    else if (dish[i - 1] == 'B') {
      shipment[i] = 2;
    }
    else {
      shipment[i] = 3;
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int a = 0; a <= 3; a++) {
      for (int b = 0; b <= 3; b++) {
        for (int c = 0; c <= 3; c++) {
          dp[i][a][b][c] = -1;
        }
      }
    }
  }
  dp[1][0][0][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int a = 0; a <= 3; a++) {
      for (int b = 0; b <= 3; b++) {
        for (int c = 0; c <= 3; c++) {
          if (dp[i][a][b][c] == -1) {
            continue;
          }
          int cur = dp[i][a][b][c];
          // shipment[i + 1] vào hàng 1
          updateMax(dp[i + 1][shipment[i]][b][c], cur + calc(shipment[i + 1], shipment[i], a));
          // shipment[i + 1] vào hàng 2
          updateMax(dp[i + 1][b][shipment[i]][a], cur + calc(shipment[i + 1], b, c));
        }
      }
    }
  }
  int res = -1;
  for (int a = 0; a <= 3; a++) {
    for (int b = 0; b <= 3; b++) {
      for (int c = 0; c <= 3; c++) {
        res = max(res, dp[n][a][b][c]);
      }
    }
  }
  cout << res;
  return 0;
}