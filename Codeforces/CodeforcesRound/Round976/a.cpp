#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long n, k;
    cin >> n >> k; 
    if (k == 1) {
      cout << n << endl;
      continue; 
    }
    long long ans = 0; 
    while (n >= k) {
      long long mul = k; 
      while (mul <= n) {
        mul *= k;   
      }                   
      if (mul > n) {
        mul /= k;
      }        
      n -= mul;  
      ans++;
    }
    ans += n;
    cout << ans << endl;
  }
  return 0; 
}