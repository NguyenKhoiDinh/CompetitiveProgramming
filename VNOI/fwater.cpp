#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 305; 
int cost[MAX_N][MAX_N];
int n; 
int w[MAX_N];
struct edge {
  int u, v, w; 
  bool operator < (const edge &other) {
    return w < other.w; 
  }
};
vector <edge> listEdge;
int root[MAX_N];

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
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> w[i]; 
    listEdge.push_back((edge) {0, i, w[i]});
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> cost[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      listEdge.push_back((edge) {i, j, cost[i][j]});
    }
  }
  sort(listEdge.begin(), listEdge.end());
  for (int i = 0; i <= n; i++) {
    root[i] = i;
  }
  int ans = 0; 
  for (int i = 0; i < (int) listEdge.size(); i++) {
    int u = listEdge[i].u;
    int v = listEdge[i].v; 
    int w = listEdge[i].w;
    if (findRoot(u) != findRoot(v)) {
      ans += w;
      unionSet(u, v);
    }
  }
  cout << ans;
  return 0; 
} 