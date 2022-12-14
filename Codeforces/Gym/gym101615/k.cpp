#include <iostream>
#include <algorithm>
#include <math.h>
#include <fstream>

using namespace std;
const int MAX_N = 45;
const int inf = 100000007;
int dp[MAX_N][2][2];
string N;

void update(int &a, int b) {
  a = min(a, b);
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> N;
  reverse(N.begin(), N.end());
  int len = (int) N.size();
  N = "0" + N;
  for (int i = 0; i <= len; i++) {
    for (int remember1 = 0; remember1 <= 1; remember1++) {
      for (int remember2 = 0; remember2 <= 1; remember2++) {
        dp[i][remember1][remember2] = inf;
      }
    }
  }
  dp[0][0][0] = 0;
  dp[0][0][1] = 0;
  for (int l = 0; l < (len + 1) / 2; l++) {
    int r = len + 1 - l;
    for (int remember1 = 0; remember1 <= 1; remember1++) {
      for (int remember2 = 0; remember2 <= 1; remember2++) {
        if (dp[l][remember1][remember2] == inf) {
          continue;
        }
        int curVal = dp[l][remember1][remember2];
        for (int digit = 0; digit <= 9; digit++) {
          int total = 0;
          int newRemember1 = 0;
          if (N[l + 1] - '0' + remember1 > digit) {
            total += 10 - (N[l + 1] - '0' + remember1) + digit;
            newRemember1 = 1;
          }
          else {
            total += digit - (N[l + 1] - '0' + remember1);
            newRemember1 = 0;
          }
          for (int newRemember2 = 0; newRemember2 <= 1; newRemember2++) {
            int valRight = N[r - 1] - '0' + newRemember2;
            int newTotal = total;
            if (remember2 == 1 && valRight <= digit) {
              continue;
            }
            if (remember2 == 0 && valRight > digit) {
              continue;
            }
            if (valRight <= digit) {
              newTotal += digit - valRight;
            }
            else {
              newTotal += 10 - valRight + digit;
            }
            update(dp[l + 1][newRemember1][newRemember2], curVal + newTotal);
          }
        }
      }
    }
  }
  int ans = inf;
  if (len % 2 == 0) {
    for (int remember = 0; remember <= 1; remember++) {
      ans = min(ans, dp[(len + 1) / 2][remember][remember]);
    }
  }
  else {
    for (int remember1 = 0; remember1 <= 1; remember1++) {
      for (int remember2 = 0; remember2 <= 1; remember2++) {
        ans = min(ans, dp[(len + 1) / 2][remember1][remember2]);
      }
    }
  }
  cout << ans;
  return 0;
}