#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 44; 
int dp[MAX_N][2]; 

class NumberofFiboCalls {
  public: 
  vector <int> fiboCallsMade(int n) {
    dp[0][0] = 1;
    dp[1][1] = 1; 
    for (int i = 2; i <= n; i++) {
      dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
      dp[i][1] = dp[i - 1][1] + dp[i - 2][1]; 
    }
    vector <int> ans;
    ans.push_back(dp[n][0]);
    ans.push_back(dp[n][1]);
    return ans; 
  }
};

int main () {
  return 0; 
}
