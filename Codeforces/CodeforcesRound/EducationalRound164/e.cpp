#include <iostream> 
#include <math.h>
#include <vector> 
int n;
int a[100005]; 
int maxValue = -1;
std::vector <int> position[100005];  
int numbComponents[100005]; 
int root[100005];
int findRoot(int u) {
  return root[u] = (root[u] == u ? u : findRoot(root[u]));
} 

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    position[a[i]].push_back(i); 
    if (maxValue < a[i]) {
      maxValue = a[i]; 
    } 
  }
  for (int i = 0; i <= n + 1; i++) {
    root[i] = i; 
  }
  int numb = 2; 
  for (int v = 1; v <= maxValue; v++) {
    for (int i = 0; i < (int) position[v].size(); i++) {
      int p = position[v][i];
      a[p] = 0; 
      numb++;
      int rootp = findRoot(p); 
      int j = p - 1;
      int rootj = findRoot(j); 
      if (a[j] == 0 && rootp != rootj) {
        numb--; 
      }
      j = p + 1;
      rootj = findRoot(j);
      if (a[j] == 0 && rootp != rootj) {
        numb--; 
      } 
    }
    numbComponents[v] = std::max(0, numb - 1); 
  }
  for (int v = 1; v <= maxValue; v++) {
    long long ans = 1;
    for (int i = v; i <= maxValue; i += v) {
      ans += numbComponents[i];
    }
    std::cout << ans << ' ';
  }
  return 0; 
}