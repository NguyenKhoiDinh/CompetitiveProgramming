#include <iostream>
#include <math.h> 
#include <algorithm>
#include <map>
#include <utility> 
int maxDivisor[10000007];
int n, numTest;
int a[100005], b[100005];  
void erathones() {
  for (int i = 1; i * i <= 10000000; i++) {
    for (int j = i * i; j <= 10000000; j += i) {
      maxDivisor[j] = std::max(maxDivisor[j], i); 
      if (i != 1) {
        maxDivisor[j] = std::max(maxDivisor[j], j / i);
      } 
    }
  }
}

int main () {
  erathones();                            
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> b[i]; 
    }
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
      int da = a[i];
      int d = 0; 
      std::map <int, int> M; 
      while (da != 1) {
        M[da] = d; 
        da = maxDivisor[da]; 
        d++;  
      } 
      M[1] = d; 
      int db = b[i];
      d = 0;                                                           
      while (true) {
        if (M.find(db) != M.end()) {
          ans += d + M[db];
          break;  
        }
        db = maxDivisor[db];
        d++;   
      }
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}