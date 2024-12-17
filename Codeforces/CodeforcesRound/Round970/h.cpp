#include <iostream> 
#include <math.h>
int numTest; 
int f[100005]; 
int n, numQueries;
int a[100005]; 
int sum[100005]; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> numQueries; 
    for (int i = 1; i <= n; i++) {
      sum[i] = 0; 
      f[i] = 0; 
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
      sum[a[i]]++; 
    }
    for (int i = 1; i <= n; i++) {
      sum[i] += sum[i - 1]; 
    }
    for (int x = 1; x <= n; x++) {
      int lo = 0, hi = x - 1; 
      while (lo <= hi) {
        int mid = (lo + hi) / 2; 
        int total = 0; 
        for (int l = 0; l <= n; l += x) {
          total += sum[std::min(l + mid, n)] - (l == 0 ? 0 : sum[l - 1]);         
        }
        if (total > n / 2) {
          f[x] = mid; 
          hi = mid - 1; 
        }
        else {
          lo = mid + 1; 
        }
      }
    }
    for (int query = 1; query <= numQueries; query++) {
      int x;
      std::cin >> x;
      std::cout << f[x] << ' '; 
    }
    std::cout << std::endl;
  }
  return 0; 
}