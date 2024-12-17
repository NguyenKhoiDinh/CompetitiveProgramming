#include <iostream> 
#include <math.h> 
#include <vector> 
long long n;
int k;  
std::vector <int> listPrimes; 
long long ans = 0LL; 
bool checkPrime(int p) {
  for (int i = 2; i <= (int) std::sqrt(p); i++) {
    if (p % i == 0) {
      return false; 
    }
  }
  return true; 
}
void init() {
  for (int i = 2; i <= 1000000; i++) {
    if (checkPrime(i) == true) {
      listPrimes.push_back(i); 
    }
  }
}
void solve(int p1, int p2, int p3, int t1, int t2, int t3) {
  long long mul = 1LL; 
  for (int i = 1; i <= t1; i++) {
    if (mul <= n / p1) {
      mul *= p1; 
    }
    else {
      return; 
    }
  }
  for (int i = 1; i <= t2; i++) {
    if (mul <= n / p2) {
      mul *= p2; 
    }
    else {
      return; 
    }
  }
  for (int i = 1; i <= t3; i++) {
    if (mul <= n / p3) {
      mul *= p3; 
    }
    else {
      return;
    }
  }
  ans = std::max(ans, mul); 
}

int main () {
  init(); 
  std::cin >> n >> k;
  for (int t1 = 1; t1 <= 63; t1++) {
    for (int t2 = t1; t2 <= 63; t2++) {
      for (int t3 = t2; t3 <= 63; t3++) {
        if ((t1 + 1) * (t2 + 1) * (t3 + 1) == k) {
          for (int i = 0; i < (int) listPrimes.size() - 2; i++) {
            int p1 = listPrimes[i];
            int p2 = listPrimes[i + 1];
            int p3 = listPrimes[i + 2]; 
            solve(p1, p2, p3, t1, t2, t3);
            solve(p1, p3, p2, t1, t2, t3);
            solve(p2, p1, p3, t1, t2, t3);
            solve(p2, p3, p1, t1, t2, t3);
            solve(p3, p1, p2, t1, t2, t3);
            solve(p3, p2, p1, t1, t2, t3); 
          }  
        }
      }
    }
  }
  std::cout << ans;
  return 0; 
}