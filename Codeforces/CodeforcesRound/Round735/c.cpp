#include <bits/stdc++.h> 

using namespace std;
long long n, m; 
int numTest;

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    long long tmp = n; 
    if (m < n) {
      cout << 0 << endl;
      continue;  
    }
    long long res = 0; 
    while (true) {
      if (n > m) {
        break;
      }
      bool found = false; 
      for (int b = 32; b >= 0; b--) {
        if (((m & (1LL << (long long) b)) > 0) && ((n & (1LL << (long long) b)) == 0)) {
          n ^= (1LL << (long long) b);
          res += (1LL << (long long) b);
          found = true; 
          break;   
        }
      }
      if (found == false) {
        break;
      } 
    } 
    if (n == m) {
      int pos = -1; 
      for (int b = 0; b <= 32; b++) {
        if ((n & (1LL << (long long) b)) == 0) {
          res += (1LL << (long long) b); 
          pos = b; 
          break; 
        }
      }
      for (int b = pos - 1; b >= 0; b--) {
        if (((n & (1LL << (long long) b)) > 0) && ((tmp & (1LL << (long long) b)) == 0)) {
          res -= (1LL << (long long) b);
        }
      }                                
    }                     
    cout << res << endl;
  }
  return 0;
}                                 