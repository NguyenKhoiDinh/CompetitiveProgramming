#include <bits/stdc++.h>

using namespace std;
const int inf = 1000000007; 
vector <int> adj[500005];         
int f[500005], height[500005], f_len[500005], parent[500005]; 
int minValue[500005]; 
bool deleted[500005]; 
vector <int> listLeaves[500005]; 
int n; 
void dfs(int u, int father) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    height[v] = height[u] + 1; 
    dfs(v, u); 
    f[u] += f[v] + 1;     
  }
}
void dfs_len(int u, int father) {
  f_len[u] = height[u]; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    parent[v] = u; 
    dfs_len(v, u); 
    f_len[u] = max(f_len[u], f_len[v]); 
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL); 
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n; 
    for (int i = 1; i <= n; i++) {
      f[i] = 0; 
      height[i] = 0;
      minValue[i] = 0;
      f_len[i] = 0;
      deleted[i] = false;  
      listLeaves[i].clear(); 
      parent[i] = -1; 
      adj[i].clear(); 
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v; 
      adj[u].push_back(v);
      adj[v].push_back(u); 
    }
    dfs(1, -1);  
    for (int i = 2; i <= n; i++) {
      if ((int) adj[i].size() == 1) {
        listLeaves[height[i]].push_back(i); 
      }
    }
    dfs_len(1, -1); 
    for (int i = 1; i <= n; i++) {
      minValue[height[i]] += f[i]; 
    } 
    int ans = inf;
    int numbDeleted = 0; 
    for (int h = 1; h <= n; h++) {
      if (listLeaves[h].empty() == true) {
        continue;   
      }  
      ans = min(ans, minValue[h] + numbDeleted);
      for (int i = 0; i < (int) listLeaves[h].size(); i++) {
        int u = listLeaves[h][i];
        while (deleted[u] == false && f_len[u] <= h) {
          numbDeleted++; 
          deleted[u] = true; 
          u = parent[u]; 
        } 
      } 
    }
    cout << ans << endl;        
  }
  return 0; 
}