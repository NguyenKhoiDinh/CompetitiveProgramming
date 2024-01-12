#include <iostream> 
#include <vector> 
#include <algorithm>
#include <math.h> 
const long long mod = 1000000007LL; 
int n, m, k;
std::vector <int> adj[100005];
std::vector <int> listVertex;
int position[100005];
int chainStart[100005];
int level[100005];
int parent[100005];
int f[100005][18];
int sz[100005];                
int chain = 0; 
int chainIndex[100005]; 
std::vector <int> freq1, freq2; 
long long fact[100005], inv_fact[100005];

long long fastpow(const long long &x, const long long &n) {
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

void init() {
  fact[0] = 1LL; 
  inv_fact[0] = 1LL; 
  for (int i = 1; i <= m; i++) {
    fact[i] = (fact[i - 1] * (long long) i) % mod; 
    inv_fact[i] = fastpow(fact[i], mod - 2); 
  }
} 

long long C(int n, int k) {
  if (n < k) {
    return 0LL; 
  }
  long long ret = fact[n]; 
  (ret *= inv_fact[k]) %= mod;
  (ret *= inv_fact[n - k]) %= mod;
  return ret; 
}

void dfs(int u, int father) {
  parent[u] = father; 
  sz[u] = 1; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    level[v] = level[u] + 1; 
    dfs(v, u); 
    sz[u] += sz[v]; 
  }
}

void heavyLightDecomposition(int u, int father) {
  if (chainStart[chain] == -1) {
    chainStart[chain] = u;
  }  
  chainIndex[u] = chain; 
  listVertex.push_back(u); 
  position[u] = (int) listVertex.size();               
  int specialVertex = -1; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    if (v == father) {
      continue; 
    }
    if (specialVertex == -1 || sz[specialVertex] < sz[v]) {
      specialVertex = v; 
    }
  }
  if (specialVertex != -1) {
    heavyLightDecomposition(specialVertex, u); 
  }
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    if (v == father) {
      continue; 
    }
    if (v != specialVertex) {
      chain++; 
      heavyLightDecomposition(v, u); 
    }
  }
}

void initLCA() {
  for (int u = 1; u <= n; u++) {
    for (int j = 0; j <= 17; j++) {
      f[u][j] = -1; 
    }
  }
  for (int u = 1; u <= n; u++) {
    f[u][0] = parent[u]; 
  }
  for (int j = 1; j <= 17; j++) {
    for (int u = 1; u <= n; u++) {
      if (f[u][j - 1] != -1) {
        f[u][j] = f[f[u][j - 1]][j - 1]; 
      }
    }
  }
}

int lca(int u, int v) {
  if (level[u] < level[v]) {
    std::swap(u, v); 
  }
  for (int j = 17; j >= 0; j--) {
    if (level[u] - (1 << j) >= level[v]) {
      u = f[u][j]; 
    }
  }
  if (u == v) {
    return u; 
  }
  for (int j = 17; j >= 0; j--) {
    if (f[u][j] != -1 && f[u][j] != f[v][j]) {
      u = f[u][j];
      v = f[v][j]; 
    }
  }
  return f[u][0]; 
}

void updateSegment(int l, int r, std::vector <int> &freq) {
  freq[l]++; 
  freq[r + 1]--; 
}

void update(int u, int ancestor) {
  while (chainIndex[u] != chainIndex[ancestor]) {
    int start = chainStart[chainIndex[u]];
    int l = position[start];
    int r = position[u];
    updateSegment(l, r, freq1);
    updateSegment(l, r, freq2);
    u = start;
    u = parent[u];  
  }
  if (position[ancestor] + 1 <= position[u]) {
    updateSegment(position[ancestor] + 1, position[u], freq1); 
    updateSegment(position[ancestor] + 1, position[u], freq2); 
  }                            
}

int main () {
  std::cin >> n >> m >> k;
  init();
  for (int i = 1; i <= n; i++) {
    chainStart[i] = -1;
  }
  freq1.resize(n + 5, 0); 
  freq2.resize(n + 5, 0);  
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v; 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
  }
  dfs(1, -1); 
  heavyLightDecomposition(1, -1);
  initLCA(); 
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v; 
    int ancestor = lca(u, v); 
    update(u, ancestor);
    update(v, ancestor); 
    updateSegment(position[ancestor], position[ancestor], freq1); 
  }
  long long ans = 0LL;
  for (int i = 1; i <= n; i++) {
    freq1[i] += freq1[i - 1]; 
    freq2[i] += freq2[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    (ans += C(freq1[i], k)) %= mod; 
    ans -= C(freq2[i], k);
    (ans += mod) %= mod;  
  }
  std::cout << ans;                                          
  return 0;    
}              