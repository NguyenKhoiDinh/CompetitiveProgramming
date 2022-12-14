#include <bits/stdc++.h> 

using namespace std;
long long dp[15][1000005]; 
int a[15]; 
int n, X; 

int main () {
  cin >> X >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
  }
  sort(a + 1, a + n + 1); 
  vector <int> b; 
  b.push_back(0); 
  b.push_back(a[1]); 
  for (int i = 2; i <= n; i++) {
    if (a[i] != a[i - 1]) {
      b.push_back(a[i]); 
    }
  }
  n = (int) b.size(); 
  dp[0][0] = 1; 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= X; j++) {
      if (dp[i][j] == 0) {
        continue; 
      }
      dp[i + 1][j] += dp[i][j];
      if (j + a[i] <= X) {
        dp[i][j + b[i]] += dp[i][j];
      }
    }
  }
  cout << dp[n][X]; 
  return 0; 
}