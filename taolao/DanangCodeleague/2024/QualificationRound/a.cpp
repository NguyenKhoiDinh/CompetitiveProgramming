#include <iostream>
#include <math.h> 
#include <string>
#include <vector>
const long long mod = 1000000007LL; 
int n; 
std::vector <std::string> a;
long long fastpow(const long long &x, const long long &n) {
  if (n == 0) {
    return 1LL;
  }
  long long ret = fastpow(x, n / 2); 
  (ret *= ret) %= mod;
  if (n % 2 == 1) {
    (ret *= x) %= mod; 
  }
  return ret; 
} 
int main () {
  std::cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i]; 
  }
  long long maxRow = -1, maxCol = -1; 
  for (int i = 0; i < n; i++) {
    int numb = 0;
    long long sum = 0LL; 
    for (int j = 0; j < n; j++) {
      if (a[i][j] == '#') {
        numb++; 
      }
      else {
        if (numb > 0) {
          (sum += fastpow(numb, numb)) %= mod;   
        }
        numb = 0; 
      }
    }
    if (numb > 0) {
      (sum += fastpow(numb, numb)) %= mod; 
    }
    maxRow = std::max(maxRow, sum); 
  }
  for (int j = 0; j < n; j++) {
    int numb = 0;
    long long sum = 0LL;
    for (int i = 0; i < n; i++) {
      if (a[i][j] == '#') {
        numb++; 
      }
      else {
        if (numb > 0) {
          (sum += fastpow(numb, numb)) %= mod;
        }
        numb = 0; 
      }
    }
    if (numb > 0) {
      (sum += fastpow(numb, numb)) %= mod; 
    }
    maxCol = std::max(maxCol, sum); 
  }
  std::cout << maxRow << ' ' << maxCol;
  return 0; 
}