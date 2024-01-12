#include <bits/stdc++.h>
int numTest; 
int x[200005]; 
int m, R, n; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    cin >> m >> R >> n;
    for (int i = 1; i <= n; i++) {
      cin >> x[i]; 
    }
    int curPoint = 0;
    int ans = 0; 
    bool isValid = true; 
    int p = 1; 
    while (true) {                       
      if (curPoint < x[p] - R) {
        isValid = false; 
        break; 
      }  
      int prevPoint = curPoint; 
      ans++; 
      while (p <= n && prevPoint >= x[p] - R) {
        curPoint = x[p] + R; 
        p++; 
      }                                  
      if (p > n || curPoint >= m) {
        break; 
      }                            
    }
    if (isValid == false || curPoint < m) {
      cout << "IMPOSSIBLE" << endl; 
    }
    else {
      cout << ans << endl; 
    }
  }
  return 0; 
}