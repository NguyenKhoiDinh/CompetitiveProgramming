#include <iostream>
#include <algorithm>
#include <math.h>        
long long n, l[500005], r[500005], cnt, f[500005][2];
struct element {
  long long x, y, s;
};
element a[500005];
bool compare(element a, element b) {
  if (a.s != b.s) {
    return a.s < b.s; 
  }
  if (a.x != b.x) {
    return a.x < b.x; 
  }
  return a.y > b.y;
}
long long dist(int i, int j) {
  return std::abs(a[i].x - a[j].x) + std::abs(a[i].y - a[j].y); 
}
int main() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].x >> a[i].y; 
    a[i].s = std::max(a[i].x, a[i].y); 
  } 
  std::sort(a + 1, a + n + 1, compare);
  for (int i = 1; i <= n; i++) {
    if (a[i].s != a[i - 1].s) {
      r[++cnt] = i; 
    }
    if (a[i].s != a[i + 1].s) {
      l[cnt] = i; 
    }
  }
  for (int i = 1; i <= cnt; i++) {
    f[i][0] = std::min(f[i - 1][0] + dist(l[i - 1], r[i]), f[i - 1][1] + dist(r[i - 1], r[i])) + dist(l[i], r[i]); 
    f[i][1] = std::min(f[i - 1][0] + dist(l[i - 1], l[i]), f[i - 1][1] + dist(r[i - 1], l[i])) + dist(l[i], r[i]); 
  }
  std::cout << std::min(f[cnt][0], f[cnt][1]); 
  return 0;                                         
}