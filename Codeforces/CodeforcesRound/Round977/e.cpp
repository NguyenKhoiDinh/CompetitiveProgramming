#include <bits/stdc++.h>

using namespace std;
int n, m, p; 
int sizeComponents[200005]; 
int root[200005]; 
long long latency[200005];
long long ans[200005];  
int findRoot(int u) {
  return root[u] = (u == root[u] ? u : findRoot(root[u])); 
}
struct edge {
  int u, v, w; 
  bool operator < (const edge &other) {
    return w < other.w; 
  }
};
vector <edge> listEdges; 
int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
      root[i] = i;  
      sizeComponents[i] = 0; 
      ans[i] = 0LL; 
      latency[i] = 0LL; 
    }
    listEdges.clear();
    for (int i = 1; i <= p; i++) {
      int u;
      cin >> u;
      sizeComponents[u] = 1; 
    } 
    for (int i = 1; i <= m; i++) {
      int u, v, w;                                                                         
      cin >> u >> v >> w; 
      listEdges.push_back((edge) {u, v, w}); 
    }                   
    sort(listEdges.begin(), listEdges.end());
    vector <long long> diff; 
    long long totalLatency = 0LL; 
    for (int i = 0; i < m; i++) {
      int u = listEdges[i].u; 
      int v = listEdges[i].v;   
      int w = listEdges[i].w;
      int rootu = findRoot(u);
      int rootv = findRoot(v);
      if (rootu != rootv) {
        root[rootu] = rootv; 
        if (sizeComponents[rootu] > 0 && sizeComponents[rootv] > 0) {
          long long connectLatency = min(latency[rootu] + 1LL * sizeComponents[rootv] * w, latency[rootv] + 1LL * sizeComponents[rootu] * w); 
          diff.push_back(latency[rootu] + latency[rootv] - connectLatency);
          latency[rootv] = connectLatency;  
          sizeComponents[rootv] += sizeComponents[rootu]; 
        }
        else {
          sizeComponents[rootv] += sizeComponents[rootu];
          latency[rootv] = max(latency[rootv], latency[rootu]); 
        }
      }  
    }
    int finalRoot = findRoot(1);
    long long ret = latency[finalRoot];
    ans[1] = ret;
    sort(diff.begin(), diff.end()); 
    for (int i = 2; i <= p; i++) {
      ret += diff[i - 2]; 
      ans[i] = ret; 
    }                                                      
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << ' '; 
    }
    cout << endl; 
  }
  return 0; 
}