#include <iostream>
#include <math.h> 
#include <string> 
int numTest = 1; 
std::string s; 
int dp[2][105][5005]; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> s;
    int n = (int) s.size();
    int cntZeros = 0;
    int cntOnes = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        cntZeros++;
      }
      else {
        cntOnes++; 
      }
    } 
    int maxLimit = (n * (n - 1) / 2 - cntZeros * (cntZeros - 1) / 2 - cntOnes * (cntOnes - 1) / 2) / 2; 
    for (int i = 0; i <= 1; i++) {
      for (int numbZeros = 0; numbZeros <= n; numbZeros++) {
        for (int lim = 0; lim <= maxLimit; lim++) {
          dp[i][numbZeros][lim] = n + 5; 
        }
      }
    }
    dp[0][0][0] = 0; 
    for (int i = 0; i <= n; i++) {
      int now = i % 2;
      int nxt = !now; 
      for (int numbZeros = 0; numbZeros <= n; numbZeros++) {
        for (int lim = 0; lim <= maxLimit; lim++) {
          dp[nxt][numbZeros][lim] = n + 5; 
        }
      }
      for (int numbZeros = 0; numbZeros <= i; numbZeros++) {
        for (int lim = 0; lim <= maxLimit; lim++) {
          if (dp[now][numbZeros][lim] == n + 5) {
            continue; 
          }
          dp[nxt][numbZeros][lim] = std::min(dp[nxt][numbZeros][lim], dp[now][numbZeros][lim]); 
          if (numbZeros + 1 <= cntZeros && lim + (i - numbZeros) <= maxLimit) {
            dp[nxt][numbZeros + 1][lim + (i - numbZeros)] = std::min(dp[nxt][numbZeros + 1][lim + (i - numbZeros)], dp[now][numbZeros][lim] + (s[i] == '1'));
          }
        }
      }
    }
    std::cout << dp[n % 2][cntZeros][maxLimit];
  }
  return 0; 
}