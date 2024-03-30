#include <iostream>
#include <string>
#include <vector> 
int numTest; 
int n;
std::vector <std::string> a; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {                  
    std::cin >> n;
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i]; 
    }
    int maxx = -1, maxy = -1, minx = n + 2, miny = n + 2;
    int total = 0;  
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == '1') {
          total++; 
          maxx = std::max(maxx, i);
          maxy = std::max(maxy, j);
          minx = std::min(minx, i);
          miny = std::min(miny, j); 
        }
      }
    }
    std::cout << (total == (maxx - minx + 1) * (maxy - miny + 1) ? "SQUARE" : "TRIANGLE") << std::endl;
  }
  return 0; 
}