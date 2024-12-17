#include <bits/stdc++.h> 
using namespace std;
const long double inf = 1000000007.00000;
struct edge {
  int to; 
  int length; 
  int velocity; 
};
vector <edge> adj[205]; 
double minTime[205][505]; 
int n, m, source, sink, startVelocity; 
priority_queue <pair <double, pair <int, int> >, vector <pair <double, pair <int, int> > >, greater <pair <double, pair <int, int> > > > pq; 

int main () {
  cin >> n >> m >> source >> sink >> startVelocity;
  for (int i = 1; i <= m; i++) {
    int from, to, length, velocity; 
    cin >> from >> to >> length >> velocity; 
    adj[from].push_back((edge) {to, length, velocity}); 
  }
  for (int u = 1; u <= n; u++) {
    for (int velocity = 1; velocity <= 500; velocity++) {
      minTime[u][velocity] = inf; 
    }
  }
  minTime[source][startVelocity] = 0.0; 
  pq.push(make_pair(0.0, make_pair(source, startVelocity))); 
  while (pq.empty() == false) {
    pair <double, pair <int, int> > pqTop = pq.top();
    pq.pop(); 
    int u = pqTop.second.first;
    int currentVelocity = pqTop.second.second;  
    double currentTime = pqTop.first;
    if (currentTime != minTime[u][currentVelocity]) {
      continue; 
    }
    for (int i = 0; i < (int) adj[u].size(); i++) {
      edge neighbor = adj[u][i];              
      int velocity = (neighbor.velocity == 0 ? velocity : neighbor.velocity); 
      double finishTime = 1.0 * neighbor.length / velocity;
      int v = neighbor.to; 
      if (minTime[v][velocity] > currentTime + finishTime) {
        minTime[v][velocity] = currentTime + finishTime; 
        pq.push(make_pair(minTime[v][velocity], make_pair(v, velocity))); 
      } 
    }
  }
  double ans = inf; 
  for (int velocity = 1; velocity <= 500; velocity++) {
    ans = min(ans, minTime[sink][velocity]); 
  }
  cout << fixed << setprecision(12) << ans; 
  return 0;    
}