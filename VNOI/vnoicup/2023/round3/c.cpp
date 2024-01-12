#include <iostream> 
#include <vector>
int numTest; 
int n;                

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    std::vector <int> p; 
    p.resize(n); 
    for (int i = 0; i < n; i++) {
      std::cin >> p[i]; 
    }
    bool found = false;
    for (int mask = 0; mask < (1 << n); mask++) {
      bool ok = true; 
      for (int i = 0; i < n; i++) {
        int numbLeft = 0;
        for (int j = 0; j < i; j++) {
          if ((mask & (1 << j)) > 0) {
            numbLeft++; 
          }
        }
        int numbRight = 0;
        for (int j = i + 1; j < n; j++) {
          if ((mask & (1 << j)) > 0) {
            numbRight++; 
          }
        }
        int isTrue = 0; 
        if (numbLeft >= numbRight) {
          isTrue = 1;  
        }
        int isLiar = ((mask & (1 << i)) == 0); 
        int answer; 
        if (isLiar == 1) {
          answer = !isTrue; 
        }
        else {
          answer = isTrue; 
        }
        if (answer != p[i]) {
          ok = false;
          break;
        }
      }
      if (ok == true) {
        found = true;
        for (int i = 0; i < n; i++) {
          if ((mask & (1 << i)) > 0) {
            std::cout << 1 << ' '; 
          }
          else {
            std::cout << 0 << ' '; 
          }
        }
        break; 
      } 
    }                                                           
    if (found == false) {
      std::cout << -1; 
    }
    std::cout << std::endl;
  }
  return 0; 
}