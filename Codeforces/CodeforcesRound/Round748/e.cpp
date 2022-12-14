#include <bits/stdc++.h> 

using namespace std;
int numTest;
vector <int> adj[400005]; 
int n, k;
int dist[400005];
int dp[400005];  
int parent[400005];
vector <int> child[400005]; 

void dfs(int u, int father) {
  parent[u] = father; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue;
    }
    dist[v] = dist[u] + 1;
    dfs(v, u); 
  }
}

void dfs1(int u, int father) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue;
    }
    child[u].push_back(v); 
    dfs1(v, u);
    dp[u] = max(dp[u], dp[v] + 1); 
  }
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      dist[i] = -1; 
      dp[i] = 0;
      child[i].clear(); 
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    if (n <= 2) {
      cout << 0 << endl;
      continue; 
    }
    dist[1] = 0;
    dfs(1, -1); 
    int maxi = -1;
    int choose = -1;  
    for (int u = 1; u <= n; u++) {
      if (maxi < dist[u]) {
        maxi = dist[u];
        choose = u; 
      }  
    }
    dist[choose] = 0; 
    dfs(choose, -1);
    maxi = -1;
    choose = -1;
    for (int i = 1; i <= n; i++) {
      if (maxi < dist[i]) {
        maxi = dist[i];
        choose = i; 
      }
    }
    vector <int> listVertex;
    while (true) {
      listVertex.push_back(choose);
      choose = parent[choose]; 
      if (choose == -1) {
        break; 
      }
    }   
    int sz = (int) listVertex.size();
    choose = listVertex[sz / 2]; 
    dfs1(choose, -1);
    int maxiDp = -1; 
    int deg = (int) child[choose].size();  
    for (int i = 0; i < (int) child[choose].size(); i++) {
      int v = child[choose][i];
      maxiDp = max(maxiDp, dp[v]); 
    }
    int maxDp2 = -1; 
    for (int i = 0; i < (int) child[choose].size(); i++) {
      int v = child[choose][i];
      if (dp[v] != maxiDp && dp[v] < k) {
        deg--;
        maxDp2 = max(maxDp2, dp[v] + 1);  
      }
    }
    int ans = 0;
    if (dp[choose] < k) {
      cout << 0 << endl;
      continue;   
    }
    if (deg > 1) {
      queue <int> myqueue;
      myqueue.push(choose);
      while (!myqueue.empty()) {
        int u = myqueue.front();
        myqueue.pop();
        if (dp[u] < k) {
          continue; 
        }
        ans++; 
        for (int i = 0; i < (int) child[u].size(); i++) {
          int v = child[u][i];
          myqueue.push(v); 
        }
      }
    }
    else if (deg == 1) {
      k -= maxDp2; 
      if (k >= 1) {
        ans = 0;  
      }  
      else {
        ans = 2;
      }
    }
    else {
      ans = 1; 
    }
    cout << ans << endl; 
  }
  return 0; 
}