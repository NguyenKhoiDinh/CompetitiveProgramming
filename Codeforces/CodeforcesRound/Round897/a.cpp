#include <iostream>
#include <algorithm>
#include <utility>
int numTest; 
int n;
std::pair <int, int> a[40005]; 
int ans[40005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i].first; 
      a[i].second = i; 
    }
    std::sort(a + 1, a + n + 1); 
    for (int i = 1; i <= n; i++) {
      ans[a[i].second] = n - i + 1; 
    }
    for (int i = 1; i <= n; i++) {
      std::cout << ans[i] << ' ';
    }
    std::cout << std::endl;
  }
  return 0; 
}