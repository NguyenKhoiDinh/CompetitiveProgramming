#include <iostream> 
int numTest;

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int ans = 0; 
    if (b > a) {
      ans++; 
    }            
    if (c > a) {
      ans++; 
    }  
    if (d > a) {
      ans++; 
    } 
    std::cout << ans << std::endl;
  }
  return 0;
}