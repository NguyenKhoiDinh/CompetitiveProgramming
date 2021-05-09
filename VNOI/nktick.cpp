#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 60005; 
int t[MAX_N], r[MAX_N];
int n; 
int dp[MAX_N];

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i]; 
  }
  for (int i = 1; i < n; i++) {
    cin >> r[i]; 
  }
  dp[1] = t[1]; 
  dp[2] = min(t[1] + t[2], r[1]); 
  for (int i = 3; i <= n; i++) {
    dp[i] = min(dp[i - 1] + t[i], dp[i - 2] + r[i - 1]); 
  }
  cout << dp[n];
  return 0; 
}