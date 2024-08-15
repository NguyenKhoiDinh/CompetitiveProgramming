#include <bits/stdc++.h>

using namespace std;
int f[500005]; 
int n, k; 
int a[500005];

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }  
    int need = n % k; 
    if (need == 0) {
      need = k; 
    }
    int half = (need + 1) / 2; 
    int ans = -1; 
    int lo = 1; 
    int hi = 1000000000; 
    while (lo <= hi) {
      int mid = (lo + hi) / 2; 
      for (int i = 0; i <= need; i++) {
        f[i] = -1;   
      }
      f[0] = 0; 
      for (int i = 1; i <= n; i++) {
        int p = i % k; 
        if (p == 0 && need == k) {
          p = k;   
        }
        if (p == 0) {
          continue;
        }
        if (f[p - 1] != -1) {
          f[p] = max(f[p], f[p - 1] + (a[i] >= mid ? 1 : 0));   
        }
      }
      if ((need % 2 == 1 && f[need] >= half) || (need % 2 == 0 && f[need] > half)) {
        ans = mid; 
        lo = mid + 1; 
      }
      else {
        hi = mid - 1; 
      }
    }
    cout << ans << endl;
  }
  return 0; 
}