#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional> 
const long long inf = 1000000000000007LL; 
int numTest; 
int n, m; 
void dijkstra(int numbVertex, const std::vector <std::vector <std::pair <int, int> > > &adj, int start, int end) {
  std::vector <long long> dist(numbVertex, inf); 
  std::priority_queue <std::pair <long long, int>, std::vector <std::pair <long long, int> >, std::greater <std::pair <long long, int> > > pq; 
  dist[start] = 0; 
  pq.push(std::make_pair(0LL, start)); 
  while (pq.empty() == false) {
    std::pair <long long, int> element = pq.top(); 
    pq.pop(); 
    int node = element.second;
    long long distance = element.first;
    if (node == end) {
      std::cout << distance << std::endl; 
      return; 
    } 
    if (dist[node] != distance) {
      continue; 
    }
    for (int i = 0; i < (int) adj[node].size(); i++) {
      std::pair <int, int> neighbor = adj[node][i]; 
      if (dist[neighbor.first] > dist[node] + neighbor.second) {
        dist[neighbor.first] = dist[node] + neighbor.second; 
        pq.push(std::make_pair(dist[neighbor.first], neighbor.first)); 
      }
    }
  }
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {                  
    std::cin >> n >> m;
    std::vector <long long> c(n); 
    for (int i = 0; i < n; i++) {
      std::cin >> c[i]; 
    }
    std::vector <std::vector <long long> > a(n); 
    for (int i = 0; i < n; i++) {
      a[i].resize(m, 0); 
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cin >> a[i][j]; 
      }
    }
    std::vector <std::vector <std::pair <int, int> > > adj; 
    int numbVertex = (m + 1) * n; 
    adj.resize(numbVertex);
    for (int j = 0; j < m; j++) {
      std::vector <std::pair <int, int> > b; 
      for (int i = 0; i < n; i++) {
        b.push_back(std::make_pair(a[i][j], i)); 
      }
      std::sort(b.begin(), b.end()); 
      for (int i = 0; i < n; i++) {
        adj[b[i].second].push_back(std::make_pair(i + (j + 1) * n, c[b[i].second]));
        adj[i + (j + 1) * n].push_back(std::make_pair(b[i].second, 0));
        if (i + 1 < n) {
          adj[i + (j + 1) * n].push_back(std::make_pair(i + 1 + (j + 1) * n, b[i + 1].first - b[i].first));  
        } 
        if (i - 1 >= 0) {
          adj[i + (j + 1) * n].push_back(std::make_pair(i - 1 + (j + 1) * n, 0)); 
        }
      }
    }
    dijkstra(numbVertex, adj, n - 1, 0); 
  }
  return 0; 
}