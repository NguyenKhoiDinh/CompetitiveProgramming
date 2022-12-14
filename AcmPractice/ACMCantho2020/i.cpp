#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <functional>
#include <stdio.h>
#include <fstream>

using namespace std;
const int MAX_N = 500005;
const long long inf = 10000000000000007LL;
vector <pair <int, long long> > adj[MAX_N];
vector <long long> distHousec, distSchoolc, distHouseh, distSchoolh;
int n, m, housec, schoolc, househ, schoolh;

void Dijkstra(int start, vector <long long> &dist) {
  priority_queue <pair <long long, int>, vector <pair <long long, int> >, greater <pair <long long, int> > > pq;
  dist[start] = 0LL;
  pq.push(make_pair(0LL, start));
  while (!pq.empty()) {
    pair <long long, int> pqTop = pq.top();
    pq.pop();
    int u = pqTop.second;
    if (dist[u] != pqTop.first) {
      continue;
    }
    for (int i = 0; i < (int) adj[u].size(); i++) {
      pair <int, long long> neighbor = adj[u][i];
      int v = neighbor.first;
      if (dist[v] > dist[u] + neighbor.second) {
        dist[v] = dist[u] + neighbor.second;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
}

bool onShortestPath(int u) {
  if (distHousec[u] + distSchoolc[u] != distHousec[schoolc]) {
    return false;
  }
  if (distHouseh[u] + distSchoolh[u] != distHouseh[schoolh]) {
    return false;
  }
  return true;
}

bool checkInfinite(int u, int v, long long weight) {
  if (onShortestPath(u) == false) {
    return false;
  }
  if (onShortestPath(v) == false) {
    return false;
  }
  if (distHousec[u] + weight + distSchoolc[v] != distHousec[schoolc]) {
    return false;
  }
  if (distHouseh[u] + weight + distSchoolh[v] != distHouseh[schoolh]) {
    return false;
  }
  if (distHousec[u] == distHouseh[u]) {
    return true;
  }
  return false;
}

bool canMeet(int u, int v, long long weight) {
  if (onShortestPath(u) == false) {
    return false;
  }
  if (onShortestPath(v) == false) {
    return false;
  }
  if (distHousec[u] + weight + distSchoolc[v] != distHousec[schoolc]) {
    return false;
  }
  if (distHouseh[v] + weight + distSchoolh[u] != distHouseh[schoolh]) {
    return false;
  }
  if (distHousec[u] + weight <= distHouseh[v]) {
    return false;
  }
  if (distHouseh[v] + weight <= distHousec[u]) {
    return false;
  }
  return true;
}

void process() {
  int ans = 0;
  if (schoolc == schoolh) {
    ans++;
  }
  else {
    if (distHouseh[schoolc] + distSchoolh[schoolc] == distHouseh[schoolh]) {
      if (distHousec[schoolc] <= distHouseh[schoolc]) {
        ans++;
      }
    }
    if (distHousec[schoolh] + distSchoolc[schoolh] == distHousec[schoolc]) {
      if (distHouseh[schoolh] <= distHousec[schoolh]) {
        ans++;
      }
    }
  }
  for (int u = 1; u <= n; u++) {
    for (int i = 0; i < (int) adj[u].size(); i++) {
      int v = adj[u][i].first;
      long long weight = adj[u][i].second;
      if (canMeet(u, v, weight) == true) {
        ans++;
      }
    }
  }
  for (int u = 1; u <= n; u++) {
    if (u != schoolc && u != schoolh) {
      if (distHousec[u] + distSchoolc[u] != distHousec[schoolc]) {
        continue;
      }
      if (distHouseh[u] + distSchoolh[u] != distHouseh[schoolh]) {
        continue;
      }
      if (distHousec[u] == distHouseh[u]) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  while (true) {
    scanf("%d %d", &n, &m);
    if (n == 0 && m == 0) {
      break;
    }
    distHousec.resize(n + 1, 0LL);
    distHouseh.resize(n + 1, 0LL);
    distSchoolc.resize(n + 1, 0LL);
    distSchoolh.resize(n + 1, 0LL);
    for (int i = 1; i <= n; i++) {
      distHousec[i] = inf;
      distSchoolc[i] = inf;
      distHouseh[i] = inf;
      distSchoolh[i] = inf;
      adj[i].clear();
    }
    scanf("%d %d %d %d", &housec, &schoolc, &househ, &schoolh);
    for (int i = 1; i <= m; i++) {
      int u, v;
      long long weight;
      scanf("%d %d %lld", &u, &v, &weight);
      adj[u].push_back(make_pair(v, weight));
      adj[v].push_back(make_pair(u, weight));
    }
    Dijkstra(housec, distHousec);
    Dijkstra(schoolc, distSchoolc);
    Dijkstra(househ, distHouseh);
    Dijkstra(schoolh, distSchoolh);
    bool check = true;
    for (int u = 1; u <= n; u++) {
      if (check == false) {
        break;
      }
      for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i].first;
        long long weight = adj[u][i].second;
        if (checkInfinite(u, v, weight) == true) {
          check = false;
          break;
        }
      }
    }
    if (check == false) {
      cout << -1 << endl;
      continue;
    }
    process();
  }
  return 0;
}