#include <bits/stdc++.h>

using namespace std;
int numTest; 
string a, b; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, m;
    cin >> n >> m; 
    cin >> a >> b; 
    int pa = 0;
    int pb = 0; 
    int ans = 0; 
    while (pa < n) {
      while (pb < m) {
        if (b[pb] == a[pa]) {
          ans++; 
          pb++;
          break; 
        }
        pb++; 
      }
      if (pb == m) {
        break; 
      }
      pa++;
    }
    cout << ans << endl;
  }
  return 0; 
}