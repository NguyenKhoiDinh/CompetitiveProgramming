#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 10005; 
int a[MAX_N];
int n; 

int main () {
  cin >> n;
  int res = 0; 
  int len = 0; 
  for (int i = 1; i <= n; i++) {
    int x; 
    cin >> x;
    a[i] = x;
    x *= 2; 
    int delta = 1 + 4 * x;
    int sqrtDelta = (int) sqrt(delta);
    if (sqrtDelta * sqrtDelta == delta) {
      if (a[i] >= a[i - 1]) {
        len++; 
      }
      else {
        len = 1;
      }
    }
    else {
      len = 0; 
    }
    res = max(res, len);
  }
  cout << res;
  return 0; 
}