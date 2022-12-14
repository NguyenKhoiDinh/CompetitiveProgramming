#include <iostream>
#include <algorithm> 
#include <math.h>
int numTest; 
int a[200005];
long long dp[200005][3][2];  
int n, h; 

void update(long long &a, long long b) {
  a = std::max(a, b); 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> h; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    std::sort(a + 1, a + n + 1);
    int ans = 0; 
    for (int i = 0; i <= n; i++) {
      for (int greenSerum = 0; greenSerum <= 2; greenSerum++) {
        for (int blueSerum = 0; blueSerum <= 1; blueSerum++) {
          dp[i][greenSerum][blueSerum] = -1; 
        }
      }
    }
    dp[0][2][1] = h; 
    for (int i = 0; i < n; i++) {
      for (int greenSerum = 2; greenSerum >= 0; greenSerum--) {
        for (int blueSerum = 1; blueSerum >= 0; blueSerum--) {
          if (dp[i][greenSerum][blueSerum] == -1) {
            continue; 
          }
          if (greenSerum > 0) {
            update(dp[i][greenSerum - 1][blueSerum], dp[i][greenSerum][blueSerum] * 2LL);
          }  
          if (blueSerum > 0) {
            update(dp[i][greenSerum][blueSerum - 1], dp[i][greenSerum][blueSerum] * 3LL);
          }  
          if (dp[i][greenSerum][blueSerum] > a[i + 1]) {
            ans = i + 1;
            update(dp[i + 1][greenSerum][blueSerum], dp[i][greenSerum][blueSerum] + a[i + 1] / 2);
          }
        }
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}