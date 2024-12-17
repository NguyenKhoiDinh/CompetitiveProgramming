#include <iostream>
#include <math.h> 
int cost[5005][5005]; 
int l[5005], r[5005]; 
int n, numQueries; 

int main () {
  std::cin >> n >> numQueries; 
  for (int i = 1; i <= n; i++) {
    std::cin >> l[i] >> r[i]; 
  }
  for (int i = 1; i < n; i++) {
    cost[i][i] = (l[i + 1] - r[i] + 1) / 2; 
  }
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cost[i][j] = std::max(cost[j][j], cost[i][j - 1]); 
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cout << cost[i][j] << "    "; 
    }
    std::cout << std::endl;
  }
  for (int query = 1; query <= numQueries; query++) {
    int x, y;
    std::cin >> x >> y; 
    if (x == y) {
      std::cout << 0 << std::endl; 
    }
    else {
      std::cout << cost[x][y - 1] << std::endl;
    }
  }
  return 0; 
}