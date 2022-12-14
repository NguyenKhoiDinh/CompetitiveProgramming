#include <iostream> 
#include <fstream>
int numTest; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i += 5) {
      ans++; 
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}