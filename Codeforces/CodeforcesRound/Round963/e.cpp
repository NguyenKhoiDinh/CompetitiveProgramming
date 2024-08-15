#include <bits/stdc++.h>

using namespace std;
const int inf = 1000000007; 
vector <vector <int> > a; 
int n, m; 
int f[(1 << 16) + 5][16];
int cost[16][16];

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++) {
      a[i].resize(m); 
    }  
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j]; 
      }
    }
    for (int i = 0; i < n; i++) {
      int sumXor = 0;
      for (int j = 0; j < m; j++) {
        sumXor ^= a[i][j]; 
      }
      a[i].push_back(sumXor); 
    }
    m++; 
    vector <int> extra; 
    for (int j = 0; j < m; j++) {
      int sumXor = 0;
      for (int i = 0; i < n; i++) {
        sumXor ^= a[i][j]; 
      }
      extra.push_back(sumXor); 
    }
    a.push_back(extra); 
    n++;  
    vector <vector <int> > fRow; 
    fRow.resize(n);
    for (int i = 0; i < n; i++) {
      fRow[i].resize(m, inf); 
    }
    vector <vector <int> > fCol = fRow; 
    for (int del = 0; del < m; del++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cost[i][j] = 0; 
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (i != j) {
            for (int k = 0; k < m; k++) {
              if (k == del) {
                continue; 
              }
              cost[i][j] += abs(a[i][k] - a[j][k]); 
            }
          }
        }
      }
      for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
          f[mask][i] = inf; 
        }
      }
      for (int i = 0; i < n; i++) {
        f[1 << i][i] = 0; 
      }  
      for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
          if (f[mask][i] == inf) {
            continue; 
          }
          for (int j = 0; j < n; j++) {
            if ((mask & (1 << j)) == 0) {
              f[mask | (1 << j)][j] = min(f[mask | (1 << j)][j], f[mask][i] + cost[i][j]); 
            }
          }
        }
      }
      for (int mask = 0; mask < (1 << n); mask++) {
        if ((int) __builtin_popcount(mask) == n - 1) {
          int lost = -1; 
          for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) {
              lost = i;
              break; 
            }
          }
          for (int i = 0; i < n; i++) {
            if (f[mask][i] != inf) {
              fRow[lost][del] = min(fRow[lost][del], f[mask][i]); 
            }
          }
        }
      }
    }               
    for (int del = 0; del < n; del++) {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
          cost[i][j] = 0; 
        }
      }
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
          if (i != j) {
            for (int k = 0; k < n; k++) {
              if (k == del) {
                continue; 
              }
              cost[i][j] += abs(a[k][i] - a[k][j]); 
            }
          }
        }
      }                      
      for (int mask = 0; mask < (1 << m); mask++) {
        for (int i = 0; i < m; i++) {
          f[mask][i] = inf; 
        }
      }
      for (int i = 0; i < m; i++) {
        f[1 << i][i] = 0; 
      }  
      for (int mask = 0; mask < (1 << m); mask++) {
        for (int i = 0; i < m; i++) {
          if (f[mask][i] == inf) {
            continue; 
          }
          for (int j = 0; j < m; j++) {
            if ((mask & (1 << j)) == 0) {
              f[mask | (1 << j)][j] = min(f[mask | (1 << j)][j], f[mask][i] + cost[i][j]); 
            }
          }
        }
      }                      
      for (int mask = 0; mask < (1 << m); mask++) {
        if ((int) __builtin_popcount(mask) == m - 1) {
          int lost = -1; 
          for (int i = 0; i < m; i++) {
            if ((mask & (1 << i)) == 0) {
              lost = i;
              break; 
            }
          }
          for (int i = 0; i < m; i++) {
            if (f[mask][i] != inf) {
              fCol[del][lost] = min(fCol[del][lost], f[mask][i]); 
            }
          }
        }
      }
    }               
    int ans = inf; 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans = min(ans, fRow[i][j] + fCol[i][j]); 
      }
    }
    cout << ans << endl; 
  }
  return 0; 
}