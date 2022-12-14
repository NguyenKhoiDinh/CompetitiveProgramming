#include <iostream> 
#include <vector> 
#include <math.h> 
const int mod = 1000000007; 
int dp[105][105][105]; 
int n; 
int a[105]; 

void add(int &a, int b) {
  (a += b) %= mod; 
}

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  dp[0][0][0] = 1; 
  for (int i = 0; i < n; i++) {
    for (int last = 0; last <= n; last++) {
      for (int numb = 0; numb <= last; numb++) {
        if (dp[i][last][numb] == 0) {
          continue; 
        }
        if (numb == 0) {
          if (a[i + 1] > 0) {
            add(dp[i + 1][a[i + 1]][a[i + 1] - 1], dp[i][last][numb]);  
          }
          else {
            for (int x = 1; x <= n; x++) {
              add(dp[i + 1][x][x - 1], dp[i][last][numb]); 
            }
          }
        }
        else {
          if (a[i + 1] == last || a[i + 1] == 0) {
            add(dp[i + 1][last][numb - 1], dp[i][last][numb]); 
          }
        }
      }
    }
  }
  int ans = 0; 
  for (int last = 1; last <= n; last++) {
    add(ans, dp[n][last][0]);
  }
  if (ans == 1) {
    std::cout << "YES"; 
  }
  else {
    std::cout << "NO"; 
  }
  return 0; 
}