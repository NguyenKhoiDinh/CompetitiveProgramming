#include <bits/stdc++.h>

using namespace std;

int rev(int v) {
  int res = 0;
  while (v > 0) {
    int r = v % 10;
    v /= 10; 
    res = res * 10 + r; 
  }
  return res;
}

int main () {
  int l, r;
  cin >> l >> r;
  int ans = 0;
  for (int i = l; i <= r; i++) {
    int revNumb = rev(i); 
    if (__gcd(i, revNumb) == 1) {
      ans++; 
    }
  }
  cout << ans;
  return 0; 
}