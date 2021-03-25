#include <iostream>
#include <set>
#include <fstream>

using namespace std;
const int MAX_N = 105;
long long dp[15][MAX_N][MAX_N];
int n, m, numBlur;
int a[MAX_N][MAX_N];
int dx[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
int dy[9] = {0, 1, -1, 0, 0, 1, -1, -1, 1};

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> m >> n >> numBlur;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[0][i][j] = a[i][j];
    }
  }
  for (int step = 0; step < numBlur; step++) {
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < m; y++) {
        for (int i = 0; i < 9; i++) {
          int nextx = x + dx[i];
          int nexty = y + dy[i];
          if (nextx < 0) {
            nextx = n - 1;
          }
          else if (nextx >= n) {
            nextx = 0;
          }
          if (nexty < 0) {
            nexty = m - 1;
          }
          else if (nexty >= m) {
            nexty = 0;
          }
          dp[step + 1][nextx][nexty] += dp[step][x][y];
        }
      }
    }
  }
  set <long long> S;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      S.insert(dp[numBlur][x][y]);
    }
  }
  cout << (int) S.size();
  return 0;
}