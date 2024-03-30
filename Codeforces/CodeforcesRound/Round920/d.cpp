#include <iostream>
#include <vector>   
#include <algorithm>
#include <math.h> 
int numTest; 
int n, m;
std::vector <int> a, b; 

long long calc(const std::vector <int> &a, const std::vector <int> &b) {
  int l = 0;
  int r = m - n; 
  long long ans = 0LL; 
  while (l < n) {
    long long value = std::abs(a[l] - b[l]); 
    value = std::max(value, (long long) std::abs(a[l] - b[r])); 
    ans += value;
    l++; 
    r++; 
  }
  return ans; 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    a.clear();
    b.clear(); 
    a.resize(n);
    b.resize(m); 
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
      std::cin >> b[i];
    }
    std::sort(b.begin(), b.end());
    long long ans = calc(a, b);
    std::reverse(b.begin(), b.end());
    ans = std::max(ans, calc(a, b)); 
    std::reverse(a.begin(), a.end());
    ans = std::max(ans, calc(a, b)); 
    std::reverse(b.begin(), b.end());
    ans = std::max(ans, calc(a, b));  
    std::cout << ans << std::endl;
  }
  return 0; 
}