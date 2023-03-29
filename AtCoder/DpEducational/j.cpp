#include <iostream>
#include <iomanip>
double dp[305][305][305], prob[305][305][305]; 
int n; 
int c1 = 0, c2 = 0, c3 = 0; 

int main () {
  std::cin >> n; 
  for (int i = 1; i <= n; i++) {
    int x; 
    std::cin >> x;
    if (x == 1) {
      c1++;
    }
    else if (x == 2) {
      c2++; 
    }
    else {
      c3++; 
    }
  }
  prob[c1][c2][c3] = 1.0; 
  for (int k = n; k >= 0; k--) {
    for (int j = n; j >= 0; j--) {
      for (int i = n; i >= 0; i--) {
        if (prob[i][j][k] == 0.0) {
          continue;
        }
        if (i + j + k == 0) {
          continue;
        }
        double empty = 1.0 * (n - i - j - k) / n;
        double total = dp[i][j][k] * 1.0 / (1.0 - empty) + prob[i][j][k] * 1.0 / ((1.0 - empty) * (1.0 - empty));  
        if (i > 0) {
          dp[i - 1][j][k] += 1.0 * i / n * total;
          prob[i - 1][j][k] += prob[i][j][k] * 1.0 / (1.0 - empty) * i / n;   
        }
        if (j > 0) {
          dp[i + 1][j - 1][k] += 1.0 * j / n * total;
          prob[i + 1][j - 1][k] += prob[i][j][k] * 1.0 / (1.0 - empty) * j / n;         
        }
        if (k > 0) {
          dp[i][j + 1][k - 1] += 1.0 * k / n * total; 
          prob[i][j + 1][k - 1] += prob[i][j][k] * 1.0 / (1.0 - empty) * k / n; 
        }
      }
    }
  }
  std::cout << std::fixed << std::setprecision(12) << dp[0][0][0]; 
  return 0;
}