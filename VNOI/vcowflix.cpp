#include <bits/stdc++.h>

using namespace std;
int W, n;
int a[16]; 

int main () {
  cin >> W >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int res = -1; 
  for (int mask = 0; mask < (1 << n); mask++) {
    int sum = 0; 
    for (int i = 0; i < n; i++) {
      if ((mask & (1 << i)) > 0) {
        sum += a[i]; 
      }
    }
    if (sum <= W) {
      res = max(res, sum);
    }
  }
  cout << res;
  return 0; 
}