#include <iostream>
#include <string>
#include <math.h>
int f[100005][4][4][4];
int n;
std::string s; 
int shipment[100005]; 

int calc(int a, int b, int c) {
  int ret = 0;
  if (a == 1 || b == 1 || c == 1) {
    ret++;
  }
  if (a == 2 || b == 2 || c == 2) {
    ret++;
  }
  if (a == 3 || b == 3 || c == 3) {
    ret++;
  }
  return ret; 
}

int main () {
  std::cin >> n;
  std::cin >> s; 
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == 'M') {
      shipment[i] = 1; 
    }
    else if (s[i - 1] == 'B') {
      shipment[i] = 2; 
    }
    else {
      shipment[i] = 3; 
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int a = 0; a <= 3; a++) {
      for (int b = 0; b <= 3; b++) {
        for (int c = 0; c <= 3; c++) {
          f[i][a][b][c] = -1; 
        }
      }
    }
  }
  f[0][0][0][0] = 0; 
  for (int i = 0; i < n; i++) {
    for (int a = 0; a <= 3; a++) {
      for (int b = 0; b <= 3; b++) {
        for (int c = 0; c <= 3; c++) {
          if (f[i][a][b][c] == -1) {
            continue; 
          }
          f[i + 1][shipment[i]][b][c] = std::max(f[i + 1][shipment[i]][b][c], f[i][a][b][c] + calc(shipment[i], shipment[i + 1], a));
          f[i + 1][c][a][shipment[i]] = std::max(f[i + 1][c][a][shipment[i]], f[i][a][b][c] + calc(shipment[i + 1], b, c));
        }
      }
    }
  }
  int ans = -1; 
  for (int a = 0; a <= 3; a++) {
    for (int b = 0; b <= 3; b++) {
      for (int c = 0; c <= 3; c++) {
        ans = std::max(ans, f[n][a][b][c]);
      }
    }
  }
  std::cout << ans;
  return 0; 
}