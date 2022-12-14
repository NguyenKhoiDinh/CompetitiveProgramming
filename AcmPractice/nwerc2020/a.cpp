#include <bits/stdc++.h> 

using namespace std;
const int MAX_SIZE = 100 * 1000; 
const long long inf = 10000000000007LL; 
long long dp[MAX_SIZE + 5]; 
int n, numQuery; 
int a[105]; 

int main () {
  cin >> n >> numQuery;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int best = 1; 
  for (int i = 1; i <= n; i++) {
    if (1LL * a[i] * best < 1LL * i * a[best]) {
      best = i; 
    }
  }
  for (int i = 1; i <= MAX_SIZE; i++) {
    dp[i] = inf; 
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = a[i]; 
  }
  for (int i = n + 1; i <= MAX_SIZE; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i] = min(dp[i], dp[i - j] + a[j]); 
    }
  }
  for (int query = 1; query <= numQuery; query++) {
    int k;
    cin >> k; 
    if (k <= MAX_SIZE) {
      cout << dp[k] << endl; 
    }
    else {
      long long ans = inf; 
      int delta = k - MAX_SIZE; 
      int numb = (delta + best - 1) / best; 
      int rem = k - numb * best; 
      ans = dp[rem] + 1LL * numb * a[best];   
      cout << ans << endl;
    }
  }
  return 0;
}