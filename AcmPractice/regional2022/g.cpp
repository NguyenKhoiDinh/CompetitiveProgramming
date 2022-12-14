#include <iostream> 
int n, r, x1, x2; 

bool ok(const int &x) {
  if (x1 < x2) {
    return x + r <= x1; 
  }
  else {
    return x - r >= x1; 
  }
}

int main () {
  std::cin >> n >> r >> x1 >> x2; 
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x; 
    if (ok(x) == true) {
      std::cout << "GOAL";
      return 0; 
    }
  }
  std::cout << "NO GOAL"; 
  return 0; 
}