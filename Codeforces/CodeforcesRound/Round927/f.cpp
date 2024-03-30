#include <iostream>
#include <math.h> 
#include <vector> 
#include <algorithm>
const int inf = 1000005; 
int numTest; 
int n, m; 
int minLeft[1000005]; 
int numbCats[1000005]; 
int f[1000005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {                  
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      minLeft[i] = inf; 
      numbCats[i] = 0; 
      f[i] = -1; 
    }   
    for (int i = 1; i <= m; i++) {
      int l, r;
      std::cin >> l >> r; 
      numbCats[l]++;
      numbCats[r + 1]--; 
      minLeft[r] = std::min(minLeft[r], l); 
    }
    for (int i = 2; i <= n; i++) {
      numbCats[i] += numbCats[i - 1]; 
    }
    for (int i = n - 1; i >= 1; i--) {
      minLeft[i] = std::min(minLeft[i + 1], minLeft[i]); 
    }
    for (int i = 1; i <= n; i++) {
      f[i] = f[i - 1];
      if (minLeft[i] != inf) {
        f[i] = std::max(f[i], f[minLeft[i] - 1] + numbCats[i]); 
      }
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
      ans = std::max(ans, f[i]); 
    } 
    std::cout << ans << std::endl;
  }
  return 0; 
}