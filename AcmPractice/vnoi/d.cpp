#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 10005; 
const int inf = 1000000007; 
vector <pair <int, int> > adj[MAX_N]; 
int n, m, k; 
struct element {
  int fluence, moon; 
};
element a[MAX_N]; 
map <string, int> ID; 
string source, des;
int IDsource, IDdes; 
int cost[MAX_N]; 
int dist[MAX_N];
int totalMoon[MAX_N]; 

void bfs(int start) {
  if (k == 0) {
    return;
  }
  queue <int> myqueue; 
  for (int i = 1; i <= n; i++) {
    dist[i] = -1; 
  }
  dist[start] = 0; 
  myqueue.push(start); 
  while (!myqueue.empty()) {
    int u = myqueue.front();
    myqueue.pop();
    for (int i = 0; i < (int) adj[u].size(); i++) {
      pair <int, int> neighbor = adj[u][i];
      if (dist[neighbor.first] == -1) {
        dist[neighbor.first] = dist[u] + 1; 
        cost[start] += a[neighbor.first].fluence; 
        if (dist[neighbor.first] < k) {
          myqueue.push(neighbor.first);
        }
      }
    }
  }
}

void dijkstra(int start, int end) {
  for (int i = 1; i <= n; i++) {
    dist[i] = inf; 
  }  
  totalMoon[start] = a[start].moon; 
  dist[start] = 0; 
  priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq; 
  pq.push(make_pair(0, start)); 
  while (!pq.empty()) {
    pair <int, int> pqTop = pq.top();
    pq.pop(); 
    if (pqTop.first != dist[pqTop.second]) {
      continue; 
    }
    int u = pqTop.second; 
    for (int i = 0; i < (int) adj[u].size(); i++) {
      pair <int, int> neighbor = adj[u][i];
      int v = neighbor.first;
      int weight = neighbor.second;
      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight; 
        totalMoon[v] = totalMoon[u] + a[v].moon; 
        pq.push(make_pair(dist[v], v));
      }
      else if (dist[v] == dist[u] + weight) {
        totalMoon[v] = max(totalMoon[v], totalMoon[u] + a[v].moon);
      }
    }
  }
  cout << dist[end] << ' ' << totalMoon[end]; 
}

int main () {
  cin >> n >> m >> k;
  cin >> source >> des; 
  for (int i = 1; i <= n; i++) {
    string name; 
    cin >> name >> a[i].moon >> a[i].fluence;
    ID[name] = i;  
  }
  for (int i = 1; i <= m; i++) {
    string name1, name2; 
    int weight; 
    cin >> name1 >> name2 >> weight;
    int u = ID[name1];
    int v = ID[name2];
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight));
  }
  for (int i = 1; i <= n; i++) {
    bfs(i);   
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int) adj[i].size(); j++) {
      adj[i][j].second += cost[i]; 
    }
  }
  IDsource = ID[source];
  IDdes = ID[des];                           
  dijkstra(IDsource, IDdes); 
  return 0; 
}