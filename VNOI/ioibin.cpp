#include <bits/stdc++.h>

using namespace std;
int root[10005]; 

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

int main () {
  for (int i = 1; i <= 10000; i++) {
    root[i] = i;
  }
  int numQuery;
  cin >> numQuery;
  for (int i = 1; i <= numQuery; i++) {
    int u, v, type;
    cin >> u >> v >> type; 
    if (type == 1) {
      unionSet(u, v); 
    }
    else {
      int rootu = findRoot(u);
      int rootv = findRoot(v);
      cout << (rootu == rootv) << endl;
    }
  }
  return 0; 
}