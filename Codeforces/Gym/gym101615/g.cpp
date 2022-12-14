#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX_N = 1005;
struct segment {
  int l, r;
};
struct element {
  int v, l, r;
};
bool visited[MAX_N];
vector <element> adj[MAX_N];
int n, m, k;
int start, final;
vector <int> save;
vector <segment> listSegment;

void DFS(int u, int key) {
  visited[u] = true;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    element e = adj[u][i];
    if (e.l <= key && key <= e.r && visited[e.v] == false) {
      DFS(e.v, key);
    }
  }
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n >> m >> k;
  cin >> start >> final;
  save.push_back(0);
  save.push_back(k);
  for (int i = 1; i <= m; i++) {
    int u, v, l, r;
    cin >> u >> v >> l >> r;
    adj[u].push_back((element) {v, l, r});
    save.push_back(l - 1);
    save.push_back(r);
  }
  sort(save.begin(), save.end());
  for (int i = 1; i < (int) save.size(); i++) {
    if (save[i] != save[i - 1]) {
      listSegment.push_back((segment) {save[i - 1] + 1, save[i]});
    }
  }
  int ans = 0;
  for (int i = 0; i < (int) listSegment.size(); i++) {
    memset(visited, false, sizeof(visited));
    DFS(start, listSegment[i].l);
    if (visited[final] == true) {
      ans += listSegment[i].r - listSegment[i].l + 1;
    }
  }
  cout << ans;
  return 0;
}