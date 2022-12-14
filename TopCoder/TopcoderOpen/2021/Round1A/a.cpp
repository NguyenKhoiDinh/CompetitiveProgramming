#include <bits/stdc++.h> 

using namespace std;

char consonant[5] = {'A', 'E', 'I', 'U', 'O'}; 
const int MAX_N = 105; 
const int inf = 10000006; 
int dp[MAX_N][MAX_N];

class EllysBalancedStrings {
  public: 
  int getMin(string S) {
    int n = (int) S.size();
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        dp[i][j] = inf; 
      }
    } 
    dp[0][0] = 0; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        if (dp[i][j] == inf) {
          continue; 
        }
        for (int c = 0; c <= 25; c++) {
          char nextChar = (char) (c + 'A'); 
          bool flag = false; 
          for (int p = 0; p < 5; p++) {
            if (nextChar == consonant[p]) {
              flag = true; 
              break; 
            }
          }
          if (flag == true) {
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(nextChar - S[i]));
          }
          else {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + abs(nextChar - S[i]));
          }
        }
      }
    }
    return dp[n][n / 2]; 
  }
};

EllysBalancedStrings E; 

int main () {
  cout << E.getMin("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  return 0; 
}
