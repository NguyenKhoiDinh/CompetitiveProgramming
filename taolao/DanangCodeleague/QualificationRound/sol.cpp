#include <iostream> 
#include <string> 
int numTest; 
std::string s; 
int dp[105]; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> s; 
    int n = (int) s.size(); 
    for (int i = 0; i <= n; i++) {
      dp[i] = 0; 
    }
    dp[0] = 1; 
    for (int i = 0; i < n; i++) {
      if (dp[i] == 0) {
        continue; 
      }
      if (s[i] == 'F') {
        dp[i + 1] = 1; 
      }
      if (i + 2 <= n && s[i] == 'F' && s[i + 1] == 'D') {
        dp[i + 2] = 1; 
      }
      if (i + 3 <= n && s[i] == 'F' && s[i + 1] == 'D' && s[i + 2] == 'D') {
        dp[i + 3] = 1; 
      }
    }
    std::cout << (dp[n] == 1 ? "Yes" : "No") << std::endl; 
  }
  return 0; 
}