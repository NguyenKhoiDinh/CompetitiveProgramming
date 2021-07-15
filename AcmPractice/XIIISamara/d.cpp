#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 200005;
vector <pair <int, char> > adj[MAX_N];
int n, m;
int dist[MAX_N];
int trace[MAX_N];
string path = "";
vector <int> ans;

bool compare(pair <pair <int, char>, int> &a, pair <pair <int, char>, int> &b) {
  return a.first.second < b.first.second;
}

void bfs() {
  queue <int> myqueue;
  myqueue.push(n);
  dist[n] = 0;
  while (!myqueue.empty()) {
    int u = myqueue.front();
    myqueue.pop();
    for (int i = 0; i < (int) adj[u].size(); i++) {
      pair <int, char> neighbor = adj[u][i];
      int v = neighbor.first;
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        myqueue.push(v);
      }
    }
  }
}

int main () {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    dist[i] = -1;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    char c;
    scanf("%d %d %c", &u, &v, &c);
    adj[u].push_back(make_pair(v, c));
    adj[v].push_back(make_pair(u, c));
  }
  bfs();
  vector <int> save;
  save.push_back(1);
  for (int i = 1; i <= dist[1]; i++) {
    int minChar = 'z' + 5;
    vector <int> nxt;
    for (int j = 0; j < (int) save.size(); j++) {
      int u = save[j];
      for (int jj = 0; jj < (int) adj[u].size(); jj++) {
        pair <int, char> neighbor = adj[u][jj];
        if (dist[u] != dist[neighbor.first] + 1) {
          continue;
        }
        if (minChar >= neighbor.second) {
          if (minChar > neighbor.second) {
            nxt.clear();
            minChar = neighbor.second;
          }
          nxt.push_back(neighbor.first);
          trace[neighbor.first] = u;
        }
      }
    }
    sort(nxt.begin(), nxt.end());
    save.clear();
    if (!nxt.empty()) {
      save.push_back(nxt[0]);
      for (int i = 1; i < (int) nxt.size(); i++) {
        if (nxt[i] != nxt[i - 1]) {
          save.push_back(nxt[i]);
        }
      }
    }
    path += (char) (minChar);
  }
  printf("%d\n", dist[1]);
  int u = n;
  do {
    ans.push_back(u);
    u = trace[u];
  }
  while (trace[u] != 0);
  reverse(ans.begin(), ans.end());
  printf("1 ");
  for (int i = 0; i < (int) ans.size(); i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  cout << path;
  return 0;
}