#include <iostream>
#include <queue>

int dist[1000005]; 
int a[12], b[12]; 
std::queue <int> myqueue; 
int mod; 
int n;
int s0; 

int main () {
  std::cin >> mod >> n >> s0; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i];
  }
  for (int i = 0; i < mod; i++) {
    dist[i] = -1; 
  }
  dist[s0] = 0; 
  myqueue.push(s0); 
  while (!myqueue.empty()) {
    int u = myqueue.front();
    myqueue.pop();
    for (int i = 1; i <= n; i++) {
      long long v = (1LL * u * a[i] + 1LL * b[i]) % mod; 
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        myqueue.push(v); 
      }
    }
  }
  std::cout << dist[0];
  return 0; 
}