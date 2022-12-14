#include <bits/stdc++.h>

using namespace std;
const int mod = 1000000007; 
int dp[(1 << 21) + 5]; 
int a[23][23]; 
int n; 

int main () {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j]; 
    }
  }
  dp[0] = 1; 
  for (int mask = 1; mask < (1 << n); mask++) {
    int numbMan = (int) __builtin_popcount(mask); 
    for (int i = 0; i < n; i++) {
      if ((mask & (1 << i)) > 0 && a[i][numbMan - 1] == 1) {
        (dp[mask] += dp[mask - (1 << i)]) %= mod; 
      }
    }
  }
  cout << dp[(1 << n) - 1];
  return 0;
}