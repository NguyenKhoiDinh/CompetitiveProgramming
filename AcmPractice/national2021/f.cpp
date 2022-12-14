#include <bits/stdc++.h> 

using namespace std; 

long long f[55][55]; 
int n; 
int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    f[i][1] = 1; 
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= i; j++) {
      f[i][j] = f[i - 1][j] + f[i - 1][j - 1]; 
    }
  }
  long long ans = 0LL;
  for (int j = 1; j <= n; j++) {
    ans += f[n][j]; 
  }
  cout << ans;
  return 0; 
}