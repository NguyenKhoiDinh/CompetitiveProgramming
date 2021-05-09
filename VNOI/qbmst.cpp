#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 10005; 
struct edge {
  int u, v, w; 
  bool operator < (const edge &other) {
    return w < other.w;
  }
};
int root[MAX_N];
int n, m; 
vector <edge> listEdge; 

int findRoot(int u) {
  return root[u] = (u == root[u] ? u : findRoot(root[u]));
}

void unionSet(int u, int v) {
  int rootu = findRoot(u);
  int rootv = findRoot(v);
  if (rootu != rootv) {
    root[rootu] = rootv;
  }
}

int main () {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    root[i] = i; 
  }
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w; 
    listEdge.push_back((edge) {u, v, w});
  }
  sort(listEdge.begin(), listEdge.end());
  int ans = 0; 
  for (int i = 0; i < m; i++) {
    int u = listEdge[i].u; 
    int v = listEdge[i].v; 
    int w = listEdge[i].w;
    int rootu = findRoot(u);
    int rootv = findRoot(v);
    if (rootu != rootv) {
      ans += w;
      unionSet(u, v);
    }
  }
  cout << ans;
  return 0; 
}