#include <bits/stdc++.h>

using namespace std;    
const long long mod = 998244353LL; 
int deg[2005], parent[2005]; 
int n, numQueries; 
long long f[2005]; 
vector <int> adj[2005]; 
void dfs(int u, int father) {
  parent[u] = father;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs(v, u); 
  }
}
long long fastpow(const long long &x, const long long &n) {
  if (n % 2 == 0) {
    return 1LL; 
  }
  long long ret = fastpow(x, n / 2);
  (ret *= ret) %= mod;
  if (n % 2 == 1) {
    (ret *= x) %= mod; 
  }
  return ret; 
}

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> numQueries;
    for (int i = 1; i <= n; i++) {
      deg[i] = 0;
      parent[i] = -1;
      f[i] = 0;  
      adj[i].clear(); 
    }    
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      deg[u]++;
      deg[v]++; 
      adj[u].push_back(v);
      adj[v].push_back(u); 
    }
    dfs(1, -1);
    for (int query = 1; query <= numQueries; query++) {
      int u, coin;
      cin >> u >> coin;
      long long ans = 0LL;
      int steps = 1;
      priority_queue <int> pq; 
      while (u != 1) {
        if (steps == 1) {
          ans++; 
        }
        else {
          pq.push(2LL * deg[u] - 1); 
        }
        u = parent[u]; 
        steps = 1 - steps; 
      }  
      while (coin > 0 && pq.empty() == false) {
        pq.pop();
        coin--;
        ans++;  
      }
      while (pq.empty() == false) {
        int pqTop = pq.top(); 
        pq.pop(); 
        (ans += pqTop) %= mod; 
      }
      cout << ans << endl;
    } 
  }
  return 0; 
}