#include <bits/stdc++.h>

using namespace std;
const long long mod = 998244353LL; 
int nearest[200005]; 
vector <int> adj[200005]; 
int n; 
long long inv[200005]; 
long long ans[200005]; 
void dfs(int u, int father) {
  int minDistance = n + 100; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs(v, u); 
    minDistance = min(minDistance, 1 + nearest[v]); 
  }
  if (minDistance == n + 100) {
    nearest[u] = 0; 
  }
  else {
    nearest[u] = minDistance; 
  }
}
long long fastpow(const long long &x, long long n) {
  if (n == 0) {
    return 1LL;
  }
  long long ret = fastpow(x, n / 2);
  (ret *= ret) %= mod;
  if (n % 2 == 1) {
    (ret *= x) %= mod; 
  }
  return ret; 
}
void dfs2(int u, int father, long long ret) {
  ans[u] = ret; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    long long newRet = ret;
    (newRet *= nearest[v]) %= mod; 
    (newRet *= inv[nearest[v] + 1]) %= mod; 
    dfs2(v, u, newRet); 
  }
}

int main () {
  for (int i = 1; i <= 200002; i++) {
    inv[i] = fastpow(i, mod - 2); 
  }
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n; 
    for (int i = 1; i <= n; i++) {
      adj[i].clear(); 
      nearest[i] = 0; 
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u); 
    }
    dfs(1, -1); 
    dfs2(1, -1, 1); 
    for (int u = 1; u <= n; u++) {
      cout << ans[u] << ' ';
    }
    cout << endl;
  }
  return 0; 
}