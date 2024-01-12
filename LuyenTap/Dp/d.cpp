#include <bits/stdc++.h> 
 
using namespace std; 
const int MOD = 1000000007;
int pw3[11]; 
int n, m; 
int dp[1005][(1 << 10) + 3]; 
vector <int> listMask[(1 << 10) + 3];
bool validMask[(1 << 10) + 3];  
bool ok[(1 << 10) + 3][(1 << 10) + 3]; 
 
int main () {
  cin >> n >> m;
  for (int mask = 0; mask < (1 << n); mask++) {
    bool valid = true; 
    for (int i = 0; i < n; i++) { 
      if ((mask & (1 << i)) == 0) {
        if (i < n - 1 && (mask & (1 << (i + 1))) == 0) {
          i++; 
        }
        else {
          valid = false; 
          break; 
        }
      }
    }
    validMask[mask] = valid; 
  }
  pw3[0] = 1; 
  for (int i = 1; i <= n; i++) {
    pw3[i] = pw3[i - 1] * 3; 
  }
  for (int status = 0; status < pw3[n]; status++) {
    vector <int> state; 
    int tmp = status; 
    while (tmp > 0) {
      int r = tmp % 3; 
      tmp /= 3; 
      state.push_back(r); 
    }
    while ((int) state.size() < n) {
      state.push_back(0); 
    }
    reverse(state.begin(), state.end()); 
    bool valid = true; 
    for (int i = 0; i < n; i++) { 
      if (state[i] == 0) {
        if (i < n - 1 && state[i + 1] == 0) {
          i++; 
        }
        else {
          valid = false; 
          break; 
        }
      }
    }
    if (valid == true) {
      int mask = 0; 
      for (int i = 0; i < n; i++) {
        if (state[i] == 1) {
          mask += (1 << i); 
        }
      }
      int nextMask = 0; 
      for (int i = 0; i < n; i++) {
        if (state[i] == 2) {
          nextMask += (1 << i); 
        }
      }
      if (validMask[mask ^ nextMask] == true) {
        ok[mask][nextMask] = true; 
      }
    }
  }
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int nextMask = 0; nextMask < (1 << n); nextMask++) {
      if (ok[mask][nextMask] == true) {
        listMask[mask].push_back(nextMask);
      }
    }
  }
  dp[1][0] = 1; 
  for (int i = 1; i < m; i++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      if (dp[i][mask] == 0) {
        continue; 
      }
      for (int j = 0; j < (int) listMask[mask].size(); j++) {
        int nextMask = listMask[mask][j]; 
        (dp[i + 1][nextMask] += dp[i][mask]) %= MOD; 
      }
    }
  }
  int ans = 0; 
  for (int mask = 0; mask < (1 << n); mask++) {
    if (validMask[mask] == true) {
      (ans += dp[m][mask]) %= MOD; 
    }
  }
  cout << ans;
  return 0; 
}