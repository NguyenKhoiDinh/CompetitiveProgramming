#include <iostream> 
#include <string> 
#include <vector> 
int numTest; 
int n; 
int p[200005]; 
std::string s; 
bool visited[200005]; 
int f[200005];  
std::vector <int> groups[200005]; 
int cnt = 0; 
void dfs(int u, int id) {
  if (s[u] == '0') {
    cnt++; 
  }  
  groups[id].push_back(u); 
  visited[u] = true; 
  if (visited[p[u]] == false) {
    dfs(p[u], id); 
  }
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
      std::cin >> p[i];
      p[i]--; 
    }
    std::cin >> s; 
    for (int i = 0; i < n; i++) {
      visited[i] = false; 
      groups[i].clear(); 
      f[i] = 0; 
    }
    int id = 0; 
    for (int i = 0; i < n; i++) {
      if (visited[i] == false) {
        cnt = 0; 
        dfs(i, id);
        for (int j = 0; j < (int) groups[id].size(); j++) {
          f[groups[id][j]] = cnt; 
        }
        id++;         
      }
    }
    for (int i = 0; i < n; i++) {
      std::cout << f[i] << ' '; 
    }
    std::cout << std::endl;
  }
  return 0; 
}