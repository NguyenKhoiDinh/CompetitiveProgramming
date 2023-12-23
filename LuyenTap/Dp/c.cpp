#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
int h[15]; 
int n; 
int f[1 << 15][15];
long long ways[1 << 15][15]; 
std::vector <int> listIndex[1 << 15]; 

int main () {
  for (int mask = 0; mask < (1 << 15); mask++) {
    for (int i = 0; i < 15; i++) {
      if ((mask & (1 << i)) > 0) {
        listIndex[mask].push_back(i); 
      }
    }
  }
  while (true) {
    std::cin >> n;
    if (n == 0) {
      break;
    }
    for (int i = 0; i < n; i++) {
      std::cin >> h[i];
    }
    int maxPerimeter = -1; 
    long long numbWays = 0LL;
    for (int start = 0; start < n; start++) {
      for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
          f[mask][i] = -1;
          ways[mask][i] = 0LL; 
        }
      }
      f[1 << start][start] = h[start] + 1; 
      ways[1 << start][start] = 1LL; 
      for (int mask = 0; mask < (1 << n); mask++) {
        std::vector <int> &vChosen = listIndex[mask];
        std::vector <int> &vNotChosen = listIndex[(1 << n) - 1 - mask];  
        for (int i = 0; i < (int) vChosen.size(); i++) {
          int u = vChosen[i]; 
          if (f[mask][u] == -1) {
            continue; 
          }
          for (int j = 0; j < (int) vNotChosen.size(); j++) {
            int v = vNotChosen[j]; 
            int diff = std::abs(h[v] - h[u]); 
            if (f[mask | (1 << v)][v] < f[mask][u] + 1 + diff) {
              f[mask | (1 << v)][v] = f[mask][u] + 1 + diff;
              ways[mask | (1 << v)][v] = ways[mask][u];
            }
            else if (f[mask | (1 << v)][v] == f[mask][u] + 1 + diff) {
              ways[mask | (1 << v)][v] += ways[mask][u];
            }
          }
        }
      }
      for (int u = 0; u < n; u++) {
        if (u != start) {
          if (maxPerimeter < f[(1 << n) - 1][u] + h[u]) {
            maxPerimeter = f[(1 << n) - 1][u] + h[u];
            numbWays = ways[(1 << n) - 1][u]; 
          }
          else if (maxPerimeter == f[(1 << n) - 1][u] + h[u]) {
            numbWays += ways[(1 << n) - 1][u];
          }
        }
      }
    } 
    std::cout << maxPerimeter + n << ' ' << numbWays << std::endl;
  }
  return 0; 
}