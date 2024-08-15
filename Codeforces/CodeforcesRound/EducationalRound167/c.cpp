#include <iostream>
#include <math.h> 
int numTest; 
int a[200005], b[200005]; 
int n; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    int sum1 = 0;
    int sum2 = 0; 
    int total = 0; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];  
    }  
    for (int i = 1; i <= n; i++) {
      std::cin >> b[i]; 
    }
    int x = 0, y = 0; 
    for (int i = 1; i <= n; i++) {
      total += b[i]; 
      if (a[i] == 0) {
        if (b[i] == -1) {
          sum2 += b[i];   
        }
        else {
          continue;   
        }
      }
      if (b[i] == 0) {
        if (a[i] == -1) {
          continue; 
        }
        else {
          sum1 += a[i]; 
        }
      }
      if (a[i] == 1 && b[i] == -1) {
        sum1 += a[i];
        sum2 += b[i]; 
      }
      else if (a[i] == -1 && b[i] == 1) {
        continue; 
      }
      else if (a[i] == 1 && b[i] == 1) {
        x++; 
      }
      else if (a[i] == -1 && b[i] == -1) {
        y++; 
      }
    }
    int ans = -1000000007; 
    for (int diff = -y; diff <= x; diff++) {
      ans = std::max(ans, std::min(sum1 + diff, total - sum2 - diff));   
    }
    std::cout << ans << std::endl;
  }
  return 0; 
}