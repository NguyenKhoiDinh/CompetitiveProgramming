#include <iostream> 
#include <stdlib.h>
#include <time.h>
#include <math.h> 
#include <random>
int n, m; 

int main () {
  std::random_device rd;
  std::default_random_engine eng {rd()};
  std::uniform_int_distribution <> dist(0, 180000);
  std::cin >> m >> n; 
  for (int i = 1; i < m; i++) {
    std::cout << i << ' ' << i + 1 << std::endl; 
  }
  int ans = -1; 
  for (int step = 1; step <= 200; step++) {
    int u = dist(eng) % n + 1; 
    int v;
    while (true) {
      v = dist(eng) % n + 1;
      if (u != v) {
        break; 
      }
    }
    std::cout << "subtree " << u << ' ' << v << std::endl;
    int d1;
    std::cin >> d1; 
    std::cout << "subtree " << v << ' ' << u << std::endl;
    int d2;
    std::cin >> d2; 
    std::cout << "distance " << u << ' ' << v << std::endl;
    int d3;
    std::cin >> d3;
    ans = std::max(ans, d1 + d2 - d3); 
  }
  std::cout << "! " << ans << std::endl;
  return 0; 
}