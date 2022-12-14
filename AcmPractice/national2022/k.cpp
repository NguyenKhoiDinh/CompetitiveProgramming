#include <iostream> 
#include <vector>
#include <algorithm>
#include <math.h> 
#include <utility>
struct pythagoreTriple {
  int a, b, c; 
  bool operator < (const pythagoreTriple &other) {
    return (double) b / (double) a > (double) other.b / (double) other.a; 
  }
};
int n; 
std::vector <pythagoreTriple> v; 

void generatePythagore() {
  const int LIM = 3000;
  for (int a = 1; a <= LIM; a++) {
    for (int b = 1; b <= LIM; b++) {
      if (std::__gcd(a, b) != 1) {
        continue;
      }
      int sum = a * a + b * b; 
      int c = (int) std::sqrt(sum); 
      if (c * c == sum) {
        v.push_back((pythagoreTriple) {a, b, c}); 
      }
    }
  }
  std::sort(v.begin(), v.end());
}

int main () {
  generatePythagore(); 
  std::cin >> n; 
  if (n == 1 || n == 2) {
    std::cout << "NO";
    return 0;
  }
  std::cout << "YES" << std::endl;
  int x = -1000000, y = -1000000;
  for (int i = 0; i < n - 1; i++) {
    std::cout << x << ' ' << y << std::endl; 
    if (i < n - 2) {
      x += v[i].a; 
      y += v[i].b; 
    }
  } 
  std::cout << x << ' ' << -1000000;
  return 0; 
}