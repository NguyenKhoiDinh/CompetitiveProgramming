#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
#include <unordered_map> 
struct edge {
  int u, v; 
  bool isDeleted; 
  bool solve; 
};
int n; 
int root[500005]; 
int rank[500005], szComponents[500005]; 
struct element {
  int u, backRoot, v, backRank, backComponents; 
};
std::stack <element> st; 
std::vector <edge> listEdges[500005]; 
std::vector <edge> listQueries; 
std::unordered_map <long long, std::vector <std::pair <int, int> > > range;
long long ans = 0LL; 
int findRoot(int u) {
  return (u == root[u] ? u : findRoot(root[u])); 
}
void update(std::vector <std::vector <std::pair <int, int> > > &it, int index, int L, int R, int l, int r, int u, int v) {
  if (L > r || l > R) {
    return; 
  }
  if (l <= L && R <= r) {
    it[index].push_back(std::make_pair(u, v)); 
    return; 
  }
  int mid = (L + R) / 2; 
  update(it, 2 * index, L, mid, l, r, u, v); 
  update(it, 2 * index + 1, mid + 1, R, l, r, u, v); 
}
void process(const std::vector <std::vector <std::pair <int, int> > > &it, int sizeStack, int index, int L, int R) {
  if (L == R && listQueries[L].solve == true) {
    int u = listQueries[L].u;
    int v = listQueries[L].v;
    int rootu = findRoot(u);
    int rootv = findRoot(v); 
    ans += 1LL * szComponents[rootu] * szComponents[rootv]; 
  }
  for (int i = 0; i < (int) it[index].size(); i++) {
    int u = it[index][i].first; 
    int v = it[index][i].second; 
    int rootu = findRoot(u);
    int rootv = findRoot(v);
    if (rootu != rootv) {
      if (rank[rootu] > rank[rootv]) {
        std::swap(rootu, rootv); 
      }
      st.push((element) {rootu, root[rootu], rootv, rank[rootv], szComponents[rootv]});
      if (rank[rootu] == rank[rootv]) {
        rank[rootv]++; 
      } 
      szComponents[rootv] += szComponents[rootu];
      root[rootu] = rootv;  
    }
  }  
  if (L < R) {
    int mid = (L + R) / 2; 
    process(it, (int) st.size(), 2 * index, L, mid);
    process(it, (int) st.size(), 2 * index + 1, mid + 1, R); 
  }
  while ((int) st.size() > sizeStack) {
    element e = st.top(); 
    st.pop(); 
    root[e.u] = e.backRoot; 
    rank[e.v] = e.backRank; 
    szComponents[e.v] = e.backComponents; 
  }
}

int main () {
  scanf("%d", &n); 
  for (int i = 1; i <= n; i++) {
    root[i] = i; 
    rank[i] = 1; 
    szComponents[i] = 1; 
  }
  for (int i = 1; i < n; i++) {
    int u, v, weight; 
    scanf("%d %d %d", &u, &v, &weight); 
    if (u > v) {
      std::swap(u, v); 
    }
    listEdges[weight].push_back((edge) {u, v, false, false}); 
  }
  for (int w = 1; w <= n; w++) {
    for (int i = 0; i < (int) listEdges[w].size(); i++) {
      edge e = listEdges[w][i];
      listQueries.push_back((edge) {e.u, e.v, false, false}); 
    }
  }
  for (int w = 1; w <= n; w++) {
    for (int i = 0; i < (int) listEdges[w].size(); i++) {
      edge e = listEdges[w][i]; 
      listQueries.push_back((edge) {e.u, e.v, true, false}); 
    }
    for (int i = 0; i < (int) listEdges[w].size(); i++) {
      edge e = listEdges[w][i]; 
      listQueries.push_back((edge) {e.u, e.v, false, true}); 
      listQueries.push_back((edge) {e.u, e.v, true, false}); 
    }
    for (int i = 0; i < (int) listEdges[w].size(); i++) {
      edge e = listEdges[w][i];
      listQueries.push_back((edge) {e.u, e.v, false, false}); 
    }
  }
  int numQueries = (int) listQueries.size(); 
  for (int i = 0; i < numQueries; i++) {
    edge e = listQueries[i]; 
    if (e.isDeleted == false) {
      range[(long long) e.u * 1000000 + e.v].push_back(std::make_pair(i, numQueries - 1)); 
    }
    else {
      range[(long long) e.u * 1000000 + e.v].back().second = i - 1;
    }
  }
  std::vector <std::vector <std::pair <int, int> > > it;
  it.resize(4 * numQueries + 5); 
  for (std::unordered_map <long long, std::vector <std::pair <int, int> > >::iterator iter = range.begin(); iter != range.end(); iter++) {
    long long key = iter->first; 
    int u = key / 1000000; 
    int v = key % 1000000; 
    std::vector <std::pair <int, int> > b = iter->second; 
    for (int i = 0; i < (int) b.size(); i++) {
      int l = b[i].first;
      int r = b[i].second;
      update(it, 1, 0, numQueries - 1, l, r, u, v);   
    }
  }
  process(it, 0, 1, 0, numQueries - 1);
  std::cout << ans;  
  return 0; 
}