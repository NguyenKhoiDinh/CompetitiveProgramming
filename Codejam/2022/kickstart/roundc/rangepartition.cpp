#include <iostream>
#include <vector> 
int numTest; 
long long X, Y; 
long long N; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> N >> X >> Y;
    long long total = N * (N + 1) / 2; 
    if ((total * X) % (X + Y) != 0) {
      std::cout << "IMPOSSIBLE"; 
    }
    else {
      std::cout << "POSSIBLE" << std::endl; 
      long long half = (total * X) / (X + Y); 
      std::vector <int> ans; 
      for (int i = N; i >= 1; i--) {
        if (half >= i) {
          ans.push_back(i); 
          half -= i; 
        }
      }
      std::cout << (int) ans.size() << std::endl; 
      for (int i = 0; i < (int) ans.size(); i++) {
        std::cout << ans[i] << ' '; 
      }
      std::cout << std::endl; 
    }
  }          
  return 0; 
}