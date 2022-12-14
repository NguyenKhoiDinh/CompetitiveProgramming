#include <iostream>  
#include <math.h> 
const int inf = 1000000007; 
int numTest; 
int n, m; 
int key[2505];
int numb[2505]; 
int Left[2505][2505], Right[2505][2505];  
int dp[2505][2505]; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": ";
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> numb[i]; 
    } 
    std::cin >> m; 
    for (int i = 1; i <= m; i++) {
      std::cin >> key[i]; 
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = inf; 
      }
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= 2500; j++) {
        Left[i][j] = -1; 
        Right[i][j] = -1; 
      }
    }
    for (int i = 1; i <= m; i++) {
      for (int j = i; j >= 1; j--) {
        if (Left[i][key[j]] == -1) {
          Left[i][key[j]] = j; 
        }
      }
      for (int j = i; j <= m; j++) {
        if (Right[i][key[j]] == -1) {
          Right[i][key[j]] = j; 
        }
      }
    }
    for (int j = 1; j <= m; j++) {
      if (key[j] == numb[1]) {
        dp[1][j] = 0; 
      }
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= m; j++) {
        if (dp[i][j] == inf) {
          continue; 
        }
        if (Left[j][numb[i + 1]] != -1) {
          int nextpos = Left[j][numb[i + 1]]; 
          dp[i + 1][nextpos] = std::min(dp[i + 1][nextpos], dp[i][j] + std::abs(j - nextpos)); 
        }
        if (Right[j][numb[i + 1]] != -1) {
          int nextpos = Right[j][numb[i + 1]]; 
          dp[i + 1][nextpos] = std::min(dp[i + 1][nextpos], dp[i][j] + std::abs(j - nextpos)); 
        }
      }
    }
    int ans = inf; 
    for (int j = 1; j <= m; j++) {
      ans = std::min(ans, dp[n][j]); 
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}