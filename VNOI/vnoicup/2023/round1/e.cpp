#include <iostream>
#include <utility> 
#include <vector> 
#include <set> 
#include <algorithm> 
#include <deque>
#include <map>
#include <math.h>
int n, m, l; 
std::multiset <int> S; 
std::vector <std::pair <int, int> > a; 
std::vector <int> adj[200005]; 
std::map <int, std::deque <int> > dq;  
bool visited[200005];  

void dfs(int u, std::vector <int> &save) {
  save.push_back(u);
  visited[u] = true; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == false) {
      dfs(v, save); 
    }
  }
}

int main () {
  std::cin >> m >> n >> l;
  a.resize(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].first >> a[i].second; 
  }
  std::sort(a.begin(), a.end()); 
  int p = 0; 
  for (int i = 0; i < n; i++) {
    while (p < i && a[i].first - a[p].first > l) {
      std::multiset <int>::iterator it = S.find(a[p].second);
      S.erase(it);
      dq[a[p].second].pop_front();
      p++;       
    }
    std::multiset <int> ::iterator it = S.upper_bound(a[i].second + l);
    if (it != S.begin()) {
      it--; 
      int node = dq[*it].front();                               
      adj[i].push_back(node);    
      adj[node].push_back(i); 
      dq[*it].pop_front(); 
      S.erase(it); 
    }
    it = S.lower_bound(a[i].second - l); 
    if (it != S.end()) {
      int node = dq[*it].front(); 
      adj[i].push_back(node);
      adj[node].push_back(i);
      dq[*it].pop_front();
      S.erase(it);   
    }
    S.insert(a[i].second); 
    dq[a[i].second].push_back(i); 
  } 
  std::vector <std::pair <int, int> > ans; 
  for (int i = 0; i < n; i++) {
    std::vector <int> save; 
    if (visited[i] == false) {
      dfs(i, save);   
    }
    int minx = m + 2;
    int maxx = -1;
    int miny = m + 2; 
    int maxy = -1; 
    for (int j = 0; j < (int) save.size(); j++) {
      minx = std::min(minx, a[save[j]].first);
      maxx = std::max(maxx, a[save[j]].first);
      miny = std::min(miny, a[save[j]].second);
      maxy = std::max(maxy, a[save[j]].second);
    }       
    if ((minx - l <= 0 || maxy + l >= m) && (maxx + l >= m || miny - l <= 0)) {
      for (int j = 0; j < (int) save.size(); j++) {
        ans.push_back(a[save[j]]);
      }         
    }
  }
  std::cout << (int) ans.size() << std::endl; 
  for (int i = 0; i < (int) ans.size(); i++) {
    std::cout << ans[i].first << ' ' << ans[i].second << std::endl;
  }
  return 0; 
}
