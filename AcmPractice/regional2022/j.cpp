#include <iostream> 
#include <string>
#include <cstring> 
#include <vector>
const std::string core = "ICPC";  
std::string s; 

int main () {
  std::ios_base::sync_with_stdio(false);
  while (true) {
    std::cin >> s;
    int n = (int) s.size(); 
    if (s == "$") {
      break; 
    }
    std::vector <std::vector <unsigned long long> > dp; 
    dp.resize(n + 1); 
    for (int i = 0; i <= n; i++) {
      dp[i].resize(5, 0LL); 
    }
    dp[0][0] = 1;              
    if (s[0] == 'I') {
      dp[1][1] = 1; 
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= 4; j++) {
        if (dp[i][j] == 0) {
          continue; 
        }
        dp[i + 1][j] += dp[i][j]; 
        if (i + 2 <= n && j < 4 && s[i + 1] == core[j]) {
          dp[i + 2][j + 1] += dp[i][j]; 
        }
      }
    }
    std::cout << dp[n][4] << std::endl; 
  }
  return 0; 
}