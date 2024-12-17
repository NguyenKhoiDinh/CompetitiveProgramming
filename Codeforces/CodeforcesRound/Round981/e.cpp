#include <iostream> 
int n; 
int p[1000005]; 
bool visited[1000005];
int len = 0;  
void dfs(int u) {
  len++; 
  visited[u] = true;
  if (visited[p[u]] == false) {
    dfs(p[u]); 
  }
}

int main () {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> p[i];
      visited[i] = false;  
    }
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
      if (visited[i] == false) {
        len = 0; 
        dfs(i);
        ans += (len - 1) / 2;  
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}       



           
