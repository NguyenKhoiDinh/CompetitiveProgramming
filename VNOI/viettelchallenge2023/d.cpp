#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <utility>
struct edge {
  int u, v;
  double weight; 
  bool operator < (const edge &other) const {
    return weight < other.weight; 
  }
};
struct point {
  double x, y; 
};
int n; 
point a[155]; 
double w, c; 
std::vector <edge> listEdges; 
double ans; 
int root[155]; 
int sz[155]; 
int findRoot(int u) {
  return root[u] = (u == root[u] ? u : findRoot(root[u])); 
}

double dist(const point &a, const point &b) {
  double ret = std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); 
  return ret; 
}

int main () {
  std::cin >> n; 
  for (int i = 1; i <= n; i++) {
    root[i] = i;
    sz[i] = 1; 
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].x >> a[i].y; 
  }
  std::cin >> w >> c; 
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      listEdges.push_back((edge) {i, j, c * dist(a[i], a[j])}); 
    }
  }
  std::sort(listEdges.begin(), listEdges.end()); 
  ans = w * n;                  
  for (int i = 0; i < (int) listEdges.size(); i++) {
    edge e = listEdges[i]; 
    int u = e.u;
    int v = e.v; 
    int rootu = findRoot(u);
    int rootv = findRoot(v);
    if (rootu != rootv && e.weight < w) {
      root[rootu] = rootv;
      sz[rootv] += sz[rootu]; 
      ans -= w;
      ans += e.weight;    
    }
  }
  int rootu = findRoot(1);
  if (sz[rootu] == n) {
    ans -= w; 
  }
  std::cout << std::fixed << std::setprecision(15) << ans; 
  return 0; 
}