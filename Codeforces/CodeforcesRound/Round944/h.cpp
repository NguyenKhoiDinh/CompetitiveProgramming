#include <iostream>
#include <vector>
#include <math.h> 
#include <stack>
int numTest; 
const int SHIFT = 500; 
std::vector <int> adj[2 * SHIFT + 2];
std::vector <int> adj_root[2 * SHIFT + 2];
bool visited[2 * SHIFT + 2];  
int low[2 * SHIFT + 2];
int numb[2 * SHIFT + 2];
bool deleted[2 * SHIFT + 2];
bool state[2 * SHIFT + 2];  
int a[3][505];  
int n; 
int timeDfs = 0; 
std::stack <int> store;  
int root[2 * SHIFT + 2];                      
void addEdge(int u, int v) {
  adj[SHIFT - v].push_back(SHIFT + u);
  adj[SHIFT - u].push_back(SHIFT + v); 
}
void dfs(int u) {
  timeDfs++; 
  low[u] = numb[u] = timeDfs;
  store.push(u);  
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    if (deleted[v] == true) {
      continue; 
    }
    if (numb[v] == 0) {
      dfs(v);
      low[u] = std::min(low[u], low[v]);  
    }
    else {
      low[u] = std::min(low[u], numb[v]); 
    }
  }
  if (low[u] == numb[u]) {
    while (true) {
      int v = store.top(); 
      store.pop(); 
      deleted[v] = true;
      root[v] = u;
      if (v == u) {
        break; 
      } 
    }  
  }
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < n; j++) {
        std::cin >> a[i][j]; 
      }
    }
    for (int i = SHIFT - n; i <= SHIFT + n; i++) {
      adj[i].clear(); 
      adj_root[i].clear(); 
      visited[i] = false;
      low[i] = 0;
      numb[i] = 0;
      deleted[i] = false;     
    }
    for (int j = 0; j < n; j++) {
      addEdge(a[0][j], a[1][j]);
      addEdge(a[1][j], a[2][j]);
      addEdge(a[2][j], a[0][j]); 
    }
    timeDfs = 0; 
    for (int i = SHIFT - n; i <= SHIFT + n; i++) {
      if (numb[i] == 0) {
        dfs(i); 
      }
    }
    bool ok = true; 
    for (int i = 1; i <= n; i++) {
      if (root[SHIFT - i] == root[SHIFT + i]) {
        ok = false;
        break; 
      }
    }
    std::cout << (ok == true ? "YES" : "NO") << std::endl; 
  }
  return 0; 
}