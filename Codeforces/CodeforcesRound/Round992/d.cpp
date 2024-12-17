#include <bits/stdc++.h>

using namespace std;
vector <int> adj[200005]; 
int n;          
int ans[200005];
int sz[200005]; 
set <int> odd, even;
void dfs_sz(int u, int father) {
  sz[u] = 1; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    sz[u] += sz[v]; 
  }           
}
int findCentroid(int u, int father) {
  int numbChildren = sz[u];
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }  
    if (sz[v] * 2 > numbChildren) {
      return findCentroid(v, u); 
    }
  }
  return u;    
} 
void dfs(int u, bool isOdd) { 
  set <int> &myset = (isOdd == true ? odd : even);
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    if (ans[v] != -1) {
      continue; 
    }
    set <int>::iterator itBig = myset.end(); 
    itBig--;
    set <int>::iterator itSmall = myset.begin();  
    int largeValue = *itBig; 
    int smallValue = *itSmall;
    int value = largeValue;
    if (abs(ans[u] - value) < abs(ans[u] - smallValue)) {
      value = smallValue; 
    } 
    ans[v] = value; 
    myset.erase(myset.find(value));
    dfs(v, isOdd);  
  } 
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      sz[i] = 1;
      ans[i] = -1; 
      adj[i].clear();
    }
    odd.clear();
    even.clear(); 
    for (int i = 3; i <= 2 * n; i += 2) {
      odd.insert(i); 
    }
    for (int i = 4; i <= 2 * n; i += 2) {
      even.insert(i); 
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);   
    }
    dfs_sz(1, -1);    
    int centroid = findCentroid(1, -1);
    ans[centroid] = 1;
    ans[adj[centroid][0]] = 2;
    dfs(centroid, true);
    dfs(adj[centroid][0], false);
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << ' '; 
    }    
    cout << endl; 
  }
  return 0; 
}