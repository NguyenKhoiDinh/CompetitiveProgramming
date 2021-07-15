#include <bits/stdc++.h>

using namespace std;

int main () {
  int p, n; 
  int ans = 1000000007;
  cin >> n >> p;
  int tmp = p; 
  for (int i = 2; i <= tmp; i++) {
    if (p % i == 0) {
      int deg = 0; 
      while (p % i == 0) {
        p /= i; 
        deg++; 
      }
      int mul = i; 
      int cnt = 0; 
      while (mul <= n) {
        cnt += n / mul; 
        mul *= i; 
      }
      ans = min(ans, cnt / deg);
    }
  }
  cout << ans; 
  return 0; 
}