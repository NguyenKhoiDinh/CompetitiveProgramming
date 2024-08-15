#include <iostream>
#include <vector> 
#include <math.h>
#include <algorithm> 
int numTest; 
long long n; 
int numbZero(long long x, long long base) {
  if (base < 2) {
    return -1; 
  }
  int ret = 0; 
  while (x > 0) {
    ret += (x % base == 0);
    x /= base;    
  }  
  return ret; 
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    int maxZero = 0; 
    std::vector <long long> ans; 
    for (long long base = 1; base <= std::min(n, 20000LL); base++) {
      int cnt = numbZero(n, base);
      if (maxZero < cnt) {
        maxZero = cnt;
        ans.clear();
        ans.push_back(base); 
      }
      else if (maxZero == cnt) {
        ans.push_back(base); 
      }
      cnt = numbZero(n, n / base);
      if (maxZero < cnt) {
        maxZero = cnt;
        ans.clear();
        ans.push_back(n / base);
      }
      else if (maxZero == cnt) {
        ans.push_back(n / base);
      }  
    }
    std::sort(ans.begin(), ans.end());
    ans.resize(std::unique(ans.begin(), ans.end()) - ans.begin());
    std::cout << maxZero << ' ' << (int) ans.size() << std::endl;
    for (int i = 0; i < (int) ans.size(); i++) {
      std::cout << ans[i] << ' '; 
    } 
    std::cout << std::endl;
  }
  return 0; 
}