#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 33;
const int MAX_SUM = 1005;
long long dpSmall[MAX_N][MAX_SUM * MAX_N], dpLarge[MAX_N][MAX_SUM * MAX_N];
long long C[MAX_N][MAX_N];

void DynamicProgramming(long long dp[MAX_N][MAX_SUM * MAX_N], vector <int> &values) {
  int n = (int) values.size();
  dp[0][0] = 1LL;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += values[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= sum; j++) {
      if (dp[i][j] == 0) {
        continue;
      }
      dp[i + 1][j] += dp[i][j];
      if (j + values[i] <= sum) {
        dp[i + 1][j + values[i]] += dp[i][j];
      }
    }
  }
}

class Jewelry {
  public:
  long long howMany(vector <int> values) {
    long long ans = 0LL;
    sort(values.begin(), values.end());
    vector <int> revValues = values;
    reverse(revValues.begin(), revValues.end());
    DynamicProgramming(dpSmall, values);
    DynamicProgramming(dpLarge, revValues);
    int n = (int) values.size();
    for (int i = 0; i <= n; i++) {
      C[i][0] = 1;
      C[i][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += values[i];
    }
    values.push_back(1007);
    int l = 0;
    for (int j = 1; j <= sum; j++) {
      l = 0;
      for (int i = 1; i <= n; i++) {
        if (values[i] != values[i - 1]) {
          int r = i - 1;
          int countSameValue = r - l + 1;
          for (int forSmall = 1; forSmall <= countSameValue; forSmall++) {
            for (int forLarge = 0; forLarge <= countSameValue - forSmall; forLarge++) {
              if (j < max(forSmall, forLarge) * values[i - 1]) {
                continue;
              }
              long long mul = dpSmall[l][j - forSmall * values[i - 1]];
              mul *= C[countSameValue][forSmall];
              mul *= dpLarge[n - r - 1][j - forLarge * values[i - 1]];
              mul *= C[countSameValue - forSmall][forLarge];
              ans += mul;
            }
          }
          l = i;
        }
      }
    }
    return ans;
  }
};

Jewelry J;

int main () {
  cout << J.howMany({7,7,8,9,10,11,1,2,2,3,4,5,6});
  return 0;
}