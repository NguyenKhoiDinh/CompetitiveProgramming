#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
int n; 
int a[1000005]; 
int f[1000005]; 
int maxValue[1000005];
int position[1000005]; 
int trace[1000005];  

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::reverse(a + 1, a + n + 1); 
  for (int i = 1; i <= n; i++) {
    f[i] = 1; 
    if (f[i] < maxValue[a[i] - 1] + 1) {
      f[i] = maxValue[a[i] - 1] + 1; 
      trace[i] = position[a[i] - 1]; 
    }
    if (maxValue[a[i]] < f[i]) {
      maxValue[a[i]] = f[i];
      position[a[i]] = i;
    }  
  }
  int last = -1;
  int ans = -1; 
  for (int i = 1; i <= n; i++) {
    if (ans < f[i]) {
      ans = f[i]; 
      last = i; 
    }
  }
  std::vector <int> res; 
  int p = last;
  do {
    res.push_back(p); 
    p = trace[p]; 
  } 
  while (p > 0);
  std::cout << (int) res.size() << std::endl;
  for (int i = 0; i < (int) res.size(); i++) {
    std::cout << n - res[i] + 1 << ' '; 
  }
  return 0; 
}