#include <bits/stdc++.h> 

using namespace std; 
vector <int> adj[55]; 
int root[55]; 
int cnt[55]; 
int needAdd = 0; 
int n, m, k; 
vector <pair <int, int> > listEdge;
vector <pair <int, int> > addEdge; 
vector <vector <int> > answer; 
bool visited[55]; 
int trace[55]; 
bool mark[55][55];
bool ok[55];  
priority_queue <pair <int, int> > listComponent; 

int findRoot(int u) {
  return root[u] = (u == root[u] ? u : findRoot(root[u])); 
}

void dfs(int start, int end) {
  visited[start] = true; 
  for (int i = 0; i < (int) adj[start].size(); i++) {
    int u = adj[start][i]; 
    if (visited[u] == false) {
      trace[u] = start;  
      dfs(u, end); 
    }
  }
}

vector <int> findPath(int start, int end) {
  for (int i = 1; i <= n; i++) {
    visited[i] = false; 
    trace[i] = 0; 
  }                     
  dfs(start, end);
  vector <int> res;
  int u = end;
  do {
    res.push_back(u); 
    u = trace[u];     
  }
  while (u != 0); 
  return res; 
}

void dfs1(int u, vector <int> &save) {
  visited[u] = true; 
  save.push_back(u); 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == false) {
      dfs1(v, save); 
    }  
  }
}

void process(int u) {
  for (int i = 1; i <= n; i++) {
    visited[i] = false;
  }
  vector <int> save;
  dfs1(u, save);
  if ((int) save.size() <= 2) {
    return;
  }
  for (int i = 0; i < (int) save.size(); i++) {
    for (int j = i + 1; j < (int) save.size(); j++) {
      int x = save[i];
      int y = save[j]; 
      if (mark[x][y] == true) {
        continue; 
      }
      if (needAdd < k) {
        vector <int> path = findPath(x, y); 
        if ((int) path.size() <= 2) {
          continue; 
        }
        needAdd++; 
        mark[x][y] = true; 
        mark[y][x] = true; 
        answer.push_back(path);
        addEdge.push_back(make_pair(x, y));  
      }
    }
  }  
}

int main () {
  cin >> n >> m >> k; 
  for (int i = 1; i <= n; i++) {
    root[i] = i; 
    cnt[i] = 1; 
  }
  for (int j = 1; j <= m; j++) {
    int u, v;
    cin >> u >> v;
    mark[u][v] = true; 
    mark[v][u] = true; 
    int rootu = findRoot(u);
    int rootv = findRoot(v);
    if (rootu != rootv) {
      root[rootu] = rootv; 
      cnt[rootv] += cnt[rootu]; 
      adj[u].push_back(v); 
      adj[v].push_back(u); 
    }
    else {
      // save edges not in spanning tree
      listEdge.push_back(make_pair(u, v)); 
    }  
  }
  while (!listEdge.empty()) {
    if (needAdd == k) {
      break; 
    }
    pair <int, int> edge = listEdge.back(); 
    listEdge.pop_back(); 
    int u = edge.first; 
    int v = edge.second;
    vector <int> path = findPath(u, v);
    if ((int) path.size() <= 2) {
      continue; 
    } 
    answer.push_back(path); 
    needAdd++; 
  }
  if (needAdd < k) {
    for (int u = 1; u <= n; u++) {
      int rootu = findRoot(u); 
      if (ok[rootu] == false) {
        ok[rootu] = true;      
        listComponent.push(make_pair(cnt[rootu], rootu));
        process(rootu); 
      }
    }
  }
  if (needAdd < k) {                     
    while ((int) listComponent.size() > 1) {
      pair <int, int> pr1 = listComponent.top(); 
      listComponent.pop(); 
      pair <int, int> pr2 = listComponent.top(); 
      listComponent.pop(); 
      int u = pr1.second; 
      int v = pr2.second; 
      root[u] = v; 
      cnt[v] += cnt[u];
      adj[u].push_back(v);
      adj[v].push_back(u);
      addEdge.push_back(make_pair(u, v)); 
      mark[u][v] = true; 
      mark[v][u] = true; 
      process(u); 
      if (needAdd == k) {
        break; 
      }
      listComponent.push(make_pair(cnt[v], v)); 
    }
  } 
  if (needAdd < k) {
    cout << "NO"; 
  }
  else {
    cout << "YES" << endl; 
    cout << (int) addEdge.size() << endl; 
    for (int i = 0; i < (int) addEdge.size(); i++) {
      cout << addEdge[i].first << ' ' << addEdge[i].second << endl; 
    }
    for (int i = 0; i < (int) answer.size(); i++) {
      vector <int> path = answer[i];
      cout << (int) path.size() << ' '; 
      for (int j = 0; j < (int) path.size(); j++) {
        cout << path[j] << ' '; 
      }
      cout << endl; 
    }
  }
  return 0; 
}