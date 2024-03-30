#include <iostream>
#include <string>
#include <math.h>
int numTest; 
int n, k; 
std::string s; 
int prefix[3005][3005], suffix[3005][3005]; 
int maxl0[3005];

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    std::cin >> s;
    for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j <= k; j++) {
        prefix[i][j] = 0; 
        suffix[i][j] = 0;
      }
    }
    for (int i = 0; i <= n + 1; i++) {
      maxl0[i] = -3005; 
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        if (s[i - 1] == '1') {
          if (j > 0) {
            prefix[i][j] = prefix[i - 1][j - 1] + 1; 
          }                                         
        }
        else {                                               
          prefix[i][j] = prefix[i - 1][j] + 1; 
        }
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        if (i > 0) {
          prefix[i][j] = std::max(prefix[i][j], prefix[i - 1][j]);
        }
        if (j > 0) {
          prefix[i][j] = std::max(prefix[i][j], prefix[i][j - 1]); 
        }
      }  
    }
    for (int i = n; i >= 1; i--) {
      for (int j = 0; j <= k; j++) {
        if (s[i - 1] == '1') {
          if (j > 0) {
            suffix[i][j] = suffix[i + 1][j - 1] + 1; 
          }
        }
        else {
          suffix[i][j] = suffix[i + 1][j] + 1; 
        }
      }
    }
    for (int i = n + 1; i >= 1; i--) {
      for (int j = 0; j <= k; j++) {
        if (i + 1 <= n) {
          suffix[i][j] = std::max(suffix[i][j], suffix[i + 1][j]); 
        }
        if (j > 0) {
          suffix[i][j] = std::max(suffix[i][j], suffix[i][j - 1]); 
        }
      }
    }
    maxl0[0] = prefix[n][k]; 
    for (int l = 1; l <= n; l++) {
      int cnt0 = 0;
      for (int r = l; r <= n; r++) {
        if (s[r - 1] == '0') {
          cnt0++; 
        }                            
        if (cnt0 <= k) {
          maxl0[r - l + 1] = std::max(maxl0[r - l + 1], prefix[l - 1][k - cnt0]);
          maxl0[r - l + 1] = std::max(maxl0[r - l + 1], suffix[r + 1][k - cnt0]);  
        }
      }
    }
    for (int a = 1; a <= n; a++) {
      int ans = 0;
      for (int l1 = 0; l1 <= n; l1++) {
        ans = std::max(ans, a * maxl0[l1] + l1); 
      }
      std::cout << ans << ' '; 
    }
    std::cout << std::endl;
  }
  return 0; 
}