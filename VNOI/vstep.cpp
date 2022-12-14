#include <bits/stdc++.h>

using namespace std;
const int MOD = 14062008; 
int n, k; 
int mark[100005]; 
int f[100005]; 

int main () {
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    int pos;
    cin >> pos; 
    mark[pos] = 1; 
  }
  f[1] = 1; 
  for (int i = 1; i < n; i++) {
    if (f[i] == 0) {
      continue; 
    }
    if (mark[i + 1] == 0) {
      (f[i + 1] += f[i]) %= MOD; 
    }
    if (i + 2 <= n && mark[i + 2] == 0) {
      (f[i + 2] += f[i]) %= MOD; 
    }
  }
  cout << f[n];
  return 0; 
}