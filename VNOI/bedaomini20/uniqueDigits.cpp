#include <iostream>
#include <utility> 
#include <math.h> 
#include <vector> 
long long dp[1005][1 << 10]; 
int n, numTest;
std::vector <std::pair <long long, int> > a;  

int maskDigit(long long value) {
  int ret = 0;
  while (value > 0) {
    int r = value % 10;
    value /= 10; 
    if ((ret & (1 << r)) > 0) {
      return -1;
    }
    ret |= (1 << r); 
  }
  return ret; 
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    a.clear(); 
    for (int i = 1; i <= n; i++) {
      long long x;
      std::cin >> x; 
      if (maskDigit(x) == -1) {
        continue; 
      }
      a.push_back(std::make_pair(x, maskDigit(x)));
    }
    n = (int) a.size(); 
    for (int i = 0; i <= n; i++) {
      for (int mask = 0; mask < (1 << 10); mask++) {
        dp[i][mask] = -1; 
      }
    }
    dp[0][0] = 0LL;
    for (int i = 0; i < n; i++) {
      for (int mask = 0; mask < (1 << 10); mask++) {
        if (dp[i][mask] == -1) {
          continue; 
        }
        dp[i + 1][mask] = std::max(dp[i + 1][mask], dp[i][mask]); 
        int nextMask = a[i].second; 
        if ((mask & nextMask) > 0) {
          continue; 
        }
        dp[i + 1][mask | nextMask] = std::max(dp[i + 1][mask | nextMask], dp[i][mask] + a[i].first); 
      }
    }
    long long ans = -1LL;
    for (int mask = 0; mask < (1 << 10); mask++) {
      ans = std::max(ans, dp[n][mask]); 
    } 
    std::cout << ans << std::endl;
  }
  return 0; 
}