#include <iostream>
#include <math.h>  
const long long inf = -1e15; 
long long dp[(1 << 16) + 5]; 
long long cost[(1 << 16) + 5]; 
int a[16][16];
int n; 

int main () {
  std::cin >> n; 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> a[i][j]; 
    }
  }
  for (int mask = 1; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if ((mask & (1 << i)) > 0 && (mask & (1 << j)) > 0) {
          cost[mask] += a[i][j]; 
        }
      }
    }
  }
  dp[0] = 0; 
  for (int mask = 1; mask < (1 << n); mask++) {
    dp[mask] = cost[mask]; 
    for (int submask = (mask - 1) & mask; submask > 0; submask = (submask - 1) & mask) {
      dp[mask] = std::max(dp[mask], dp[mask - submask] + cost[submask]); 
    }
  }
  std::cout << dp[(1 << n) - 1]; 
  return 0; 
}