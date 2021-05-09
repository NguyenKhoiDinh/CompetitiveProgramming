#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 33; 
int numTest; 
long long dp[MAX_N][(1 << 6) + 5];
int n, m; 

bool check(int mask, int newmask) {
  for (int b = 0; b < n - 1; b++) {
    int v1 = ((mask & (1 << b)) > 0);
    int v2 = ((mask & (1 << (b + 1))) > 0);
    int v3 = ((newmask & (1 << b)) > 0);
    int v4 = ((newmask & (1 << (b + 1))) > 0);
    if (v1 == v2 && v2 == v3 && v3 == v4) {
      return false; 
    }
  }
  return true; 
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    if (n > m) {
      swap(n, m);
    }
    memset(dp, 0, sizeof(dp));
    for (int mask = 0; mask < (1 << n); mask++) {
      dp[1][mask] = 1LL;
    } 
    for (int i = 1; i < m; i++) {
      for (int mask = 0; mask < (1 << n); mask++) {
        if (dp[i][mask] == 0) {
          continue; 
        }
        for (int newmask = 0; newmask < (1 << n); newmask++) {
          bool flag = check(mask, newmask);  
          if (flag == true) {
            dp[i + 1][newmask] += dp[i][mask];
          }
        }
      }
    }
    long long ans = 0; 
    for (int mask = 0; mask < (1 << n); mask++) {
      ans += dp[m][mask]; 
    }
    cout << ans << endl; 
  }
  return 0; 
}