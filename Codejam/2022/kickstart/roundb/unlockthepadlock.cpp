#include <bits/stdc++.h> 

using namespace std; 
const long long inf = 10000000000007LL; 
int numTest; 
long long dp[405][405][2]; 
long long a[405]; 
int n;
long long D; 

long long value(int p1, int p2) {
  return min(abs(a[p1] - a[p2]), D - abs(a[p1] - a[p2])); 
}

int main () {
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> D;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    } 
    a[0] = 0; 
    a[n + 1] = 0;
    for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j <= n + 1; j++) {
        for (int state = 0; state <= 1; state++) {
          dp[i][j][state] = inf; 
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      dp[i][i][0] = value(i, i - 1); 
      dp[i][i][1] = value(i, i + 1); 
    }                       
    for (int i = n - 1; i >= 1; i--) {
      for (int j = i + 1; j <= n; j++) {
        dp[i][j][0] = min(dp[i + 1][j][0] + value(i, i - 1), dp[i][j - 1][1] + value(j, i - 1)); 
        dp[i][j][1] = min(dp[i + 1][j][0] + value(i, j + 1), dp[i][j - 1][1] + value(j, j + 1)); 
      }                                                                                
    }
    long long ans = min(dp[1][n][0], dp[1][n][1]); 
    cout << ans << endl; 
  }
  return 0; 
}