#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
const int MAX_N = 12;
const int MAX_X = 705;
long long dp[(1 << MAX_N) + 5][MAX_N + 3][MAX_X];
int score[MAX_N];
int n, X;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n >> X;
  for (int i = 0; i < n; i++) {
    cin >> score[i];
  }
  sort(score, score + n);
  dp[0][n - 1][0] = 1;
  for (int mask = 0; mask < (1 << n); mask++) {
    int numSingers = (int) __builtin_popcount(mask);
    for (int best = 0; best < n; best++) {
      for (int total = 0; total <= X; total++) {
        if (dp[mask][best][total] == 0) {
          continue;
        }
        for (int i = 0; i < n; i++) {
          if ((mask & (1 << i)) > 0 || i == best) {
            continue;
          }
          int add = max(0, score[best] - score[i] + 1);
          if (total + (n - numSingers) * add > X) {
            continue;
          }
          int newTotal = total + (n - numSingers) * add;
          dp[mask + (1 << i)][i][newTotal] += dp[mask][best][total];
        }
      }
    }
  }
  long long ans = 0LL;
  for (int best = 0; best < n; best++) {
    for (int total = 0; total <= X; total++) {
      ans += dp[(1 << n) - 1][best][total];
    }
  }
  cout << ans;
  return 0;
}