#include <iostream>
#include <deque>
#include <math.h>

using namespace std;
const int inf = 1000000007; 
int c[2000005], s[2000005]; 
int prefixMax[2000005], prefixMin[2000005], suffixMax[2000005], suffixMin[2000005];
int n; 
int f[2000005]; 
std::deque <int> dq2, dq3, dq4; 
                                                                         
int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i] >> s[i]; 
  }
  prefixMax[0] = -inf; 
  prefixMin[0] = inf; 
  for (int i = 1; i <= n; i++) {
    prefixMax[i] = std::max(prefixMax[i - 1], s[i]);
    prefixMin[i] = std::min(prefixMin[i - 1], s[i]);   
  }
  suffixMax[n + 1] = -inf; 
  suffixMin[n + 1] = inf;
  for (int i = n; i >= 1; i--) {
    suffixMax[i] = std::max(suffixMax[i + 1], s[i]); 
    suffixMin[i] = std::min(suffixMin[i + 1], s[i]); 
  }
  f[1] = -c[1];
  for (int i = 2; i <= n; i++) {
    f[i] = std::min(f[i - 1], -c[i]);
  }
  prefixMax[0] = 0;
  prefixMin[0] = 0;
  suffixMax[n + 1] = 0; 
  suffixMin[n + 1] = 0; 
  int ans = inf; 
  int l = 1;
  int i2 = 1, i3 = 1, i4 = 1; 
  for (int j = 1; j <= n; j++) {
    // max va min cung nam ben phai j 
    while (l <= j && (prefixMax[l - 1] < suffixMax[j + 1] || prefixMin[l - 1] > suffixMin[j + 1])) {
      l++; 
    }
    if (l > 1) {
      ans = std::min(ans, c[j] + suffixMax[j + 1] - suffixMin[j + 1] + f[l - 1]); 
    }
    // min ben trai i, max ben phai j
    while (i2 <= j && prefixMax[i2 - 1] <= suffixMax[j + 1] && prefixMin[i2 - 1] > suffixMin[j + 1]) {
      if (dq2.empty() == false && dq2.front() == i2) {
        dq2.pop_front(); 
      }
      i2++; 
    } 
    if (dq2.empty() == false) {
      ans = std::min(ans, c[j] + suffixMax[j + 1] - c[dq2.front()] - prefixMin[dq2.front() - 1]); 
    }
    while (dq2.empty() == false && -c[dq2.back()] - prefixMin[dq2.back() - 1] <= -c[j] - prefixMin[j - 1]) {
      dq2.pop_back(); 
    }
    dq2.push_back(j);
    // max ben trai i, min ben phai j
    while (i3 <= j && prefixMin[i3 - 1] >= suffixMin[j + 1] && prefixMax[i3 - 1] < suffixMax[j + 1]) {
      if (dq3.empty() == false && dq3.front() == i3) {
        dq3.pop_front(); 
      }
      i3++; 
    } 
    if (dq3.empty() == false) {
      ans = std::min(ans, c[j] - suffixMin[j + 1] - c[dq3.front()] + prefixMax[dq3.front() - 1]); 
    }
    while (dq3.empty() == false && -c[dq3.back()] + prefixMax[dq3.back() - 1] <= -c[j] + prefixMax[j - 1]) {
      dq3.pop_back(); 
    }
    dq3.push_back(j);                  
    // max va min nam ben trai i
    while (i4 <= j && (prefixMax[i4 - 1] >= suffixMax[j + 1] || prefixMin[i4 - 1] <= suffixMin[j + 1])) {
      
    }
  }  
  return 0; 
}