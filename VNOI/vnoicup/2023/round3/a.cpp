#include <iostream> 
int n, a, b;
int numTest; 
int x[105]; 

bool solve(const int &l1, const int &l2) {
  int p = 1;
  int end = x[1] + l1;
  while (p <= n && x[p] <= end) {
    p++; 
  }
  if (p > n) {
    return true; 
  }  
  end = x[p] + l2;
  while (p <= n && x[p] <= end) {
    p++; 
  }
  if (p > n) {
    return true;
  }
  return false; 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> a >> b; 
    for (int i = 1; i <= n; i++) {
      std::cin >> x[i]; 
    }
    if (solve(a, b) == true || solve(b, a) == true) {
      std::cout << "YES" << std::endl; 
    }
    else {
      std::cout << "NO" << std::endl; 
    }
  }
  return 0; 
}