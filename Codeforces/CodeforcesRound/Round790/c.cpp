#include <iostream> 
#include <string> 
#include <algorithm> 
#include <math.h>
int numTest; 
int n, L; 
std::string a[55]; 
int cost(const std::string &s1, const std::string &s2) {
  int ret = 0; 
  for (int i = 0; i < L; i++) {
    ret += std::abs(s1[i] - s2[i]); 
  }    
  return ret; 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> L; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    int ans = 1000000007; 
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i != j) {
          ans = std::min(ans, cost(a[i], a[j])); 
        }
      }                                             
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}