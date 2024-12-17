#include <bits/stdc++.h> 

using namespace std;
const int inf = 1000000007; 
int n, m; 
string a[1005];
int f[1005][12][(1 << 10) + 5];  

int main () {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = '_' + a[i];  
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int mask = 0; mask < (1 << m); mask++) {
        f[i][j][mask] = inf; 
      }
    }
  }
  f[0][m][0] = 0; 
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int mask = 0; mask < (1 << m); mask++) {
        if (a[i][j] == '.') {
          if ((mask & (1 << (j - 1))) > 0) {
            f[i][j][mask] = inf; 
          }
          else {
            if (j != 1) {
              f[i][j][mask] = min(f[i][j - 1][mask], f[i][j - 1][mask ^ (1 << (j - 1))]);
            }
            else {
              f[i][j][mask] = min(f[i - 1][m][mask], f[i - 1][m][mask ^ (1 << (j - 1))]); 
            }
          }
        }
        else {
          if ((mask & (1 << (j - 1))) > 0) {
            if (j != 1) {
              f[i][j][mask] = min(f[i][j - 1][mask], f[i][j - 1][mask ^ (1 << (j - 1))] + 1); 
            }
            else {
              f[i][j][mask] = min(f[i - 1][m][mask], f[i - 1][m][mask ^ (1 << (j - 1))] + 1); 
            }
          }
          else {
            if (j != 1) {
              f[i][j][mask] = min(f[i][j - 1][mask], f[i][j - 1][mask ^ (1 << (j - 1))]);   
            }
            else {
              f[i][j][mask] = min(f[i - 1][m][mask], f[i - 1][m][mask ^ (1 << (j - 1))]);
            }
            if (j == 1 || a[i][j - 1] == '.' || ((mask & (1 << (j - 2))) > 0)) {
              f[i][j][mask]++; 
            }
          }
        }
      }
    }
  }
  int ans = inf; 
  for (int mask = 0; mask < (1 << m); mask++) {
    ans = min(ans, f[n][m][mask]); 
  }
  cout << ans;
  return 0; 
}