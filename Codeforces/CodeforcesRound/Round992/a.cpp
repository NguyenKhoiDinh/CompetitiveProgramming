#include <bits/stdc++.h>

using namespace std;
int n, k;
int a[105];

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }  
    int ans = -1; 
    for (int i = 1; i <= n; i++) {
      bool ok = true; 
      for (int j = 1; j <= n; j++) {
        if (j != i) {
          if (abs(a[i] - a[j]) % k == 0) {
            ok = false;
          }  
        }
      }
      if (ok == true) {
        ans = i;
        break;
      }
    }
    if (ans != -1) {
      cout << "YES" << endl;
      cout << ans << endl; 
    }
    else {
      cout << "NO" << endl;
    }
  }
  return 0; 
}