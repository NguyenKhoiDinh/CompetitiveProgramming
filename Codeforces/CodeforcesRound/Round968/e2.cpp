#include <iostream>
#include <math.h> 
int f[5005][5005][2]; 
bool state[5005][4]; 
int n, m, numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m; 
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        f[i][j][0] = -1; 
        f[i][j][1] = -1; 
      }
    }
    for (int i = 1; i <= n; i++) {
      state[i][0] = false;
      state[i][1] = false;
      state[i][2] = false;
      state[i][3] = false; 
    } 
    for (int i = 1; i <= m; i++) {
      int l, r;
      std::cin >> l >> r;
      state[l][1] = true; 
      state[r][2] = true; 
      for (int j = l + 1; j < r; j++) {
        state[j][3] = true; 
      }   
    }
    bool fail = false; 
    for (int i = 1; i <= n; i++) {
      if (state[i][1] == true && state[i][2] == true) {
        fail = true; 
        break; 
      }
    }
    if (fail == true) {
      std::cout << -1 << std::endl; 
      continue; 
    }
    f[0][0][0] = 0; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        for (int bit = 0; bit <= 1; bit++) {
          if (f[i][j][bit] == -1) {
            continue; 
          }
          if (state[i + 1][1] == false && state[i + 1][2] == false && state[i + 1][3] == false) {
            f[i + 1][j + 1][1] = std::max(f[i + 1][j + 1][1], f[i][j][bit]); 
            f[i + 1][j][0] = std::max(f[i + 1][j][0], f[i][j][bit] + j); 
          }
          if (state[i + 1][2] == true) {
            f[i + 1][j + 1][1] = std::max(f[i + 1][j + 1][1], f[i][j][bit]);   
          }
          if (state[i + 1][1] == true) {
            if (state[i + 1][3] == false) {
              f[i + 1][j][0] = std::max(f[i + 1][j][0], f[i][j][bit] + j); 
            }
            else if (bit == 0) {
              f[i + 1][j][0] = std::max(f[i + 1][j][0], f[i][j][bit] + j);   
            }
          }
          if (state[i + 1][1] == false && state[i + 1][2] == false && state[i + 1][3] == true) {
            f[i + 1][j + 1][1] = std::max(f[i + 1][j + 1][1], f[i][j][bit]); 
            if (bit == 0) {
              f[i + 1][j][0] = std::max(f[i + 1][j][0], f[i][j][bit] + j); 
            }
          }
        }
      }
    }
    int ans = -1; 
    for (int j = 0; j <= n; j++) {
      if (f[n][j][0] != -1) {
        ans = std::max(ans, f[n][j][0] + j * (j - 1) / 2 + (n - j) * (n - j - 1) / 2); 
      }
      if (f[n][j][1] != -1) {
        ans = std::max(ans, f[n][j][1] + j * (j - 1) / 2 + (n - j) * (n - j - 1) / 2); 
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}               