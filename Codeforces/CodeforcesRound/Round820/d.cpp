#include <iostream>
#include <algorithm>
int numTest; 
int x[100005], y[100005];
int k[100005]; 
int n; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> y[i];
      k[i] = y[i] - x[i]; 
    }
    std::sort(k + 1, k + n + 1);
    int r = n; 
    int l = 1; 
    int ans = 0; 
    while (l < r) {
      while (l < r && k[l] + k[r] < 0) {
        l++; 
      } 
      if (l < r) {
        ans++;
        l++;
        r--;   
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}