#include <iostream> 
#include <set> 
#include <vector>
#include <algorithm>
int r[200005]; 
int n, numTest;
std::set <int> in[200005], tmpIn[200005];
std::set <int> listNotIn;
int d[200005];
bool visited[200005];     
bool deleted[200005];          

int main () {
  std::ios_base::sync_with_stdio(false); 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    listNotIn.clear(); 
    for (int i = 1; i <= n; i++) {
      in[i].clear();
      tmpIn[i].clear(); 
      d[i] = 1;
      visited[i] = false;
      deleted[i] = false;   
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> r[i];
      in[r[i]].insert(i);
      tmpIn[r[i]].insert(i);   
    }
    for (int i = 1; i <= n; i++) {
      if (in[i].empty() == true) {
        listNotIn.insert(i); 
      }
    }
    int ans = 1; 
    while (listNotIn.empty() == false) {
      std::vector <int> newNotIn; 
      for (std::set <int>::iterator it = listNotIn.begin(); it != listNotIn.end(); it++) {
        int u = *it; 
        deleted[u] = true; 
        int next = r[u];
        d[next] += d[u]; 
        in[next].erase(in[next].find(u));
        if (in[next].empty() == true) {
          newNotIn.push_back(next); 
        }  
      }
      listNotIn.clear();
      while (newNotIn.empty() == false) {
        listNotIn.insert(newNotIn.back()); 
        newNotIn.pop_back(); 
      }
    }
    for (int i = 1; i <= n; i++) {
      if (visited[i] == false && in[i].empty() == false) {
        int p = i; 
        int lenCycle = 0;
        bool isEqual = true; 
        while (visited[p] == false) {
          visited[p] = true;
          for (std::set <int>::iterator it = tmpIn[p].begin(); it != tmpIn[p].end(); it++) {
            int u = *it;
            if (deleted[u] == true) {
              ans = std::max(ans, d[u] + 1); 
            }
          }
          p = r[p];                 
        } 
      }
    }
    std::cout << ans + 1 << std::endl;                 
  }
  return 0; 
}