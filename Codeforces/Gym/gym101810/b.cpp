#include <iostream>
int numTest; 
long long cnt[1005]; 
int n;
long long x; 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> x >> n; 
    if (n == 1) {
      std::cout << x << std::endl;
      continue; 
    }
    for (int i = 1; i <= n; i++) {
      cnt[i] = 0; 
    }
    int len = n + n - 2;
    long long cycle = x / len;
    cnt[1] += cycle;
    cnt[n] += cycle;
    for (int i = 2; i < n; i++) {
      cnt[i] += 2LL * cycle; 
    } 
    x %= len; 
    for (int i = 1; i <= n; i++) {
      if (x == 0) {
        break;
      }
      cnt[i]++; 
      x--; 
    }
    for (int i = n - 1; i >= 2; i--) {
      if (x == 0) {
        break; 
      }
      cnt[i]++;
      x--; 
    }
    for (int i = 1; i <= n; i++) {
      std::cout << cnt[i] << ' '; 
    }
    std::cout << std::endl;
  }
  return 0; 
}