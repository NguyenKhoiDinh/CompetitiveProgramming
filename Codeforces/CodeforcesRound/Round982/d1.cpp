#include <bits/stdc++.h>

using namespace std;
const long long inf = 1000000000000007LL; 
int a[300005];
int b[300005]; 
int n, m; 
long long sum[300005]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m; 
    vector <vector <long long> > f(n + 5); 
    for (int i = 0; i <= n; i++) {
      f[i].resize(m + 5, inf); 
    }
    vector <vector <int> > nextPos(n + 5); 
    for (int i = 0; i <= n; i++) {
      nextPos[i].resize(m + 5, 0); 
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum[i] = sum[i - 1] + a[i]; 
    }
    for (int i = 1; i <= m; i++) {
      cin >> b[i]; 
    }
    for (int j = 1; j <= m; j++) {
      for (int i = 0; i < n; i++) {
        long long value = b[j] + sum[i]; 
        int lo = i + 1;
        int hi = n; 
        int pos = -1; 
        while (lo <= hi) {
          int mid = (lo + hi) / 2; 
          if (sum[mid] <= value) {
            pos = mid; 
            lo = mid + 1; 
          }
          else {
            hi = mid - 1; 
          }
        }
        nextPos[i][j] = pos; 
      }
    }
    f[0][1] = 0;
    for (int i = 0; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (f[i][j] == inf) {
          continue; 
        }
        if (j < m) {
          f[i][j + 1] = min(f[i][j + 1], f[i][j]); 
        }
        if (nextPos[i][j] != -1) {
          int p = nextPos[i][j]; 
          f[p][j] = min(f[p][j], f[i][j] + m - j); 
        }
      }
    }
    cout << (f[n][m] == inf ? -1 : f[n][m]) << endl;  
  }
  return 0; 
}