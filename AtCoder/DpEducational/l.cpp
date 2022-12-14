#include <iostream>

using namespace std;
long long a[3005]; 
long long sum[3005];
long long dp[3005][3005]; 
int n; 

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i]; 
  }
  for (int i = 1; i <= n; i++) {
    dp[i][i] = a[i];
  }
  for (int l = n - 1; l >= 1; l--) {
    for (int r = l + 1; r <= n; r++) {
      dp[l][r] = sum[r] - sum[l - 1] - min(dp[l + 1][r], dp[l][r - 1]); 
    }
  }
  long long X = dp[1][n];
  long long Y = sum[n] - X; 
  cout << X - Y;
  return 0;
}