#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm> 
struct element {
  int mask; 
  std::vector <int> dig; 
};
int n; 
long long a[105]; 
std::vector <element> v; 
int pw3 = 1;
long long f[105][59100];
std::vector <int> v3[59100];   
element build(const long long &x) {
  element ret;
  ret.mask = -1;  
  long long tmp = x; 
  ret.dig.resize(10, 0); 
  while (tmp > 0) {
    int d = tmp % 10;
    tmp /= 10; 
    ret.dig[d]++; 
  }
  for (int i = 0; i < 10; i++) {
    if (ret.dig[i] > 2) {
      return ret; 
    }  
  }
  int mask = 0; 
  int mul = 1; 
  for (int i = 0; i < 10; i++) {
    mask += ret.dig[i] * mul;
    mul *= 3; 
  }
  ret.mask = mask; 
  return ret; 
}
std::vector <int> convertToVector(int mask) {
  std::vector <int> ret; 
  while (mask > 0) {
    ret.push_back(mask % 3);
    mask /= 3; 
  }
  while ((int) ret.size() < 10) {
    ret.push_back(0); 
  }                                     
  return ret; 
}

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int numTest;
  std::cin >> numTest;
  for (int i = 1; i <= 10; i++) {
    pw3 *= 3; 
  }
  for (int mask = 0; mask < pw3; mask++) {
    v3[mask] = convertToVector(mask); 
  }
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    } 
    v.clear(); 
    for (int i = 1; i <= n; i++) {
      v.push_back(build(a[i])); 
    }
    for (int i = 0; i <= n; i++) {
      for (int mask = 0; mask < pw3; mask++) {
        f[i][mask] = -1; 
      }
    }
    f[0][0] = 0; 
    for (int i = 0; i < n; i++) {
      for (int mask = 0; mask < pw3; mask++) {
        if (f[i][mask] == -1) {
          continue; 
        }
        f[i + 1][mask] = std::max(f[i + 1][mask], f[i][mask]);
        std::vector <int> &digBaseOnMask = v3[mask]; 
        if (v[i].mask != -1) {
          bool check = true; 
          std::vector <int> &dig = v3[v[i].mask]; 
          for (int j = 0; j < 10; j++) {
            if (digBaseOnMask[j] + dig[j] > 2) {
              check = false; 
              break; 
            }
          }
          if (check == true) {
            std::vector <int> newDig = dig;
            for (int j = 0; j < 10; j++) {
              newDig[j] += digBaseOnMask[j]; 
            } 
            int nextMask = 0; 
            int mul3 = 1; 
            for (int j = 0; j < 10; j++) {
              nextMask += mul3 * newDig[j];
              mul3 *= 3;  
            }
            f[i + 1][nextMask] = std::max(f[i + 1][nextMask], f[i][mask] + a[i + 1]); 
          }
        } 
      }
    }
    long long ans = -1; 
    for (int mask = 0; mask < pw3; mask++) {
      ans = std::max(ans, f[n][mask]); 
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}