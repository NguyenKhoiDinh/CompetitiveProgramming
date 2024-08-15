#include <iostream>
#include <string>
#include <vector> 
int numTest; 
int n, m;
std::vector <std::string> a; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i]; 
    }
    int minL = m + 1, maxR = -1; 
    int x; 
    for (int i = 0; i < n; i++) {
      int l = -1, r = -1;
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '#') {
          if (l == -1) {
            l = j; 
          }
          r = j; 
        }
      }
      if (l != -1 && r != -1) {
        if (minL > l) {
          x = i; 
        }
        minL = std::min(minL, l); 
        maxR = std::max(maxR, r); 
      }  
    }
    std::cout << x + 1 << ' ' << (minL + maxR) / 2 + 1 << std::endl;
  }
  return 0; 
}