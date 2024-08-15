#include <bits/stdc++.h>

using namespace std;
string s; 
int n, c, k; 
int sum[(1 << 18) + 5][18]; 
bool f[(1 << 18) + 5][18]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> c >> k;
    for (int mask = 0; mask < (1 << c); mask++) {
      for (int i = 0; i <= c; i++) {
        f[mask][i] = false; 
      }
    }
    cin >> s;
    for (int i = 1; i <= n; i++) {
      for (int ch = 0; ch < c; ch++) {
        sum[i][ch] = sum[i - 1][ch]; 
      }
      sum[i][s[i - 1] - 'A']++; 
    }
    int all = (1 << c) - 1; 
    for (int i = 0; i <= n - k; i++) {
      int mask = 0;
      int l = i;
      int r = l + k;
      for (int ch = 0; ch < c; ch++) {
        if (sum[r][ch] - sum[l][ch] > 0) {
          mask |= (1 << ch); 
        }           
      }
      f[all - mask][0] = true;   
    }
    f[all - (1 << (s.back() - 'A'))][0] = true; 
    for (int i = 1; i <= c; i++) {
      for (int mask = 0; mask < (1 << c); mask++) {
        if (f[mask][i - 1] == true) {
          f[mask][i] = true;
        }
        if ((mask & (1 << (i - 1))) == 0 && f[mask | (1 << (i - 1))][i - 1] == true) {
          f[mask][i] = true; 
        }
      }                 
    }
    int ans = n + 5; 
    for (int mask = 1; mask < (1 << c); mask++) {
      if (f[mask][c] == false) {
        ans = min(ans, __builtin_popcount(mask)); 
      }
    }
    cout << ans << endl;
  }
  return 0;      
}