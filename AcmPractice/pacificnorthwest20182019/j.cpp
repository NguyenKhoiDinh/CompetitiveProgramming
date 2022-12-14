#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 105;
int n, s;
int t[MAX_N];

int main () {
  int slowest = -1;
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  for (int i = 1; i <= n; i++) {
    slowest = max(slowest, s * t[i]);
  }
  for (int ans = 1; ans <= 1000; ans++) {
    if (ans * 1000 >= slowest) {
      cout << ans;
      return 0;
    }
  }
  return 0; 
}