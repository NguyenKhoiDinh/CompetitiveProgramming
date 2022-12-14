#include <bits/stdc++.h> 

using namespace std; 

long long dp[100005]; 
long long a[100005]; 
int n; 

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[1] = 0; 
  dp[2] = abs(a[2] - a[1]); 
  for (int i = 3; i <= n; i++) {
    dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2])); 
  }
  cout << dp[n];
  return 0; 
}