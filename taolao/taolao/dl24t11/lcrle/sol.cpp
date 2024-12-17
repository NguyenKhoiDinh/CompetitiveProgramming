#include <iostream>
#include <math.h> 
#include <vector>
#include <string>         
std::string A, B; 
int n, m; 
long long f[505][505];
std::string X, Y;
std::vector <long long> numbX, numbY;
long long g[505][505][2];   

int main () {
  std::cin >> A >> B; 
  n = (int) A.size();
  m = (int) B.size();
  X += '.';
  Y += '.';
  numbX.push_back(0);
  numbY.push_back(0);
  long long value = 0LL; 
  for (int i = 0; i < n; i++) {
    if ('a' <= A[i] && A[i] <= 'z') {
      X += A[i];
      if (value > 0) {
        numbX.push_back(value);
      }
      value = 0LL;  
    }
    else {
      value = value * 10LL + A[i] - '0';
    }
  }  
  numbX.push_back(value);
  value = 0LL;
  for (int i = 0; i < m; i++) {
    if ('a' <= B[i] && B[i] <= 'z') {
      Y += B[i];
      if (value > 0) {
        numbY.push_back(value); 
      }
      value = 0LL; 
    }
    else {
      value = value * 10LL + B[i] - '0'; 
    }
  } 
  numbY.push_back(value);
  n = (int) X.size() - 1; 
  m = (int) Y.size() - 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] = std::max(f[i - 1][j], f[i][j - 1]);
      if (X[i] == Y[j]) {
        if (numbX[i] == numbY[j]) {
          f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + numbX[i]); 
        }
        else if (numbX[i] > numbY[j]) {
          value = numbX[i]; 
          long long total = 0LL; 
          for (int k = j; k >= 1; k--) {
            if (X[i] == Y[k] && value >= numbY[k]) {
              f[i][j] = std::max(f[i][j], f[i - 1][k - 1] + total + numbY[k]);
              value -= numbY[k];
              total += numbY[k];  
            }
          }
        }                                      
        else {
          value = numbY[j]; 
          long long total = 0LL; 
          for (int k = i; k >= 1; k--) {
            if (X[k] == Y[j] && value >= numbX[k]) {
              f[i][j] = std::max(f[i][j], f[k - 1][j - 1] + total + numbX[k]);
              value -= numbX[k];                               
              total += numbX[k];  
            }
          }
        }
      } 
    }
  }
  std::cout << f[n][m] << std::endl; 
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int state = 0; state <= 1; state++) {
        if (X[i] == Y[j]) {
          if (numbX[i] == numbY[j]) {
            g[i][j][state] = g[i - 1][j - 1][state] + numbX[i];                                                      
          }
          else if (state == 0) {
            g[i][j][state] = g[i - 1][j - 1][1] + std::min(numbX[i], numbY[j]); 
          }
          else {
            g[i][j][state] = std::min(numbX[i], numbY[j]); 
          }
        }                                           
      }  
    }
  }
  long long ans = 0LL; 
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int state = 0; state <= 1; state++) {
        ans = std::max(ans, g[i][j][state]); 
      }
    }
  }                             
  std::cout << ans;                
  return 0; 
}