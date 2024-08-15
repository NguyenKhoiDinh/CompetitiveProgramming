#include <iostream>
#include <map>
#include <utility>
#include <math.h> 
int dx1[13] = {0, 0, 0, 0, 0, 1, 1, 1, -1, -1, -1, 2, -2}; 
int dy1[13] = {0, -1, 1, -2, 2, -1, 0, 1, -1, 0, 1, 0, 0};
int dx[12] = {0, 0, 0, 0, 0, 1, 1, 1, -1, -1, -1, -2};
int dy[12] = {0, -1, 1, -2, 2, -1, 0, 1, -1, 0, 1, 0};
int n; 
std::map <std::pair <int, int>, long long> f; 
struct diamond {
  int x, y, value; 
};
diamond a[100005]; 
                                                  
int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].x >> a[i].y >> a[i].value; 
    for (int j = 0; j < 12; j++) {
      int nx = a[i].x + dx[j];
      int ny = a[i].y + dy[j]; 
      f[std::make_pair(nx, ny)] += a[i].value;
    }
  }
  long long ans = 0; 
  for (std::map <std::pair <int, int>, long long>::iterator it = f.begin(); it != f.end(); it++) {
    ans = std::max(ans, it->second); 
  }
  std::cout << ans;
  return 0; 
}