#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 200005;
vector <int> adj[MAX_N];
int n;

int main () {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if ((int) adj[i].size() == 1) {
      ans++;
    }
  }
  cout << (ans + 1) / 2;
  return 0;
}