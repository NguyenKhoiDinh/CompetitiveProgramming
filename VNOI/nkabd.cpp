#include <bits/stdc++.h>

using namespace std;

int main () {
  int l, r;
  cin >> l >> r;
  int ans = 0;
  for (int i = l; i <= r; i++) {
    int sum = 1; 
    for (int j = 2; j <= (int) sqrt(i); j++) {
      if (i % j == 0) {
        sum += j; 
        if (i / j != j) {
          sum += i / j; 
        }
      }
    }
    if (sum > i) {
      ans++;
    }
  }
  cout << ans;
  return 0; 
}