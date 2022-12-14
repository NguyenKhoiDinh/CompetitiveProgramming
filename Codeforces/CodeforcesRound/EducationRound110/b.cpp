#include <bits/stdc++.h>

using namespace std;
int numTest;
int a[2005];
int n;

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int odd = 0, even = 0; 
    for (int i = 1; i <= n; i++) {
      if (a[i] % 2 == 1) {
        odd++;
      }
      else {
        even++;
      }
    }
    int ans = odd * even + even * (even - 1) / 2;
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (a[i] % 2 == 1 && a[j] % 2 == 1) {
          if (__gcd(a[i], a[j]) > 1) {
            ans++;
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}