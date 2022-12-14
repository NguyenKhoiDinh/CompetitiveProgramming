#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 1005;
const int inf = 1000005;  
int dp[MAX_N][MAX_N]; 

class EmoticonsDiv2 {
  public: 
  int printSmiles(int n) {
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        dp[i][j] = inf; 
      }
    }      
    dp[1][0] = 0; 
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        if (dp[i][j] == inf) {
          continue; 
        }
        if (j < i) {
          dp[i][i] = min(dp[i][i], dp[i][j] + 1); 
        }
        if (i + j <= n) {
          dp[i + j][j] = min(dp[i + j][j], dp[i][j] + 1); 
        }
      }
    }
    int ans = inf;
    for (int j = 0; j <= n; j++) {
      ans = min(ans, dp[n][j]); 
    }
    return ans;
  }
};

int main () {
  return 0; 
}