#include <bits/stdc++.h>

using namespace std;

const int inf = 200000007;
const long long MOD = 1000000009;
const int MAX_N = 2005;
vector <pair <int, int> > adj[MAX_N];
long long ways[MAX_N];
bool visited[MAX_N];

void dijkstra(int start, vector <int> &dist) {
  priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
  pq.push(make_pair(0, start));
  dist[start] = 0LL;
  ways[start] = 1LL;
  while (!pq.empty()) {
    pair <int, int> pqTop = pq.top();
    pq.pop();
    int u = pqTop.second;
    if (dist[u] != pqTop.first) {
      continue;
    }
    for (int i = 0; i < (int) adj[u].size(); i++) {
      pair <int, int> neighbor = adj[u][i];
      int v = neighbor.first;
      int w = neighbor.second;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        ways[v] = ways[u];
        pq.push(make_pair(dist[v], v));
      }
      else if (dist[v] == dist[u] + w) {
        (ways[v] += ways[u]) %= MOD;
      }
    }
  }
}

class DrivingPlans {
  public:
  int count(int N, vector <int> A, vector <int> B, vector <int> C) {
    vector <int> distStart, distEnd;
    for (int i = 0; i < (int) A.size(); i++) {
      adj[A[i]].push_back(make_pair(B[i], C[i]));
      adj[B[i]].push_back(make_pair(A[i], C[i]));
    }
    distStart.resize(N + 2, inf);
    distEnd.resize(N + 2, inf);
    dijkstra(1, distStart);
    long long ans = ways[N];
    dijkstra(N, distEnd);
    for (int i = 0; i < N; i++) {
      if (C[i] == 0) {
        if (distStart[A[i]] + distEnd[B[i]] == distStart[N]) {
          return -1;
        }
        if (distStart[B[i]] + distEnd[A[i]] == distStart[N]) {
          return -1;
        }
      }
    }
    return ans;
  }
};

DrivingPlans D;

int main () {
  cout << D.count(7,
{1,1,2,3,4,4,5,6},
{2,3,4,4,5,6,7,7},
{1,1,2,2,3,3,4,4});
  return 0;
}