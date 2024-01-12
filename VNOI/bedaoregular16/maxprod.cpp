#include <iostream>
#include <algorithm> 
long long a[100005], b[100005];
long long k; 
int n; 
long long ans = 0LL; 

int main () {
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i]; 
  }
  for (int i = 1; i <= n; i++) {
    ans += 1LL * a[i] * b[i]; 
    if (a[i] > b[i]) {
      std::swap(a[i], b[i]); 
    }
  }
  long long sum = 0LL;
  for (int i = 1; i <= n; i++) {
    sum += a[i] * b[i]; 
  }
  long long ans = 0LL;
  for (int i = 1; i <= n; i++) {
    long long tmp = k; 
    if (tmp < b[i] - a[i]) {
      ans = std::max(ans, sum + tmp * b[i]);  
    }
    else {
      long long tmpSum = sum;
      tmpSum += (b[i] - a[i]) * b[i];
      tmp -= b[i] - a[i];
      long long x = tmp / 2; 
      long long y = tmp - x; 
      tmpSum += b[i] * tmp;
      tmpSum += x * y; 
      ans = std::max(ans, tmpSum); 
    }
  } 
  std::cout << ans;
  return 0;
}