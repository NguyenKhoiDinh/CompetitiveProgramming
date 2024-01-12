#include <iostream> 
#include <math.h>
#include <algorithm> 
#include <vector> 
int n; 
int a[105]; 
int numTest; 
std::vector <int> save[105]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      save[i].clear();
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    int maxGcd = 0; 
    int numb = 0;
    int posi = -1, posj = -1;  
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        int gcd = std::__gcd(a[i], a[j]); 
        if (maxGcd < gcd) {
          maxGcd = gcd; 
          numb = 1; 
          posi = i;
          posj = j; 
        }
        else if (maxGcd == gcd) {
          numb++; 
        }
      }
    }
    if (numb > 1) {
      std::cout << maxGcd << std::endl; 
    }
    else {
      int ans = 0; 
      for (int i = 1; i <= n; i++) {
        if (i != posi && i != posj) {
          ans = std::max(ans, std::__gcd(a[posi], a[i]));
          ans = std::max(ans, std::__gcd(a[posj], a[i]));
        }
      }
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (i != j && (i != posi && j != posj) && (i != posj && j != posi)) {
            ans = std::max(ans, std::__gcd(a[i], a[j])); 
          }
        }
      }
      std::cout << ans << std::endl; 
    }
  }
  return 0;
}