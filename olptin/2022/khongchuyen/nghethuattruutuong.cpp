#include <iostream>
#include <set>
#include <utility>
int h[1005][1005]; 
int n, m; 
bool canSee[1005][1005];  

int main () {
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> h[i][j]; 
    }
  }
  for (int i = 0; i < n; i++) {
    if (h[i][0] > 0) {
      canSee[i][0] = true;
    }
    int curHeight = h[i][0]; 
    for (int j = 1; j < m; j++) {
      if (h[i][j] > curHeight) {
        canSee[i][j] = true;
        curHeight = h[i][j]; 
      }
    }
    if (h[i][m - 1] > 0) {
      canSee[i][m - 1] = true;
    }
    curHeight = h[i][m - 1];
    for (int j = m - 2; j >= 0; j--) {
      if (h[i][j] > curHeight) {
        canSee[i][j] = true;
        curHeight = h[i][j]; 
      }
    }  
  }
  for (int j = 0; j < m; j++) {
    if (h[0][j] > 0) {
      canSee[0][j] = true;
    }
    int curHeight = h[0][j];
    for (int i = 1; i < n; i++) {
      if (h[i][j] > curHeight) {
        canSee[i][j] = true;
        curHeight = h[i][j]; 
      }
    }
    if (h[n - 1][j] > 0) {
      canSee[n - 1][j] = true;
    }
    curHeight = h[n - 1][j];
    for (int i = n - 2; i >= 0; i--) {
      if (h[i][j] > curHeight) {
        canSee[i][j] = true;
        curHeight = h[i][j]; 
      }
    }
  }
  int ans = 0; 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (canSee[i][j] == true) {
        ans++; 
      }
    }
  }
  std::cout << ans; 
  return 0;
}