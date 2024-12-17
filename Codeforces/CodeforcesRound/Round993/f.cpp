#include <iostream> 
#include <math.h> 
#include <set> 
int n, m, numQueries; 
int a[200005], b[200005]; 
bool posa[200005], nega[200005], posb[200005], negb[200005]; 
bool zeroa = false, zerob = false;  
long long suma = 0LL, sumb = 0LL; 
bool test(int d1, int d2) {
  if (d1 > 0 && posa[d1] == false) {
    return false; 
  } 
  if (d1 < 0 && nega[-d1] == false) {
    return false; 
  }
  if (d2 > 0 && posb[d2] == false) {
    return false; 
  }
  if (d2 < 0 && negb[-d2] == false) {
    return false; 
  }
  return true; 
}

int main () {
  std::cin >> n >> m >> numQueries;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    suma += a[i];
  } 
  for (int i = 1; i <= n; i++) {
    if (suma - a[i] < 0) {
      if (a[i] - suma <= 200000) {
        nega[a[i] - suma] = true; 
      } 
    }
    else if (suma - a[i] == 0) {
      zeroa = true; 
    }
    else {
      if (suma - a[i] <= 200000) {
        posa[suma - a[i]] = true; 
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
    sumb += b[i]; 
  }
  for (int i = 1; i <= m; i++) {
    if (sumb - b[i] < 0) {
      if (b[i] - sumb <= 200000) {
        negb[b[i] - sumb] = true; 
      }  
    }
    else if (sumb - b[i] == 0) {
      zerob = true; 
    }
    else {
      if (sumb - b[i] <= 200000) {
        posb[sumb - b[i]] = true; 
      }
    }
  }
  for (int query = 1; query <= numQueries; query++) {
    long long x;
    std::cin >> x; 
    if (x == 0) {
      if (zeroa == true || zerob == true) {
        std::cout << "YES" << std::endl; 
      }
      else {
        std::cout << "NO" << std::endl; 
      }
      continue; 
    }
    bool ok = false; 
    for (int d = -(int) std::sqrt(std::abs(x)); d <= (int) std::sqrt(std::abs(x)); d++) {
      if (d != 0 && x % d == 0) {
        int rest = x / d;
        if (test(d, rest) == true || test(rest, d) == true) {
          ok = true;
          break; 
        } 
      }  
    }
    std::cout << (ok == true ? "YES" : "NO") << std::endl; 
  } 
  return 0; 
}