#include <iostream>
int numTest; 
int next[200005]; 
bool in[200005]; 
int n, k; 
int a[200005]; 
int dist[200005];
int state[200005]; 

bool dfs(int u, int length) {
  if (state[u] > 0) {
    return (state[u] == 2);
  }
  if (dist[u] != -1) {
    state[u] = (length - dist[u] == k ? 2 : 1); 
    return (state[u] == 2); 
  } 
  dist[u] = length; 
  state[u] = (dfs(next[u], length + 1) == true ? 2 : 1);
  return (state[u] == 2);
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      in[i] = false;
      next[i] = -1;
      dist[i] = -1;
      state[i] = 0;   
    }
    bool ans = true; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
      next[i] = a[i];
      in[a[i]] = true;
      if (k == 1 && i != a[i]) {
        ans = false; 
      }  
    }
    for (int i = 1; i <= n; i++) {
      if (state[i] == 0) {
        if (dfs(i, 0) == false) {
          ans = false; 
          break; 
        } 
      }
    }
    std::cout << (ans == true ? "YES" : "NO") << std::endl; 
  }
  return 0; 
}