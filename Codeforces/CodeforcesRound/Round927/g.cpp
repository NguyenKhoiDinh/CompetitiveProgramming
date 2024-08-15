#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
#include <assert.h>
const long long inf = 10000000000000007LL; 
struct element {
  int to; 
  long long x0 = inf, y0 = inf; 
  long long gcd;
};
int numTest, n, m, H; 
std::vector <element> adj[100005]; 
long long dist[100005]; 
int s[100005], l[100005]; 
void solve(int a, int b, long long &x, long long &y) {                  
  if (b == 0) {
    x = 1; 
    y = 0; 
    return; 
  }
  long long x1, y1; 
  solve(b, a % b, x1, y1); 
  x = y1; 
  y = x1 - (a / b) * y1; 
}

long long g(const long long &x, const long long &h) {
  long long ret = x / h;
  if (h > 0) {
    if (x > 0) {
      if (x % h != 0) {
        ret++; 
      }
    }
  }
  else {
    if (x > 0) {
      if (x % std::abs(h) != 0) {
        ret--; 
      }
    }
  }                                           
  return ret;                        
}

void dijkstra(int start) {
  std::priority_queue <std::pair <long long, int>, std::vector <std::pair <long long, int> >, std::greater <std::pair <long long, int> > > pq; 
  dist[start] = 0LL;
  pq.push(std::make_pair(0LL, start)); 
  while (pq.empty() == false) {
    std::pair <long long, int> pqTop = pq.top();
    pq.pop(); 
    if (pqTop.first != dist[pqTop.second]) {
      continue; 
    }
    int u = pqTop.second; 
    for (int i = 0; i < (int) adj[u].size(); i++) {
      element neighbor = adj[u][i]; 
      long long x0 = neighbor.x0; 
      long long gcd = neighbor.gcd;
      long long h = H / gcd; 
      long long x = x0 + g(dist[u] - x0, h) * h + 1;
      if (dist[neighbor.to] > x) {
        dist[neighbor.to] = x;
        pq.push(std::make_pair(dist[neighbor.to], neighbor.to)); 
      } 
    }
  }
  std::cout << (dist[n] == inf ? -1 : dist[n]) << std::endl; 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m >> H;
    for (int i = 1; i <= n; i++) {
      dist[i] = inf; 
      adj[i].clear(); 
    } 
    for (int i = 1; i <= n; i++) {
      std::cin >> l[i];
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> s[i]; 
    }
    for (int i = 1; i <= m; i++) {
      int u, v;
      std::cin >> u >> v; 
      int a = std::abs(s[u] - s[v]); 
      int c = std::abs(l[u] - l[v]); 
      long long gcd = std::__gcd(a, H); 
      long long x0 = inf; 
      long long y0 = inf; 
      if (c % gcd != 0) {
        continue; 
      }
      a = s[v] - s[u]; 
      int b = H;
      c = l[u] - l[v]; 
      solve(a, b, x0, y0);
      gcd = x0 * a + y0 * b;
      x0 *= c / gcd;
      y0 *= c / gcd;
      adj[u].push_back((element) {v, x0, y0, gcd});
      adj[v].push_back((element) {u, x0, y0, gcd});  
    }
    dijkstra(1); 
  }
  return 0; 
}