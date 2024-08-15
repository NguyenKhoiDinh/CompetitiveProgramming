#include <bits/stdc++.h>

using namespace std; 
int nxt[305][305]; 
int a[305]; 
int f[(1 << 20) + 2]; 
int n, k; 
int trace[(1 << 20) + 2]; 

int main () {
  int ST = clock();
  mt19937 g{1919810}; 
  std::srand (unsigned(std::time(0))); 
  cin >> n >> k;
  const int inf = n + 2; 
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i]--; 
  }
  for (int i = 0; i <= n + 2; i++) {
    for (int j = 0; j < k; j++) {
      nxt[i][j] = inf; 
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (nxt[i][a[j]] == inf) {
        nxt[i][a[j]] = j; 
      }
    }
  }
  if (k >= 20) {
    vector <int> tmp;
    for (int i = 0; i < k; i++) {
      tmp.push_back(i); 
    }
    while (true) {
      bool ok = true; 
      shuffle(tmp.begin(), tmp.end(), g); 
      int start = 0; 
      for (int i = 0; i < k; i++) {
        if (nxt[start][tmp[i]] == inf) {
          ok = false;
          break; 
        }  
        start = nxt[start][tmp[i]]; 
      }
      if (ok == false) {
        for (int i = 0; i < k; i++) {
          cout << tmp[i] + 1 << ' ';   
        }
        return 0; 
      }
    }
    return 0; 
  }
  for (int mask = 0; mask < (1 << k); mask++) {
    f[mask] = -1; 
  }
  f[0] = 0;
  for (int mask = 0; mask < (1 << k); mask++) {
    if (f[mask] == -1) {
      continue; 
    }
    for (int u = 0; u < k; u++) {
      if ((mask & (1 << u)) == 0 && f[mask | (1 << u)] < nxt[f[mask]][u]) {
        f[mask | (1 << u)] = nxt[f[mask]][u];
        trace[mask | (1 << u)] = u;    
      } 
    }
  }
  if (f[(1 << k) - 1] <= n) {
    cout << "*";
    return 0; 
  }
  else {
    int last = (1 << k) - 1;
    vector <int> ans;
    while (last > 0) {
      ans.push_back(trace[last] + 1); 
      last ^= (1 << trace[last]);    
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int) ans.size(); i++) {
      cout << ans[i] << ' '; 
    }
  }
  return 0; 
}