#include <iostream>
#include <math.h> 
int n; 
int a[1000005]; 
long long lim; 
int type; 
int left[1000005], right[1000005];
int f[1000005];       
void process() {
  int p = 1; 
  long long sum = 0LL; 
  for (int i = 1; i <= n; i++) {
    sum += a[i]; 
    while (sum > lim) {
      sum -= a[p];
      p++;   
    }
    if (p <= i) {
      left[i] = p; 
    }
  }
  p = n;
  sum = 0LL;
  for (int i = n; i >= 1; i--) {
    sum += a[i]; 
    while (sum > lim) {
      sum -= a[p];
      p--; 
    }
    if (p >= i) {
      right[i] = p; 
    }
  }  
} 

int main () {   
  std::cin >> n >> lim >> type;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  process();
  if (type == 1) {
    for (int i = 1; i <= n; i++) {
      int ans = 0; 
      int p = i; 
      if (right[p] != 0) {
        p = right[p]; 
        ans = p - i + 1; 
        if (p + 1 <= n) {
          p++;
          if (right[p] != 0) {
            p = right[p]; 
            ans = p - i + 1; 
          } 
        }
      }
      std::cout << ans << ' '; 
    }
  } 
  else {
    for (int i = 1; i < n; i++) {
      int lo = left[i];
      int hi = right[i + 1];
      if (lo != 0 && hi != 0) {
        int numbLeft = i - lo + 1; 
        int numbRight = hi - i;
        int minNumb = std::min(numbLeft, numbRight);
        f[i - minNumb + 1] = std::max(f[i - minNumb + 1], minNumb);    
      } 
    }
    for (int i = 2; i <= n; i++) {
      f[i] = std::max(f[i], std::max(0, f[i - 1] - 1)); 
    }
    for (int i = 1; i <= n; i++) {
      std::cout << 2 * f[i] << ' ';
    }
  }
  return 0; 
}