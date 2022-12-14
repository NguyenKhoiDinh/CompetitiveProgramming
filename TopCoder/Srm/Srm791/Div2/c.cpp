#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 16;
const int inf = 1000000007;
int pow3[MAX_N];
double dp[14348912];
int dist[MAX_N];
int cost[MAX_N][MAX_N];

void Dijkstra(int n) {
  for (int i = 0; i < n; i++) {
    dist[i] = inf;
  }
  dist[0] = 0;
  priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
  pq.push(make_pair(0, 0));
  while (!pq.empty()) {
    pair <int, int> pr = pq.top();
    pq.pop();
    int u = pr.second;
    int distance = pr.first;
    if (dist[u] != distance) {
      continue;
    }
    for (int v = 0; v < n; v++) {
      if (dist[v] > dist[u] + cost[u][v]) {
        dist[v] = dist[u] + cost[u][v];
        pq.push(make_pair(dist[v], v));
      }
    }
  }
}

vector <int> convertToArray(int mask, int n) {
  vector <int> res;
  while (mask > 0) {
    res.push_back(mask % 3);
    mask /= 3;
  }
  int sz = (int) res.size();
  for (int i = 1; i <= n - sz; i++) {
    res.push_back(0);
  }
  return res;
}

class RandomDijkstraDiv2 {
  public:
  double solve(int n, vector <int> G) {
    pow3[0] = 1;
    for (int i = 1; i <= n; i++) {
      pow3[i] = pow3[i - 1] * 3;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cost[i][j] = G[i * n + j];
      }
    }
    Dijkstra(n);
    dp[1] = 1.0;
    for (int mask = 1; mask < pow3[n]; mask++) {
      if (dp[mask] != 0.0) {
        vector <int> state = convertToArray(mask, n);
        int numCandidate = 0;
        for (int u = 0; u < n; u++) {
          if (state[u] != 2) {
            numCandidate++;
          }
        }
        for (int u = 0; u < n; u++) {
          if (state[u] == 1) {
            int newMask = mask + pow3[u];
            for (int v = 0; v < n; v++) {
              if (state[v] == 0 && dist[v] == dist[u] + cost[u][v]) {
                newMask += pow3[v];
              }
            }
            dp[newMask] += dp[mask] * 1.0 / numCandidate;
          }
        }
      }
    }
    return dp[pow3[n] - 1];
  }
};

RandomDijkstraDiv2 R;

int main () {
  cout << R.solve(7, {0, 2, 2, 1, 1, 1, 2, 2, 0, 1, 2, 1, 2, 1, 2, 1, 0, 1, 1, 1, 1, 1, 1, 2, 0, 2, 2, 2, 2, 2, 2, 2, 0, 2, 1, 1, 1, 2, 1, 1, 0, 2, 2, 1, 1, 1, 1, 1, 0});
  return 0;
}