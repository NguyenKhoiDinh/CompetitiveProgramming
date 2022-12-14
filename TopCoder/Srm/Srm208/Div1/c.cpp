#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 102;
int cost[MAX_N][MAX_N];
int dp[2][MAX_N][MAX_N][MAX_N];

int calc(int x1, int y1, int x2, int y2, int x3, int y3) {
  int res = 0;
  res += cost[x1][y1];
  if (x2 != x1 || y2 != y1) {
    res += cost[x2][y2];
  }
  if ((x3 != x2 && x3 != x1) || (y3 != y2 && y3 != y1)) {
    res += cost[x3][y3];
  }
  return res;
}

void update(int &a, int b) {
  a = max(a, b);
}

class StarAdventure {
  public:
  int mostStars(vector <string> a) {
    int n = (int) a.size();
    int m = (int) a[0].size();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cost[i][j] = a[i - 1][j - 1] - '0';
      }
    }
    for (int step = 0; step <= 1; step++) {
      for (int y1 = 1; y1 <= m; y1++) {
        for (int y2 = 1; y2 <= m; y2++) {
          for (int y3 = 1; y3 <= m; y3++) {
            dp[step][y1][y2][y3] = -1;
          }
        }
      }
    }
    dp[0][1][1][1] = 0;
    for (int step = 0; step < n + m - 2; step++) {
      int curStep = step & 1;
      int nxtStep = !curStep;
      for (int y1 = 1; y1 <= m; y1++) {
        for (int y2 = 1; y2 <= m; y2++) {
          for (int y3 = 1; y3 <= m; y3++) {
            dp[nxtStep][y1][y2][y3] = -1;
          }
        }
      }
      for (int y1 = 1; y1 <= m; y1++) {
        for (int y2 = y1; y2 <= m; y2++) {
          for (int y3 = y2; y3 <= m; y3++) {
            if (dp[curStep][y1][y2][y3] == -1) {
              continue;
            }
            int curVal = dp[curStep][y1][y2][y3];
            int x1 = step + 2 - y1;
            int x2 = step + 2 - y2;
            int x3 = step + 2 - y3;
            update(dp[nxtStep][y1][y2][y3], curVal + calc(x1 + 1, y1, x2 + 1, y2, x3 + 1, y3));
            if (y1 + 1 <= m) {
              update(dp[nxtStep][y1 + 1][y2][y3], curVal + calc(x1, y1 + 1, x2 + 1, y2, x3 + 1, y3));
            }
            if (y2 + 1 <= m) {
              update(dp[nxtStep][y1][y2 + 1][y3], curVal + calc(x1 + 1, y1, x2, y2 + 1, x3 + 1, y3));
              update(dp[nxtStep][y1 + 1][y2 + 1][y3], curVal + calc(x1, y1 + 1, x2, y2 + 1, x3 + 1, y3));
            }
            if (y3 + 1 <= m) {
              update(dp[nxtStep][y1][y2][y3 + 1], curVal + calc(x1 + 1, y1, x2 + 1, y2, x3, y3 + 1));
              update(dp[nxtStep][y1][y2 + 1][y3 + 1], curVal + calc(x1 + 1, y1, x2, y2 + 1, x3, y3 + 1));
              update(dp[nxtStep][y1 + 1][y2][y3 + 1], curVal + calc(x1, y1 + 1, x2 + 1, y2, x3, y3 + 1));
              update(dp[nxtStep][y1 + 1][y2 + 1][y3 + 1], curVal + calc(x1, y1 + 1, x2, y2 + 1, x3, y3 + 1));
            }
          }
        }
      }
    }
    return dp[(n + m - 2) & 1][m][m][m];
  }
};

StarAdventure S;

int main () {
  cout << S.mostStars({"0123456789",
 "1123456789",
 "2223456789",
 "3333456789",
 "4444456789",
 "5555556789",
 "6666666789",
 "7777777789",
 "8888888889",
 "9999999999"});
  return 0;
}