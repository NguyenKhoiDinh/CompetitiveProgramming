#include <bits/stdc++.h> 

using namespace std;
int numTest;
vector <int> adj[200005]; 
int n, k; 
bool isFriend[200005]; 
bool found = false;
int dp[200005];    
 
void dfs(int u, int father) {
  if (isFriend[u] == true) {
    dp[u] = 0;
    return;
  }
  int mini = 100000006; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs(v, u);
    if (dp[v] != -1) {
      mini = min(mini, dp[v] + 1);  
    } 
  }
  if (mini != 100000006) {
    dp[u] = mini;
  }
}

void findLeaf(int u, int father, int depth) {
  if ((int) adj[u].size() == 1 && u != 1) {
    found = true; 
  }
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    if (dp[v] == -1 || dp[v] > depth + 1) {
      findLeaf(v, u, depth + 1); 
    }
  }
}

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k;
    found = false; 
    for (int i = 1; i <= n; i++) {
      isFriend[i] = false;
      adj[i].clear(); 
      dp[i] = -1; 
    }
    for (int i = 1; i <= k; i++) {
      int x;
      cin >> x;
      isFriend[x] = true; 
    }  
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u); 
    }
    dfs(1, -1); 
    findLeaf(1, -1, 0);
    cout << (found == true ? "YES" : "NO") << endl;  
  }
  return 0; 
}