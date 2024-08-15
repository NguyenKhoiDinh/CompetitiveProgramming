#include <bits/stdc++.h>

using namespace std;
long double a[200005]; 
int n; 
long double b[200005]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }
    bool ok = false; 
    int p = 1; 
    while (p <= n && a[p] == 1.0) {
      p++;
    }
    for (int i = p + 1; i <= n; i++) {
      if (a[i - 1] > 1.0 && a[i] == 1.0) {
        ok = true;
        break;  
      }  
    }
    if (ok == true) {
      cout << -1 << endl;
      continue; 
    }
    long double l2 = log(2); 
    for (int i = p; i <= n; i++) {
      b[i] = log(log((long double) a[i])); 
    }
    long long ans = 0LL; 
    const long double eps = 1e-9; 
    for (int i = p + 1; i <= n; i++) {
      if (b[i - 1] - b[i] <= eps) {
        continue; 
      } 
      int cnt = 1 + (int) (1.0 * ((b[i - 1] - b[i] - eps) / l2));
      ans += cnt;  
      b[i] += cnt * l2; 
    }
    cout << ans << endl; 
  }
  return 0; 
}                  