#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1000000007;
const int MAX_N = 2005;
vector <pair <int, int> > adj[MAX_N];
int dist[MAX_N][MAX_N];
bitset <MAX_N> S[MAX_N];
long long power2[MAX_N];

struct element {
  int u, v, weight;
  bool operator < (const element &other) const {
    if (weight != other.weight) {
      return (weight < other.weight);
    }
    if (u != other.u) {
      return (u < other.u);
    }
    return (v < other.v);
  }
};
vector <element> save;

void dfs(int start, int u, int father) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    pair <int, int> neighbor = adj[u][i];
    int v = neighbor.first;
    int w = neighbor.second;
    if (v == father) {
      continue;
    }
    dist[start][v] = dist[start][u] + w;
    dfs(start, v, u);
  }
}

class MapleTree {
  public:
  int sum(vector <int> p, vector <int> length) {
    int n = (int) p.size() + 1;
    power2[0] = 1LL;
    for (int i = 1; i <= n; i++) {
      power2[i] = (power2[i - 1] * 2LL) % MOD;
    }
    for (int i = 0; i < n - 1; i++) {
      adj[p[i]].push_back(make_pair(i + 1, length[i]));
      adj[i + 1].push_back(make_pair(p[i], length[i]));
    }
    for (int i = 0; i < n; i++) {
      dist[i][i] = 0;
      dfs(i, i, -1);
    }
    for (int u = 0; u < n; u++) {
      for (int v = u + 1; v < n; v++) {
        save.push_back((element) {u, v, dist[u][v]});
      }
    }
    sort(save.begin(), save.end());
    long long ans = 0LL;
    for (int i = 0; i < (int) save.size(); i++) {
      element e = save[i];
      int u = e.u;
      int v = e.v;
      int weight = e.weight;
      long long mul = (long long) weight;
      int cnt = (S[u] & S[v]).count();
      (mul *= power2[cnt]) %= MOD;
      (ans += mul) %= MOD;
      S[u].set(v, 1);
      S[v].set(u, 1);
    }
    return (int) ans;
  }
};

MapleTree M;

int main () {
  cout << M.sum({0, 0, 1, 1, 2},
{1, 2, 1, 1, 2});
  return 0;
}