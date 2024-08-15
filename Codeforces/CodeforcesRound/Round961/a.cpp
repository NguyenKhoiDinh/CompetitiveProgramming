#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, k;
    cin >> n >> k;
    if (k == 0) {
      cout << 0; 
    }  
    else if (k <= n) {
      cout << 1; 
    }
    else {
      int ans = 1; 
      k -= n; 
      int t = n - 1; 
      while (k > 0) {
        if (k <= t) {
          ans++;
          break;   
        }
        else if (k <= 2 * t) {
          ans += 2;
          break; 
        }
        else {
          k -= 2 * t;
          t--; 
          ans += 2; 
        }
      }
      cout << ans;
    }
    cout << endl;
  }
  return 0; 
}