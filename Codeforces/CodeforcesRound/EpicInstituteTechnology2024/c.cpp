#include <iostream>
struct point {
  long long x, y; 
}; 
point a[100005]; 
long long dist(point A, point B) {
  return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y); 
}
point s, t; 
int numTest, n;

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i].x >> a[i].y; 
    }
    std::cin >> s.x >> s.y >> t.x >> t.y;
    bool ok = true; 
    for (int i = 1; i <= n; i++) {
      if (dist(a[i], t) <= dist(s, t)) {
        ok = false;
        break; 
      }
    } 
    std::cout << (ok == true ? "YES" : "NO") << std::endl;
  }
  return 0; 
}