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

class RandomDijkstraDiv1 {
  public:
  double solve(int n, vector <int> G) {
    freopen("output.txt", "w", stdout);
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
    dp[0] = 1.0;
    for (int mask = 0; mask < pow3[n]; mask++) {
      if (dp[mask] == 0.0) {
        continue;
      }
      vector <int> state = convertToArray(mask, n);
      int cntOptimize = 0;
      for (int u = 0; u < n; u++) {
        if (state[u] == 0) {
          cntOptimize++;
        }
      }
      bool isExist2 = false;
      for (int u = 0; u < n; u++) {
        if (state[u] == 2) {
          isExist2 = true;
          break;
        }
      }
      for (int u = 0; u < n; u++) {
        if (state[u] == 0) {
          bool flag = false;
          for (int v = 0; v < n; v++) {
            if (state[v] == 2 && dist[v] + cost[v][u] == dist[u]) {
              flag = true;
              break;
            }
          }
          if (flag == true) {
            int nxtMask = mask + 2 * pow3[u];
            dp[nxtMask] += dp[mask] * 1.0 / cntOptimize;
          }
          else {
            if (isExist2 == false && dist[u] == 0 && u == 0) {
              int nxtMask = mask + 2 * pow3[u];
              dp[nxtMask] += dp[mask] * 1.0 / cntOptimize;
            }
            else {
              int nxtMask = mask + pow3[u];
              dp[nxtMask] += dp[mask] * 1.0 / cntOptimize;
            }
          }
        }
      }
    }
    double res = 0.0;
    for (int mask = 0; mask < pow3[n]; mask++) {
      vector <int> state = convertToArray(mask, n);
      bool flag = true;
      for (int u = 0; u < n; u++) {
        if (state[u] == 0) {
          flag = false;
          break;
        }
      }
      if (flag == false) {
        continue;
      }
      int tmpMask = mask;
      for (int u = 0; u < n; u++) {
        if (state[u] == 1) {
          bool check = false;
          for (int v = 0; v < n; v++) {
            if (state[v] == 2 && dist[v] + cost[v][u] == dist[u]) {
              check = true;
              break;
            }
          }
          if (check == true) {
            tmpMask += pow3[u];
          }
        }
      }
      if (tmpMask == pow3[n] - 1) {
        res += dp[mask];
      }
    }
    return res;
  }
};

RandomDijkstraDiv1 R;

int main () {
  cout << R.solve(4,
{ 0, 1, 1000, 1000, 1000, 0, 1, 1000, 1000, 1000, 0, 1, 1000, 1000, 1000, 0 });
  return 0;
}