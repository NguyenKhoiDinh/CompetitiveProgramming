#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 105; 
const int inf = 10000006; 
int dp[MAX_N][26][2]; 

class EllysTwinLetters {
  public: 
  int getMin(string S) {
    int n = (int) S.size();
    for (int i = 1; i <= n; i++) {
      for (int c = 0; c < 26; c++) {
        dp[i][c][0] = dp[i][c][1] = inf; 
      }
    } 
    for (int c = 0; c < 26; c++) {
      dp[1][c][0] = abs(S[0] - (c + 'A')); 
    }
    for (int i = 1; i < n; i++) {
      for (int c = 0; c < 26; c++) {
        for (int status = 0; status <= 1; status++) {
          if (dp[i][c][status] == inf) {
            continue; 
          }
          dp[i + 1][c][1] = min(dp[i + 1][c][1], dp[i][c][status] + abs(S[i] - (c + 'A')));
          if (status == 1) {
            for (int nextc = 0; nextc < 26; nextc++) {
              if (nextc != c) {
                dp[i + 1][nextc][0] = min(dp[i + 1][nextc][0], dp[i][c][status] + abs(S[i] - (nextc + 'A')));
              }
            } 
          }
        }
      }
    }
    int ans = inf; 
    for (int c = 0; c < 26; c++) {
      ans = min(ans, dp[n][c][1]); 
    }
    return ans; 
  }
};

EllysTwinLetters E; 

int main () {
  cout << E.getMin("FROMALLTHETHINGSIVELOSTMYMINDIMISSTHEMOST");
  return 0; 
}
