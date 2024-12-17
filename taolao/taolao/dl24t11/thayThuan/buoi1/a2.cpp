#include <iostream> 
#include <functional>
#include <vector>
#include <queue> 
int n; 
int numbChildren[200005]; 
std::priority_queue <int, std::vector <int>, std::greater <int> > pq; 
std::vector <int> adj[200005]; 
int dfs(int u, int father) {
  int ret = 1; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    ret += dfs(v, u); 
  }
  numbChildren[u] = ret; 
  return ret; 
}

int main () {
  std::cin >> n;
  for (int i = 2; i <= n; i++) {
    int father;
    std::cin >> father;     
    adj[father].push_back(i);
    adj[i].push_back(father); 
  }
  dfs(1, -1);
  for (int i = 1; i <= n; i++) {
    pq.push(numbChildren[i]); 
  }  
  long long ans = 0LL; 
  while (pq.empty() == false) {
    std::cout << ans << ' '; 
    int pqTop = pq.top();
    pq.pop(); 
    ans += pqTop - 1; 
  }
  std::cout << ans;
  return 0; 
}