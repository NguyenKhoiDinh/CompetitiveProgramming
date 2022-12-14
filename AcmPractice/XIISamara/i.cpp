#include <bits/stdc++.h> 

using namespace std;

int main () {
  int a, b;
  cin >> a >> b;
  int k = a - b;
  long long ans = k;
  while (k >= 0) {
    ans += 2 * k;
    k -= b;
  }
  cout << ans;
  return 0; 
}