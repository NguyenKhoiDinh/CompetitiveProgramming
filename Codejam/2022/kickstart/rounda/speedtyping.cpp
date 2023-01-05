#include <iostream> 
#include <string>    
int numTest; 
std::string P, I; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> P >> I; 
    int p = 0; 
    int q = 0; 
    while (true) {
      while (q < (int) I.size()) {
        if (I[q] == P[p]) {
          q++;
          p++;
          break; 
        }
        else {
          q++; 
        }
      }
      if (p == (int) P.size() || q == (int) I.size()) {
        break; 
      }
    }
    if (p == (int) P.size()) {
      std::cout << (int) I.size() - (int) P.size() << std::endl; 
    }
    else {
      std::cout << "IMPOSSIBLE" << std::endl; 
    }
  }
  return 0; 
}