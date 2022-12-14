#include <iostream>  
#include <vector> 
#include <stack>
#include <math.h> 
#include <set>
int numTest; 
std::vector <int> adj[100005];  
int n, m, k, timeDfs = 0; 
bool deleted[100005]; 
std::stack <int> mystack; 
int low[100005], num[100005], root[100005]; 
int curVertex = 0;
std::set <int> listVertex[100005];
std::vector <int> adj_root[100005]; 
bool visited[100005]; 
int sz[100005]; 

void init() {
  for (int i = 1; i <= n; i++) {
    deleted[i] = false;
    low[i] = 0; 
    num[i] = 0;
    sz[i] = 0;
    adj[i].clear();
    adj_root[i].clear(); 
    listVertex[i].clear(); 
    visited[i] = false; 
  }
  while (!mystack.empty()) {
    mystack.pop(); 
  }
  timeDfs = 0; 
  curVertex = 0;
}

void dfs(int u) {
  mystack.push(u); 
  num[u] = low[u] = ++timeDfs;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (deleted[v] == true) {
      continue; 
    }
    if (num[v] == 0) {
      dfs(v); 
      low[u] = std::min(low[u], low[v]); 
    }
    else {
      low[u] = std::min(low[u], num[v]); 
    }
  }
  if (low[u] == num[u]) {
    curVertex++; 
    do {
      int v = mystack.top();                             
      mystack.pop();      
      deleted[v] = true;
      root[v] = curVertex;
      listVertex[curVertex].insert(v); 
      if (v == u) {
        break; 
      } 
    }
    while (true);
  }
}

void dfs1(int u) {
  if ((int) listVertex[u].size() > k) {
    return; 
  }
  for (int i = 0; i < (int) adj_root[u].size(); i++) {
    int v = adj_root[u][i];
    dfs1(v);
    for (std::set <int>::iterator it = listVertex[v].begin(); it != listVertex[v].end(); it++) {
      if ((int) listVertex[u].size() > k) {
        break; 
      }
      int vertex = *it;
      listVertex[u].insert(vertex); 
    }
  }
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> n >> m >> k; 
    init();
    for (int i = 1; i <= m; i++) {
      int u, v; 
      std::cin >> u >> v;
      adj[u].push_back(v); 
    } 
    for (int i = 1; i <= n; i++) {
      if (num[i] == 0) {
        dfs(i); 
      }                                
    }
    for (int u = 1; u <= n; u++) {
      for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i]; 
        int rootu = root[u];
        int rootv = root[v]; 
        if (rootu != rootv) {
          adj_root[rootv].push_back(rootu); 
        }
      }
    }
    n = curVertex;
    for (int i = 1; i <= n; i++) {
      sz[i] = (int) listVertex[i].size();
    }
    for (int i = 1; i <= n; i++) {
      dfs1(i);
    }
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
      if ((int) listVertex[i].size() > k) {
        ans += sz[i];
      }  
    }
    std::cout << ans << std::endl;
  }                       
  return 0; 
}          