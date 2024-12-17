#include <bits/stdc++.h>

using namespace std;
vector <int> listPaths[200005];
vector <int> adj[200005];
int parent[200005];
int height[200005];
int numbEdges[200005];        
int n;
long long w;  
void dfs(int u, int father) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    height[v] = height[u] + 1; 
    dfs(v, u); 
  }  
}
void solve(int u, int v, int p) {
  if (height[u] < height[v]) {
    swap(u, v); 
  }
  while (height[u] > height[v]) {
    listPaths[u].push_back(p); 
    numbEdges[p]++;
    u = parent[u]; 
  }
  while (u != v) {
    listPaths[u].push_back(p);
    listPaths[v].push_back(p); 
    numbEdges[p] += 2; 
    u = parent[u];
    v = parent[v]; 
  }
}

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
      listPaths[i].clear(); 
      adj[i].clear();
      numbEdges[i] = 0;   
    }
    for (int i = 2; i <= n; i++) {
      cin >> parent[i]; 
      adj[parent[i]].push_back(i);
      adj[i].push_back(parent[i]); 
    }    
    dfs(1, -1);
    int confirmed = 0;
    for (int i = 1; i <= n; i++) {
      solve(i, i % n + 1, i); 
    } 
    long long rest = 0LL; 
    long long lim = w; 
    for (int i = 1; i < n; i++) {
      int x;
      long long value;
      cin >> x >> value;
      lim -= value;
      for (int j = 0; j < (int) listPaths[x].size(); j++) {
        int v = listPaths[x][j];
        numbEdges[v]--;
        rest += value; 
        if (numbEdges[v] == 0) {
          confirmed++; 
        } 
      }
      cout << lim * (n - confirmed) + rest << ' ';   
    }
    cout << endl;
  }
  return 0; 
}