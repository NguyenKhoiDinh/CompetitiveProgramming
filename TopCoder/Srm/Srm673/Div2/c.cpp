#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 105; 
long long dp[MAX_N]; 
long long C[MAX_N][MAX_N]; 
long long fact[MAX_N]; 

void init(const int &MOD) {
  fact[0] = 1LL; 
  for (int i = 0; i < MAX_N; i++) {
    C[i][0] = 1; 
    C[i][i] = 1; 
    if (i > 0) {
      fact[i] = (fact[i - 1] * i) % MOD; 
    }
  }
  for (int i = 1; i < MAX_N; i++) {
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD; 
    }
  }
}

int getTotal(int n, const int &MOD) {
  int ret = n * (n + 1) / 2; 
  return ret % MOD; 
}

class BearPermutations2 {
  public: 
  int getSum(int N, int MOD) {
    init(MOD);
    for (int i = 1; i <= N; i++) {
      for (int where = 1; where <= i; where++) {
        if (where == 1 || where == i) {
          (dp[i] += dp[i - 1]) %= MOD; 
        }
        else {
          (dp[i] += ((dp[where - 1] * fact[i - where]) % MOD) * C[i - 1][where - 1] % MOD) %= MOD; 
          (dp[i] += ((dp[i - where] * fact[where - 1]) % MOD) * C[i - 1][where - 1] % MOD) %= MOD; 
          long long total = (1LL * (where - 1) * (getTotal(i, MOD) - getTotal(where, MOD) + MOD) % MOD) % MOD; 
          (total += MOD) %= MOD;
          total -= (1LL * (i - where) * getTotal(where - 1, MOD)) % MOD; 
          (total += MOD) %= MOD;
          (total *= fact[where - 2]) %= MOD;
          (total *= fact[i - where - 1]) %= MOD;
          (total *= C[i - 1][where - 1]) %= MOD;
          (dp[i] += total) %= MOD; 
        }
      }
    }                      
    return (int) dp[N];  
  }
};

BearPermutations2 B;

int main () {
  cout << B.getSum(100, 89); 
  return 0;
}



/*1 2 3 4

1 2 4 3: 2
1 3 4 2: 2
2 4 3 1: 2
3 4 2 1: 2
2 1 4 3: 2
2 1 3 4: 3
3 1 2 4: 3
3 1 4 2: 2
4 1 2 3: 3
4 1 3 2: 2

8 + 30 = 38     */