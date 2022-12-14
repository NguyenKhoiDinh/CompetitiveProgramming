#include <bits/stdc++.h>

using namespace std;
double prob[3005]; 
double dp[3005][3005]; 
int n; 

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> prob[i]; 
  }
  dp[0][0] = 1.0; 
  for (int i = 0; i < n; i++) {
    for (int head = 0; head <= i; head++) {
      if (dp[i][head] == 0.0) {
        continue; 
      }
      dp[i + 1][head + 1] += dp[i][head] * prob[i + 1]; 
      dp[i + 1][head] += dp[i][head] * (1.0 - prob[i + 1]); 
    }
  }
  double ans = 0.0; 
  for (int head = 0; head <= n; head++) {
    int tail = n - head; 
    if (head > tail) {
      ans += dp[n][head]; 
    }
  } 
  cout << fixed << setprecision(12) << ans;
  return 0;
}