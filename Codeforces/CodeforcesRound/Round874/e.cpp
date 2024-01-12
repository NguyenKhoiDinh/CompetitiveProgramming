#include <iostream>
#include <math.h>  
#include <vector> 
int numTest; 
std::vector <int> adj[200005]; 
int deg[200005]; 
int n;
int a[200005]; 
bool visited[200005]; 

void dfs(std::vector <int> &save, int u) {
  visited[u] = true; 
  save.push_back(u); 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == false) {
      dfs(save, v); 
    }
  }
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      deg[i] = 0; 
      visited[i] = false; 
    }
    int mini = 0; 
    int maxi = 0; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
      adj[i].push_back(a[i]);
      adj[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
      if (visited[i] == false) {
        maxi++; 
        std::vector <int> save; 
        dfs(save, i);
        if ((int) save.size() == 2) {
          continue;
        }
        bool check = true; 
        for (int j = 0; j < (int) save.size(); j++) {
          int u = save[j];
          for (int x = 0; x < (int) adj[u].size(); x++) {
            int v = adj[u][x]; 
            if (v < u) {
              continue; 
            }
            deg[u]++;
            deg[v]++; 
          }
        }
        for (int j = 0; j < (int) save.size(); j++) {
          if (deg[save[j]] != 2) {
            check = false; 
            break;
          }
        } 
        if (check == true) {
          mini++; 
        }
      }
    }
    std::cout << std::min(mini + 1, maxi) << ' ' << maxi << std::endl; 
  }
  return 0; 
}