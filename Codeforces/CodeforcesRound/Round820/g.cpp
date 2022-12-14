#include <iostream>
#include <math.h> 
const int mod = 1000000007; 
const int inf = 1000005; 
int numTest; 
std::string s; 
int n; 
std::string t;
int m;  
int dp[505][2];
int ways[505][2]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> s >> t;
    n = (int) s.size();
    m = (int) t.size();
    for (int i = 0; i <= n; i++) {
      dp[i][0] = dp[i][1] = inf; 
      ways[i][0] = ways[i][1] = 0; 
    }
    dp[0][0] = 0;  
    for (int i = 1; i <= n; i++) {
      if (i < m) {
        dp[i][0] = dp[i - 1][0]; 
      }  
      else {
        bool check = true; 
        int j = i - 1; 
        int x = m - 1;
        while (x >= 0) {
          if (s[j] != t[x]) {
            check = false;
            break;    
          }
          j--;
          x--; 
        }
        if (check == true) {
          for (int j = 1; j < m; j++) {
            dp[i][0] = std::min(dp[i][0], dp[i - j][1]); 
          }  
          dp[i][1] = std::min(dp[i - m][0], dp[i - m][1]) + 1; 
        }
        else {
          dp[i][0] = std::min(dp[i - 1][0], dp[i - 1][1]); 
        }
      }
    }
    ways[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      if (i < m) {
        ways[i][0] = ways[i - 1][0]; 
      }
      else {
        bool check = true; 
        int j = i - 1; 
        int x = m - 1;
        while (x >= 0) {
          if (s[j] != t[x]) {
            check = false;
            break;    
          }
          j--;
          x--; 
        }
        if (check == true) {
          for (int j = 1; j < m; j++) {
            if (dp[i][0] == dp[i - j][1]) {
              (ways[i][0] += ways[i - j][1]) %= mod; 
            }
          }
          if (dp[i][1] == dp[i - m][0] + 1) {
            (ways[i][1] += ways[i - m][0]) %= mod; 
          }
          if (dp[i][1] == dp[i - m][1] + 1) {
            (ways[i][1] += ways[i - m][1]) %= mod; 
          }                      
        }
        else {
          if (dp[i][0] == dp[i - 1][0]) {
            (ways[i][0] += ways[i - 1][0]) %= mod; 
          }
          if (dp[i][0] == dp[i - 1][1]) {
            (ways[i][0] += ways[i - 1][1]) %= mod; 
          }
        }
      }  
    }
    if (dp[n][0] < dp[n][1]) {
      std::cout << dp[n][0] << ' ' << ways[n][0];
    } 
    else if (dp[n][0] > dp[n][1]) {
      std::cout << dp[n][1] << ' ' << ways[n][1];
    }
    else {
      std::cout << dp[n][0] << ' ' << (ways[n][0] + ways[n][1]) % mod; 
    }
    std::cout << std::endl; 
  }
  return 0; 
}