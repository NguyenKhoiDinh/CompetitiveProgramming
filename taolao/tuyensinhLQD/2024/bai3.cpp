#include <iostream>
#include <math.h>
#include <algorithm>
long long a[1000005]; 

int main () {                            
  freopen("bai3.inp", "r", stdin);
  freopen("bai3.out", "w", stdout);
  std::ios_base::sync_with_stdio(false); 
  int n, k;
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  long long sum = 0LL; 
  int numbEven = 0;
  int l = 1, r = k;
  int ansL = 1, ansR = k;
  long long maxSum = 0LL;
  int maxEven = 0;  
  for (int i = 1; i <= k; i++) {
    sum += a[i]; 
    if (std::abs(a[i]) % 2 == 0) {
      numbEven++; 
    }
  }
  maxSum = sum;
  maxEven = numbEven; 
  while (r < n) {
    r++; 
    sum += a[r]; 
    if (std::abs(a[r]) % 2 == 0) {
      numbEven++; 
    }
    sum -= a[l]; 
    if (std::abs(a[l]) % 2 == 0) {
      numbEven--; 
    }
    l++; 
    if (maxSum < sum) {
      maxSum = sum;
      maxEven = numbEven;
      ansL = l;
      ansR = r;    
    }
    else if (maxSum == sum && maxEven < numbEven) {
      maxEven = numbEven;
      ansL = l;
      ansR = r; 
    }
  }
  std::cout << ansL << ' ' << ansR;
  return 0; 
}