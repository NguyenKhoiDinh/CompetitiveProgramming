#include <bits/stdc++.h>

using namespace std;
const int inf = 1000000007; 
int l, n, m; 
int f0[1505][1505], f1[1505][1505];
int a[1505];
int b[1505][1505];  
int index[3000005]; 

int main () {
  ios_base::sync_with_stdio(false); 
  int numTest;
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> l >> n >> m;
    for (int i = 1; i <= l; i++) {
      cin >> a[i];
      if (index[a[i]] == 0) {
        index[a[i]] = i; 
      } 
    }    
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> b[i][j]; 
      }
    }
    for (int i = 1; i <= n + 1; i++) {
      for (int j = 1; j <= m + 1; j++) {
        f0[i][j] = inf;
        f1[i][j] = inf;  
      }
    }
    for (int i = n; i >= 1; i--) {
      for (int j = m; j >= 1; j--) {
        f0[i][j] = min(f0[i + 1][j], f0[i][j + 1]);
        f1[i][j] = min(f1[i + 1][j], f1[i][j + 1]);
        if (index[b[i][j]] != 0) {
          if (index[b[i][j]] % 2 == 0 && index[b[i][j]] + 3 <= f1[i + 1][j + 1]) {
            f0[i][j] = min(f0[i][j], index[b[i][j]]); 
          }
          if (index[b[i][j]] % 2 == 1 && index[b[i][j]] + 3 <= f0[i + 1][j + 1]) {
            f1[i][j] = min(f1[i][j], index[b[i][j]]); 
          }
        }  
      }
    }
    for (int i = 1; i <= l; i++) {
      index[a[i]] = 0; 
    }
    if (f1[1][1] == 1) {
      cout << 'T'; 
    }
    else {
      cout << 'N'; 
    }
    cout << endl; 
  }
  return 0;                              
}