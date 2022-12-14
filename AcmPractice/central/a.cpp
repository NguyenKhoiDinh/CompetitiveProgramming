#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 205; 
const int inf = 1000000007; 
int cost[MAX_N][MAX_N];
int n, numTest;
int root[MAX_N];
int F[MAX_N][MAX_N];
int ans[MAX_N][MAX_N];  
int parent[MAX_N]; 
int minValue[MAX_N]; 
vector <int> adj[MAX_N]; 
struct edge {
  int u, v, weight; 
  bool operator < (const edge &other) {
    return weight > other.weight; 
  }
};
vector <edge> listEdge; 

int findRoot(int u) {
  return root[u] = (u == root[u] ? root[u] : findRoot(root[u])); 
}

void unionSet(int u, int v, int weight) {
  int rootu = findRoot(u);
  int rootv = findRoot(v);
  if (rootu != rootv) {
    root[rootu] = rootv; 
    ans[u][v] = ans[v][u] = weight;
    adj[u].push_back(v);
    adj[v].push_back(u); 
  }
}

void dfs(int u, int father) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    minValue[v] = min(minValue[v], min(minValue[u], cost[u][v])); 
    dfs(v, u); 
  }
}

int main () {
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
      root[i] = i; 
      adj[i].clear(); 
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> cost[i][j];
        F[i][j] = inf;
        ans[i][j] = 0;  
      }
    }
    listEdge.clear(); 
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        listEdge.push_back((edge) {i, j, cost[i][j]});   
      }
    }
    sort(listEdge.begin(), listEdge.end());
    for (int i = 0; i < (int) listEdge.size(); i++) {
      int u = listEdge[i].u;
      int v = listEdge[i].v;
      int weight = listEdge[i].weight;
      unionSet(u, v, weight);  
    } 
    bool found = true; 
    for (int u = 1; u <= n; u++) {
      for (int v = 1; v <= n; v++) {
        minValue[v] = inf;
      }
      dfs(u, -1);
      for (int v = 1; v <= n; v++) {
        if (v != u && cost[u][v] != minValue[v]) {
          found = false; 
        }
      } 
    }
    if (found == false) {
      cout << "NO" << endl; 
    }
    else {
      cout << "YES" << endl; 
      for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
          cout << ans[u][v] << ' '; 
        }
        cout << endl; 
      }
    }
  }
  return 0; 
}