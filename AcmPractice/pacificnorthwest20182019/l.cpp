#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 1005;
int l[MAX_N], r[MAX_N];
int n;

int main () {
  //freopen("input.txt", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  for (int ans = n; ans >= 0; ans--) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (l[i] <= ans && ans <= r[i]) {
        cnt++;
      }
    }
    if (cnt == ans) {
      cout << ans;
      return 0;
    }
  }
  cout << -1;
  return 0; 
}