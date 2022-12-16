#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
struct point {
  int x, y; 
};
std::vector <point> base; 
int n; 

bool check(const std::vector <point> &base, const std::vector <point> &a) {
  std::vector <int> position = {0, 1, 2, 3};
  do {
    int diffx = base[0].x - a[position[0]].x; 
    int diffy = base[0].y - a[position[0]].y; 
    bool ok = true; 
    for (int i = 1; i < 4; i++) {
      if (diffx != base[i].x - a[position[i]].x || diffy != base[i].y - a[position[i]].y) {
        ok = false;
        break; 
      }
    }
    if (ok == true) {
      return true; 
    }
  }
  while (std::next_permutation(position.begin(), position.end())); 
  return false; 
}

int main () {
  int ans = 0; 
  base.resize(4);
  for (int i = 0; i < 4; i++) {
    std::cin >> base[i].x >> base[i].y; 
  }
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::vector <point> a;
    a.resize(4); 
    for (int j = 0; j < 4; j++) {
      std::cin >> a[j].x >> a[j].y; 
    }
    if (check(base, a) == true) {
      ans++;
    }
  }
  std::cout << ans; 
  return 0; 
}