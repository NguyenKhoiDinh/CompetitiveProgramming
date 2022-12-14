#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX_N = 1005;
const int inf = 1000000007;

struct cow {
  int x, y;
  bool operator < (const cow &hs) const {
    if (y < hs.y || (y == hs.y && x < hs.x)) {
      return true;
    }
    return false;
  }
};

vector <cow> listCows;
int dp[MAX_N][MAX_N][3];
int n, K, B;
int numTest;

void updateMin(int &a, int b) {
  a = min(a, b);
}

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> K >> B;
    listCows.clear();
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= K; j++) {
        for (int status = 0; status < 3; status++) {
          dp[i][j][status] = inf;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      int x, y;
      cin >> x >> y;
      listCows.push_back((cow) {x, y});
    }
    sort(listCows.begin(), listCows.end());
    dp[1][1][0] = 1;
    dp[1][1][1] = 2;
    if (K >= 2) {
      dp[1][2][2] = 2;
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= K; j++) {
        for (int status = 0; status <= 2; status++) {
          if (dp[i][j][status] == inf) {
            continue;
          }
          int val = dp[i][j][status];
          if (i == n) {
            continue;
          }
          if (status == 0) {
            if (listCows[i - 1].y == listCows[i].y) {
              if (j < K) {
                updateMin(dp[i + 1][j + 1][2], val + 1);
              }
            }
            else {
              if (j < K) {
                updateMin(dp[i + 1][j + 1][0], val + 1);
                updateMin(dp[i + 1][j + 1][1], val + 2);
                updateMin(dp[i + 1][j + 1][2], val + listCows[i].y - listCows[i - 1].y + 1);
                if (j + 2 <= K) {
                  updateMin(dp[i + 1][j + 2][2], val + 2);
                }
              }
              if (listCows[i - 1].x == listCows[i].x) {
                updateMin(dp[i + 1][j][0], val + listCows[i].y - listCows[i - 1].y);
              }
            }
          }
          else if (status == 1) {
            if (listCows[i - 1].y < listCows[i].y) {
              if (j < K) {
                updateMin(dp[i + 1][j + 1][0], val + 1);
                updateMin(dp[i + 1][j + 1][1], val + 2);
                if (j + 2 <= K) {
                  updateMin(dp[i + 1][j + 2][2], val + 2);
                }
              }
              updateMin(dp[i + 1][j][1], val + 2 * (listCows[i].y - listCows[i - 1].y));
            }
            else {
              updateMin(dp[i + 1][j][1], val);
            }
          }
          else {
            if (listCows[i - 1].y < listCows[i].y) {
              if (j < K) {
                updateMin(dp[i + 1][j + 1][0], val + 1);
                updateMin(dp[i + 1][j + 1][1], val + 2);
                updateMin(dp[i + 1][j + 1][2], val + listCows[i].y - listCows[i - 1].y + 1);
              }
              if (j + 2 <= K) {
                updateMin(dp[i + 1][j + 2][2], val + 2);
              }
              updateMin(dp[i + 1][j][0], val + listCows[i].y - listCows[i - 1].y);
              updateMin(dp[i + 1][j][2], val + 2 * (listCows[i].y - listCows[i - 1].y));
            }
            else {
              updateMin(dp[i + 1][j][2], val);
            }
          }
        }
      }
    }
    int ans = inf;
    for (int status = 0; status <= 2; status++) {
      ans = min(ans, dp[n][K][status]);
    }
    cout << ans << endl;
  }
  return 0;
}