#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 55;
int dp[MAX_N];

class ZigZag {
  public:
  int longestZigZag(vector <int> sequence) {
    int n = (int) sequence.size();
    vector <int> a;
    for (int i = 1; i < n; i++) {
      a.push_back(sequence[i] - sequence[i - 1]);
    }
    int res = -1;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] != 0) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
          if (a[j] * a[i] < 0) {
            dp[i] = max(dp[i], dp[j] + 1);
          }
        }
        res = max(res, dp[i]);
      }
    }
    return (res + 1);
  }
};

int main () {
  return 0;
}