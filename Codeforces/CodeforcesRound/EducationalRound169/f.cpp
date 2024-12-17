#include <bits/stdc++.h>

using namespace std;
int f[2005][2005]; 
int a[2005]; 
int sum[2005]; 
map <int, int> cnt; 
int n; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cnt.clear(); 
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum[i] = sum[i - 1] + a[i]; 
    }
    int ans = 0;  
    for (int len = 1; len <= n; len++) {
      for (int l = 1, r = len; r <= n; l++, r++) {
        ans += len - 1; 
        ans -= 2 * cnt[sum[l] + sum[r - 1]]; 
      }
      for (int l = 1, r = len; r <= n; l++, r++) {
        cnt[sum[l - 1] + sum[r]]++; 
      }
    }   
    cout << ans << endl; 
  }
  return 0; 
}
