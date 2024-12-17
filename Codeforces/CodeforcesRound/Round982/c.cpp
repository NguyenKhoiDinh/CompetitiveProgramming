#include <bits/stdc++.h>

using namespace std;
bool visited[300005]; 
int n; 
long long a[300005]; 
map <long long, vector <int> > listVertex; 
void dfs(int u, long long value) {
  visited[u] = true; 
  value += u - 1; 
  if (listVertex.find(value) == listVertex.end()) {
    return; 
  }
  vector <int> &v = listVertex[value];
  for (int i = 0; i < (int) v.size(); i++) {
    if (visited[v[i]] == false) {
      dfs(v[i], value); 
    }
  }
  v.clear();  
} 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
      a[i] += i - 1; 
    }    
    for (int i = 1; i <= n; i++) {
      visited[i] = false; 
    }
    listVertex.clear(); 
    for (int i = 1; i <= n; i++) {
      listVertex[a[i]].push_back(i); 
    }
    if (listVertex.find(n) == listVertex.end()) {
      cout << n << endl;
      continue; 
    }
    vector <int> &v = listVertex[n]; 
    for (int i = 0; i < (int) v.size(); i++) {
      int u = v[i]; 
      if (visited[u] == false) {
        dfs(u, n); 
      }
    }
    v.clear();
    long long ans = n; 
    for (int u = 1; u <= n; u++) {
      if (visited[u] == true) {
        ans = max(ans, a[u] + u - 1);
      }
    }
    cout << ans << endl;
  }
  return 0; 
}