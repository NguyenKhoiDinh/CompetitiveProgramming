#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 505;
const long long inf = 1000000000000007LL;
long long dp[MAX_N][MAX_N];

void updateMin(long long &a, long long b) {
  a = min(a, b);
}

class AqaAsadiGroups {
  public:
  long long minimumDifference(vector <int> a, int k) {
    long long S = 0;
    int n = (int) a.size();
    for (int i = 0; i < n; i++) {
      S += a[i];
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        dp[i][j] = inf;
      }
    }
    dp[0][0] = 0;
    for (int j = 0; j < k; j++) {
      for (int i = 0; i <= n; i++) {
        if (dp[i][j] == inf) {
          continue;
        }
        long long curVal = dp[i][j];
        long long sum = 0LL;
        updateMin(dp[i][j + 1], curVal + S * S);
        for (int t = i + 1; t <= n; t++) {
          sum += a[t - 1];
          updateMin(dp[t][j + 1], curVal + (S - sum * k) * (S - sum * k));
        }
      }
    }
    return dp[n][k];
  }
};

int main () {
  return 0;
}