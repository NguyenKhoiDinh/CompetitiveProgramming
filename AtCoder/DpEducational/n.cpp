#include <iostream>

using namespace std;
const long long inf = 100000000000007LL; 
long long dp[405][405]; 
long long cost[405][405];
int n;
long long a[405]; 

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      cost[i][j] = cost[i][j - 1] + a[j]; 
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i][i] = 0; 
  }
  for (int i = n - 1; i >= 1; i--) {
    for (int j = i + 1; j <= n; j++) {
      dp[i][j] = inf; 
      for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + cost[i][j]); 
      }
    }
  }
  cout << dp[1][n];
  return 0;
}