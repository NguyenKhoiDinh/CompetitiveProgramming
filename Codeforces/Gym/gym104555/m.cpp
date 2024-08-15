#include <iostream> 
#include <set> 
#include <utility> 
#include <algorithm>
int f[105][105]; 
int n; 
std::set <std::pair <int, int> > S; 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> f[i][j]; 
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (f[i][j] > f[i][k] + f[k][j]) {
          std::cout << -1;
          return 0; 
        }
        if (f[i][j] == f[i][k] + f[k][j] && k != i && k != j) {
          int u = i;
          int v = j;
          if (u > v) {
            std::swap(u, v); 
          }  
          S.insert(std::make_pair(u, v)); 
        }
      }
    }
  }
  std::cout << (int) S.size();
  return 0; 
}