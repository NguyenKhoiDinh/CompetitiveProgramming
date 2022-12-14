#include <iostream>
#include <fstream>

using namespace std;
const int MAX_N = 200005;
int numTest;
int cnt[MAX_N];
int a[MAX_N];
int n;
int dp[MAX_N];

void solve() {
  int res = 0;
  for (int i = 200000; i >= 1; i--) {
    if (cnt[i] > 0) {
      dp[i] = cnt[i];
      for (int j = 2 * i; j < MAX_N; j += i) {
        dp[i] = max(dp[i], dp[j] + cnt[i]);
      }
      res = max(res, dp[i]);
    }
  }
  cout << n - res << endl;
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i < MAX_N; i++) {
      cnt[i] = 0;
      dp[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    solve();
  }
  return 0;
}