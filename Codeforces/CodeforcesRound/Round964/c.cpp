#include <iostream> 
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, s, m;
    std::cin >> n >> s >> m;
    int last = 0;
    bool ok = false; 
    for (int i = 1; i <= n; i++) {
      int l, r;
      std::cin >> l >> r; 
      if (l - last >= s) {
        ok = true; 
      }
      last = r; 
    }  
    if (ok == true || m - last >= s) {
      std::cout << "YES"; 
    }
    else {
      std::cout << "NO"; 
    }
    std::cout << std::endl;
  }
  return 0; 
}