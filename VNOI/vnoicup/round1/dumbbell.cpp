#include <iostream> 
#include <vector> 
#include <bitset>
#include <math.h> 
#include <utility> 
int n, m; 
std::vector <int> adj[100005]; 
std::bitset <100005> dp[2]; 
int dp_size[100005]; 
int low[100005], numb[100005]; 
bool visited[100005]; 
int timeDfs = 0, curVertex = 0; 
std::vector <int> listSubcomponent[100005]; 
std::vector <int> listVertex; 

void dfs(int u, int father) {
  visited[u] = true; 
  dp_size[u] = 1; 
  low[u] = numb[u] = ++timeDfs; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    if (visited[v] == false) {
      dfs(v, u); 
      low[u] = std::min(low[u], low[v]); 
      dp_size[u] += dp_size[v]; 
      if (low[v] == numb[v]) {
        listSubcomponent[curVertex].push_back(dp_size[v]); 
      }
    }
    else {
      low[u] = std::min(low[u], numb[v]); 
    }
  }
}

long long completeGraph(int n) {
  long long ret = (long long) n; 
  ret *= (ret - 1);
  ret /= 2;
  return ret;  
}

int main () {
  std::cin >> n >> m; 
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v; 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
  }
  for (int i = 1; i <= n; i++) {
    if (visited[i] == false) {
      curVertex = i; 
      dfs(i, -1); 
      listVertex.push_back(curVertex); 
    }
  }
  int numVertex = (int) listVertex.size(); 
  dp[0][0] = 1; 
  for (int i = 0; i < numVertex; i++) {
    int v = listVertex[i]; 
    dp[1] |= dp[1] << dp_size[v];
    for (int j = 0; j < (int) listSubcomponent[v].size(); j++) {
      int szComponent = listSubcomponent[v][j]; 
      dp[1] |= dp[0] << szComponent; 
      dp[1] |= dp[0] << (dp_size[v] - szComponent); 
    }    
    dp[0] |= dp[0] << dp_size[v]; 
  }
  long long ans = 1000000000000007LL; 
  for (int szComponent = 1; szComponent < n; szComponent++) {
    if (dp[0][szComponent] == 1 || dp[1][szComponent] == 1) {
      ans = std::min(ans, 1 + completeGraph(szComponent) + completeGraph(n - szComponent) - m); 
    }
  }
  std::cout << (ans == 1000000000000007LL ? -1 : ans); 
  return 0; 
}