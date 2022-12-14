#include <bits/stdc++.h> 

using namespace std;
int deg[100005]; 
int n; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    deg[u]++;
    deg[v]++; 
  }
  for (int u = 1; u <= n; u++) {
    if (deg[u] == n - 1) {
      cout << "Yes";
      return 0; 
    }
  }
  cout << "No";
  return 0; 
}