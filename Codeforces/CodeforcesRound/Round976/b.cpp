#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long k;
    cin >> k;
    long long ans = 0; 
    long long lo = 1LL, hi = 4000000000000000000LL;
    while (lo <= hi) {
      long long mid = (lo + hi) / 2;              
      if (mid - (long long) sqrt(mid) >= k) {
        ans = mid; 
        hi = mid - 1; 
      }
      else {
        lo = mid + 1; 
      }
    }  
    cout << ans << endl;
  }
  return 0; 
}           
