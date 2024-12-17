#include <iostream> 
#include <string>
#include <vector>  
#include <math.h> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n; 
    std::cin >> n;
    std::string s; 
    std::cin >> s;
    int sqrtn = (int) std::sqrt(n);
    if (n != sqrtn * sqrtn) {
      std::cout << "NO" << std::endl;
      continue; 
    } 
    std::vector <std::vector <int> > a; 
    a.resize(sqrtn);
    for (int i = 0; i < sqrtn; i++) {
      a[i].resize(sqrtn); 
    }                           
    for (int i = 0; i < n; i++) {
      int x = i / sqrtn;
      int y = i % sqrtn;
      a[x][y] = s[i] - '0';   
    }
    bool found = true; 
    for (int i = 0; i < sqrtn; i++) {
      for (int j = 0; j < sqrtn; j++) {
        if (i == 0 || i == sqrtn - 1 || j == 0 || j == sqrtn - 1) {
          if (a[i][j] == 0) {
            found = false; 
          }
        }
        else {
          if (a[i][j] == 1) {
            found = false; 
          }
        }   
      }
    }
    std::cout << (found == true ? "YES" : "NO") << std::endl;
  }
  return 0; 
}