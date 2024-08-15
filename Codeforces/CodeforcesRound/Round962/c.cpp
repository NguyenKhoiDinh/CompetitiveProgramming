#include <bits/stdc++.h>

using namespace std;
int suma[200005][26], sumb[200005][26]; 
string a, b; 
int n, numQueries; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> numQueries; 
    cin >> a >> b; 
    for (int i = 1; i <= n; i++) {
      for (int ch = 0; ch < 26; ch++) {
        suma[i][ch] = 0; 
        sumb[i][ch] = 0; 
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int ch = 0; ch < 26; ch++) {
        suma[i][ch] = suma[i - 1][ch]; 
        sumb[i][ch] = sumb[i - 1][ch]; 
      }
      suma[i][a[i - 1] - 'a']++; 
      sumb[i][b[i - 1] - 'a']++;                
    }   
    for (int query = 1; query <= numQueries; query++) {
      int l, r;
      cin >> l >> r; 
      int ans = 0; 
      for (int ch = 0; ch < 26; ch++) {
        int numba = suma[r][ch] - suma[l - 1][ch]; 
        int numbb = sumb[r][ch] - sumb[l - 1][ch]; 
        if (numba < numbb) {
          ans += numbb - numba; 
        }
      }
      cout << ans << endl;
    }
  }
  return 0; 
}