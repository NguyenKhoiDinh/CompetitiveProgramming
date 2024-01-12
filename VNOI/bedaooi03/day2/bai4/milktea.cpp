#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <utility>
#include <tuple>
const long long inf = 100000000000007LL; 
int n, m, k;
std::vector <int> t;
std::vector <std::vector <std::pair <int, int> > > adj; 
struct element {
  int u; 
  int v1, v2;
  long long distance1, distance2; 
  bool operator > (const element &other) const {
    return distance1 < other.distance1;   
  } 
};
long long dist[100005][2];
std::priority_queue <element> pq; 

int main () {
  freopen("milktea.inp", "r", stdin);
  freopen("milktea.out", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> n >> m >> k;
  adj.resize(n); 
  t.resize(n, -1); 
  for (int i = 1; i <= m; i++) {
    int u, v, w; 
    std::cin >> u >> v >> w; 
    u--;
    v--;
    adj[u].push_back(std::make_pair(v, w)); 
    adj[v].push_back(std::make_pair(u, w));
  }
  for (int i = 0; i < k; i++) {
    int p, state;
    std::cin >> p >> state; 
    p--;
    t[p] = state; 
    dist[p][0] = 0LL;
    pq.push((element) {p, p, -1, 0, inf});   
  } 
  while (pq.empty() == false) {
    element e = pq.top();
    pq.pop(); 
    if (e.distance1 != dist[e.u][0]
  }
  for (int i = 0; i < n; i++) {
    if (t[i] == -1 || t[i] == 1) {
      std::cout << dist[i][0] << ' '; 
    }  
    else {
      std::cout << 0 << ' ';
    }
  }
  return 0; 
}