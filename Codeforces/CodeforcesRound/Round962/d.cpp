#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, x;
    cin >> n >> x;
    long long ans = 0LL; 
    for (int a = 1; a <= min(1000, x); a++) {
      for (int b = a; b <= min(1000, x); b++) {
        if (a + b <= x && a * b <= n) {
          long long lim = min(x - a - b, (n - a * b) / (a + b));
          if (lim >= b) {
            lim -= b - 1;
            if (a == b) {
              ans++; 
              ans += (lim - 1) * 3; 
            }
            else {
              ans += 3; 
              ans += (lim - 1) * 6; 
            } 
          }  
        }
      }
    }
    cout << ans << endl;  
  }
  return 0; 
}