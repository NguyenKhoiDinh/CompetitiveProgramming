#include <iostream>
#include <vector>
#include <algorithm>
int numTest; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, p;
    std::cin >> n >> p; 
    std::vector <int> v; 
    for (int i = 1; i <= n; i++) {
      int x;
      std::cin >> x;
      if (x == 0) {
        v.push_back(p); 
      }
      else {
        v.push_back(x);
      }  
    }
    v.push_back(p + 1); 
    std::sort(v.begin(), v.end()); 
    int ans = 0; 
    for (int i = 1; i < (int) v.size(); i++) {
      if (v[i] > v[i - 1]) {
        ans += v[i] - 1 - v[i - 1]; 
      }
    }
    ans += v[0] - 1; 
    std::cout << ans << std::endl;
  }
  return 0; 
}