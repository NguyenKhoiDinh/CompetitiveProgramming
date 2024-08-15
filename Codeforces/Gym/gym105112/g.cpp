#include <iostream> 
#include <utility> 
#include <queue>
#include <iomanip>
#include <math.h> 
#include <vector>
const double inf = 1000000007.000000;  
struct point {
  double x, y, z; 
};
std::vector <std::pair <int, double> > adj[100005];
double distance[100005]; 
point a[100005]; 
int n, m, numQueries; 
double sqr(double x) {
  return x * x; 
}
double dist(int i, int j) {
  return std::sqrt(sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y) + sqr(a[i].z - a[j].z)); 
} 
void dijkstra(int start) {
  for (int i = 1; i <= n; i++) {
    distance[i] = inf; 
  }
  distance[1] = 0.0; 
  std::priority_queue <std::pair <double, int>, std::vector <std::pair <double, int> >, std::greater <std::pair <double, int> > > pq; 
  pq.push(std::make_pair(0.0, start)); 
  while (pq.empty() == false) {
    std::pair <double, int> pqTop = pq.top();
    pq.pop(); 
    int u = pqTop.second; 
    double d = pqTop.first;
    if (d != distance[u]) {
      continue; 
    }
    for (int i = 0; i < (int) adj[u].size(); i++) {
      std::pair <int, double> neighbor = adj[u][i];
      if (distance[neighbor.first] > d + neighbor.second) {
        distance[neighbor.first] = d + neighbor.second; 
        pq.push(std::make_pair(distance[neighbor.first], neighbor.first)); 
      }
    }
  }
}

int main () {
  std::cin >> n >> m >> numQueries; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].x >> a[i].y >> a[i].z; 
  }
  for (int i = 1; i <= m; i++) {
    int u, v; 
    std::cin >> u >> v;
    adj[u].push_back(std::make_pair(v, std::sqrt(dist(u, v)))); 
    adj[v].push_back(std::make_pair(u, std::sqrt(dist(u, v)))); 
  }
  dijkstra(1); 
  for (int query = 1; query <= numQueries; query++) {
    int finish; 
    double t; 
    std::cin >> finish >> t; 
    double a = t / distance[finish];           
    double delta = a * a - 4.0;
    double ans = inf;
    double c1 = (a - std::sqrt(delta)) / 2.0; 
    if (c1 > 0) {
      ans = std::min(ans, 2.0 * c1 * distance[finish]);  
    }
    double c2 = (a + std::sqrt(delta)) / 2.0; 
    if (c2 > 0) {
      ans = std::min(ans, 2.0 * c2 * distance[finish]);  
    }
    std::cout << std::fixed << std::setprecision(12);
    if (ans > 1000000000.00000) {
      std::cout << "impossible";
    }
    else {
      std::cout << ans; 
    }
    std::cout << std::endl; 
  }
  return 0; 
}