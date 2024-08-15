#include <iostream>
#include <algorithm>
#include <utility> 
#include <assert.h>
int numTest;
int n, k, numQueries;
int a[100005], b[100005];

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k >> numQueries; 
    for (int i = 1; i <= k; i++) {
      std::cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
      std::cin >> b[i]; 
    }
    for (int query = 1; query <= numQueries; query++) {
      int d;
      std::cin >> d;
      int p = std::lower_bound(a + 1, a + k + 1, d) - a - 1;
      double value = 1.0 * (b[p + 1] - b[p]) / (a[p + 1] - a[p]);
      value *= d - a[p];  
      int ans = b[p] + value;
      std::cout << ans << ' ';  
    }                      
  }
  return 0; 
}