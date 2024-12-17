#include <bits/stdc++.h>

using namespace std;

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int x;
    long long m;
    cin >> x >> m;
    int lastbitx = -1; 
    for (int b = 0; b <= 20; b++) {
      if ((x & (1 << b)) > 0) {
        lastbitx = b;  
      }
    }          
    long long ans = 0;
    if (m <= x) {
      for (int i = 1; i <= m; i++) {
        int value = i ^ x;
        if (value % x == 0 || value % i == 0) {
          ans++; 
        }
      }
      cout << ans << endl;
      continue; 
    }                                   
    for (int y = 1; y <= min(m, (long long) (1LL << (lastbitx + 2)) - 1); y++) {
      int value = y ^ x; 
      if (value % y == 0 || value % x == 0) {
        ans++; 
      }
    }
    long long lo = 1LL << ((long long) (lastbitx + 2));
    long long hi = m;
    hi += x;             
    if (lo <= hi) {
      ans += hi / x; 
      ans -= (lo - 1) / x; 
    } 
    hi /= x; 
    lo = (lo - 1) / x;                  
    for (long long i = hi; i >= max(hi - x, lo + 1); i--) {
      long long y = i * x;
      y ^= x;
      if (y > m) {
        ans--; 
      } 
    }
    cout << ans << endl;
  }
  return 0; 
}