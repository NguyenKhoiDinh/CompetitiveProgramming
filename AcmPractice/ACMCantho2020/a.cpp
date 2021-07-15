#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>

using namespace std;
const int MAX_N = 2005;
int dp[MAX_N][MAX_N];
pair <int, int> trace[MAX_N][MAX_N];
int n, numTest;
int a[MAX_N];

int main () {
  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < MAX_N; j++) {
      dp[i][j] = -1;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j <= 1000; j++) {
      if (dp[i][j] == -1) {
        continue;
      }
      if (dp[i + 1][j] < dp[i][j]) {
        dp[i + 1][j] = dp[i][j];
        trace[i + 1][j] = make_pair(i, j);
      }
      if (dp[i + 1][j ^ (i + 1)] < dp[i][j] + 1) {
        dp[i + 1][j ^ (i + 1)] = dp[i][j] + 1;
        trace[i + 1][j ^ (i + 1)] = make_pair(i, j);
      }
    }
  }
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int m;
    cin >> m;
    cout << dp[m][m] << endl;
    int i = m;
    int j = m;
    vector <int> res;
    while (i > 0 || j > 0) {
      pair <int, int> prev = trace[i][j];
      if (prev.second != j) {
        res.push_back(i);
      }
      i = prev.first;
      j = prev.second;
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < (int) res.size(); i++) {
      cout << res[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}