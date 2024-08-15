#include <bits/stdc++.h>

using namespace std;
vector <int> adj[200005]; 
int n; 
long long f[200005]; 
void dfs(int u, int father) {
  long long mini = 10000000000000007LL; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs(v, u);
    mini = min(mini, f[v]);  
  }
  if (f[u] >= mini) {
    if (u != 1) {
      f[u] = mini;
    }  
    else if (mini != 10000000000000007LL)  {
      f[u] += mini; 
    }
  }
  else if (mini != 10000000000000007LL) {
    long long more = (mini - f[u]) / 2;
    if (u == 1) {
      f[u] += mini; 
    }  
    else {
      f[u] += more;
    }
  }
} 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      adj[i].clear(); 
      cin >> f[i]; 
    }
    for (int i = 2; i <= n; i++) {
      int father;
      cin >> father; 
      adj[father].push_back(i);
      adj[i].push_back(father); 
    }
    dfs(1, -1); 
    cout << f[1] << endl;
  }
  return 0; 
}