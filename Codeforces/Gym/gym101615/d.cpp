#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <fstream>

using namespace std;
const int MAX_N = 50005;
vector <pair <int, int> > adj[MAX_N];
int in[MAX_N], out[MAX_N], seg[MAX_N];
int n, dfsCount = 0;
map <int, int> countColor[MAX_N];

void DFS(int u, int father) {
  dfsCount++;
  in[u] = dfsCount;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    pair <int, int> neighbor = adj[u][i];
    int v = neighbor.first;
    int color = neighbor.second;
    countColor[u][color]++;
    if (v == father) {
      continue;
    }
    DFS(v, u);
  }
  out[u] = dfsCount;
}

void update(int l, int r) {
  seg[l]++;
  seg[r + 1]--;
}

void DFS2(int u, int father, int color) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    pair <int, int> neighbor = adj[u][i];
    int v = neighbor.first;
    if (v == father) {
      continue;
    }
    int nextColor = neighbor.second;
    DFS2(v, u, nextColor);
    if (nextColor == color) {
      update(1, in[u] - 1);
      update(out[u] + 1, n);
      update(in[v], out[v]);
    }
    if (countColor[u][nextColor] >= 2) {
      update(in[v], out[v]);
    }
  }
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, color;
    cin >> u >> v >> color;
    adj[u].push_back(make_pair(v, color));
    adj[v].push_back(make_pair(u, color));
  }
  DFS(1, -1);
  DFS2(1, -1, -1);
  for (int i = 2; i <= n; i++) {
    seg[i] += seg[i - 1];
  }
  vector <int> ans;
  for (int i = 1; i <= n; i++) {
    if (seg[in[i]] == 0) {
      ans.push_back(i);
    }
  }
  cout << (int) ans.size() << endl;
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}