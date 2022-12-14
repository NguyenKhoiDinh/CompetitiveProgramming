#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 105; 
long long dp[MAX_N][MAX_N][MAX_N];
long long waysLeft[MAX_N][4 * MAX_N], waysRight[MAX_N][4 * MAX_N];
long long C[MAX_N][MAX_N]; 

class BearPermutations {
  public: 
  int countPermutations(int N, int S, int MOD) {
    for (int i = 0; i <= N; i++) {
      C[i][0] = 1;
      C[i][i] = 1; 
    }
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j < i; j++) {
        C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD; 
      }
    }
    dp[1][1][0] = 1;
    waysLeft[1][1] = 1;
    waysRight[1][1] = 1;
    for (int i = 2; i <= N; i++) {
      for (int sum = 0; sum <= S; sum++) {
        for (int where = 1; where <= i; where++) {
          if (where == 1 || where == i) {
            for (int otherWhere = 1; otherWhere <= i; otherWhere++) {
              (dp[i][where][sum] += dp[i - 1][otherWhere][sum]) %= MOD; 
            }
          }
          else {                        
            for (int value = where; value <= sum + where; value++) {
              int sumLeft = value - where;
              int sumRight = sum - sumLeft;
              long long mul = waysLeft[where - 1][sumLeft];
              (mul *= waysRight[i - where][sumRight]) %= MOD;
              (mul *= C[i - 1][where - 1]) %= MOD; 
              (dp[i][where][sum] += mul) %= MOD;
            }  
          }
          (waysLeft[i][sum - where + i + 1] += dp[i][where][sum]) %= MOD; 
          (waysRight[i][sum + where] += dp[i][where][sum]) %= MOD; 
        }
      }
    }
    long long ans = 0LL;
    for (int s = 0; s <= S; s++) { 
      for (int where = 1; where <= N; where++) {
        (ans += dp[N][where][s]) %= MOD; 
      }
    }    
    return (int) ans; 
  }
};