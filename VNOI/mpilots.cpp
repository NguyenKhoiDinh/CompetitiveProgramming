#include <iostream>
#include <fstream> 
#include <math.h> 

using namespace std; 
const int MAX_N = 5005; 
const int inf = 1000000007; 
int dp[MAX_N][MAX_N];
int X[MAX_N], Y[MAX_N];
int n; 

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> X[i] >> Y[i]; 
  }
  int half = n / 2; 
  for (int i = 0; i <= half; i++) {
    for (int j = 0; j <= half; j++) {
      dp[i][j] = inf; 
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i <= half; i++) {
    for (int j = 0; j <= i; j++) {
      if (dp[i][j] == inf) {
        continue; 
      }
      if (i < half) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + Y[i + 1 + j]); 
      }
      if (j < i) {
        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + X[i + 1 + j]);
      }
    }
  }
  cout << dp[half][half];
  return 0; 
}