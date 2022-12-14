#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 105; 
const long long MOD = 1000000007; 
long long dp[MAX_N][MAX_N]; 

class NoRepeatPlaylist {
  public: 
  int numPlaylists(int N, int M, int P) {
    dp[0][0] = 1;
    for (int i = 1; i <= P; i++) {
      for (int j = 1; j <= N; j++) {
        (dp[i][j] += (dp[i - 1][j - 1] * (N - (j - 1))) % MOD) %= MOD; 
        if (j >= M) {
          (dp[i][j] += (dp[i - 1][j] * (j - M)) % MOD) %= MOD; 
        }
      }
    }
    return (int) dp[P][N];    
  }
};

int main () {
  return 0; 
}