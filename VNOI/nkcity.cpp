#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1005; 
int n, m; 
int root[MAX_N];
struct edge {
  int u, v, w; 
  bool operator < (const edge &other) {
    return w < other.w; 
  }
};

void init() {
  for (int i = 1; i <= n; i++) {
    root[i] = i;
  }
}

int findRoot(int u) {
  return (root[u] = (root[u] == u ? u : findRoot(root[u])));
}

void unionSet(int u, int v) {
  int rootu = findRoot(u);
  int rootv = findRoot(v); 
  if (rootu != rootv) {
    root[rootu] = rootv;
  }
}
vector <edge> save; 

int main () {
  cin >> n >> m;
  init();
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    save.push_back((edge) {u, v, w});
  }
  sort(save.begin(), save.end());
  int res = -1; 
  for (int i = 0; i < m; i++) {
    int u = save[i].u;
    int v = save[i].v;
    int w = save[i].w;
    int rootu = findRoot(u);
    int rootv = findRoot(v);
    if (rootu != rootv) {
      res = w;
      unionSet(u, v);
    }
  }
  cout << res;
  return 0; 
}