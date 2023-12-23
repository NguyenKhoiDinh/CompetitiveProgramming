#include <iostream> 
int numTest; 
int p[102]; 
int n; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> p[i]; 
    }
    bool found = false; 
    for (int i = 1; i <= n; i++) {
      int a = i; 
      int b = p[a]; 
      if (a == b) {
        continue; 
      }
      int c = p[b]; 
      if (c == a || c == b) {
        continue; 
      }
      if (a == p[c]) {
        found = true;
        break; 
      }
    }
    if (found == true) {
      std::cout << "<3";
    }
    else {
      std::cout << "</3";
    }
    std::cout << std::endl; 
  }
  return 0;   
}