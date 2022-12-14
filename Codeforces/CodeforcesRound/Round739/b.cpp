#include <bits/stdc++.h> 

using namespace std;

int main () {
  int test;
  cin >> test;
  for (int tt = 1; tt <= test; tt++) {
    int a, b, c;
    cin >> a >> b >> c;
    int d = abs(a - b);
    int n = 2 * d; 
    if (c > n || a > n || b > n) {
      cout << -1 << endl;
      continue;
    }
    int ans = (c + d) % n;
    if (ans == 0) {
      ans = n;
    }
    cout << ans << endl;
  }
  return 0; 
}