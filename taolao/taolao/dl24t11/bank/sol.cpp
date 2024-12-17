#include <bits/stdc++.h> 

using namespace std;
const int mod = 1000000007; 
int f[22][(1 << 20) + 5];
int n, m;
int a[22], b[22];  
vector <int> listMask[22]; 
int numTest; 
long long sum[(1 << 20) + 5];
int g[(1 << 20) + 5][22];  
void sub2() {
  memset(g, 0, sizeof(g));
  if (n == 1) {
    cout << (int) listMask[0].size() << endl;
    return;
  }         
  for (int i = 0; i < (int) listMask[1].size(); i++) {
    g[listMask[1][i]][0]++; 
  }                   
  for (int i = 1; i <= 20; i++) {
    for (int mask = 0; mask < (1 << m); mask++) {
      if ((mask & (1 << (i - 1))) > 0) {
        g[i][mask] = (g[i - 1][mask] + g[i - 1][mask - (1 << (i - 1))]) % mod; 
      }
      else {
        g[i][mask] = g[i - 1][mask]; 
      }
    }
  }
  int ans = 0; 
  for (int i = 0; i < (int) listMask[0].size(); i++) {
    int mask = listMask[0][i];
    int other = (1 << m) - 1 - mask; 
    (ans += g[20][other]) %= mod; 
  }
  cout << ans << endl; 
}

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i]; 
      listMask[i].clear(); 
    }
    for (int i = 0; i < m; i++) {
      cin >> b[i]; 
    }
    for (int mask = 0; mask < (1 << m); mask++) {
      sum[mask] = 0LL; 
    }
    for (int mask = 0; mask < (1 << m); mask++) {
      for (int i = 0; i < m; i++) {
        if ((mask & (1 << i)) > 0) {
          sum[mask] += b[i]; 
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int mask = 0; mask < (1 << m); mask++) {
        if (a[i] == sum[mask]) {
          listMask[i].push_back(mask); 
        }   
      }
    }
    if (n <= 2) {
      sub2(); 
      continue; 
    }
    memset(f, 0, sizeof(f));
    f[0][0] = 1LL; 
    for (int i = 0; i < n; i++) {
      for (int mask = 0; mask < (1 << m); mask++) {
        if (f[i][mask] == 0) {
          continue; 
        }
        for (int j = 0; j < (int) listMask[i].size(); j++) {
          int nextMask = listMask[i][j]; 
          if ((mask & nextMask) == 0) {
            (f[i + 1][mask | nextMask] += f[i][mask]) %= mod; 
          }
        }
      }
    }
    int ans = 0; 
    for (int mask = 0; mask < (1 << m); mask++) {
      (ans += f[n][mask]) %= mod; 
    }
    cout << ans << endl; 
  }
  return 0; 
}