#include <bits/stdc++.h>

using namespace std; 
const int MAX_N = 1505; 
const int inf = 1000005; 
int a[MAX_N], b[MAX_N];
int n, m, numTest; 
int dp[MAX_N]; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }
    for (int i = 1; i <= m; i++) {
      cin >> b[i]; 
    }
    for (int i = 1; i <= m; i++) {
      dp[i] = 0; 
    }
    for (int i = 1; i <= n; i++) {
      int maxLength = 0; 
      for (int j = 1; j <= m; j++) {
        int prev = maxLength; 
        if (2 * b[j] <= a[i]) {
          maxLength = max(maxLength, dp[j]);
        }
        if (a[i] == b[j]) {
          dp[j] = max(dp[j], prev + 1); 
        }
      }
    }
    int ans = 0; 
    for (int i = 1; i <= m; i++) {
      ans = max(ans, dp[i]); 
    }
    cout << ans << endl;
  }
  return 0; 
}