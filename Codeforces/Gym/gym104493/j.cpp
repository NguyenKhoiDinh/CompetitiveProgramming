#include <iostream> 
#include <math.h> 
#include <algorithm> 
int numTest; 
long long a[1000005]; 
int n; 

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);  
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    long long sum = 0LL; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
      sum += a[i]; 
    } 
    std::sort(a + 1, a + n + 1); 
    int mid = (n + 2) / 2; 
    int l = std::max(1, mid - 5);
    int r = std::min(mid + 5, n);
    long long ans = 10000000000000007LL;
    if (sum % n == 0) {
      long long X = sum / n; 
      int smaller = 0;
      int smallerOrEqual = 0; 
      for (int i = 1; i <= n; i++) {
        if (a[i] < X) {
          smaller++; 
        }  
        if (a[i] <= X) {
          smallerOrEqual++; 
        }
      }
      if (smallerOrEqual >= mid && smaller < mid) {
        ans = std::min(ans, X); 
      }
    }
    for (int i = l; i <= r; i++) {
      long long ak = a[i]; 
      long long X = ak * (n + 1) - sum; 
      int smaller = 0;
      int smallerOrEqual = 0;
      if (X < ak) {
        smaller++;
      } 
      if (X <= ak) {
        smallerOrEqual++; 
      }
      for (int i = 1; i <= n; i++) {
        if (a[i] < ak) {
          smaller++;
        }
        if (a[i] <= ak) {
          smallerOrEqual++; 
        }
      }
      if (smallerOrEqual >= mid && smaller < mid) {
        ans = std::min(ans, X); 
      }
    }   
    std::cout << ans << std::endl;
  }
  return 0; 
}