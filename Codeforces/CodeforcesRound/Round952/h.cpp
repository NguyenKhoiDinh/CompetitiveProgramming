#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <stack> 
int numTest; 
int root[1000005];
int rank[1000005]; 
int szComponent[1000005]; 
struct element {
  int rootu, backRoot, rootv, backRank, backSize; 
};
std::stack <element> st; 
int n, m;
std::vector <std::string> a;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};  
int findRoot(int u) {
  return (u == root[u] ? u : findRoot(root[u]));
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i]; 
    } 
    while (st.empty() == false) {
      st.pop(); 
    }
    for (int i = 0; i < n * m; i++) {
      root[i] = i;
      rank[i] = 0;
      szComponent[i] = 1;   
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '.') {
          continue; 
        }
        int id = i * m + j;
        for (int k = 0; k < 4; k++) {
          int x = i + dx[k];
          int y = j + dy[k];
          if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '#') {
            int idnext = x * m + y;
            int rootu = findRoot(id);
            int rootv = findRoot(idnext);
            if (rootu != rootv) {
              if (rank[rootu] > rank[rootv]) {
                std::swap(rootu, rootv);
              }
              root[rootu] = rootv; 
              szComponent[rootv] += szComponent[rootu];
              ans = std::max(ans, szComponent[rootv]);
              if (rank[rootu] == rank[rootv]) {
                rank[rootv]++; 
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int id = i * m + j; 
        for (int k = 0; k < 4; k++) {
          int x = i + dx[k];
          int y = j + dy[k];
          if (x >= 0 && x < n && y >= 0 && y < m && (a[x][y] == '#' || x == i)) {
            int idnext = x * m + y;
            int rootu = findRoot(id);
            int rootv = findRoot(idnext);
            if (rootu != rootv) {
              if (rank[rootu] > rank[rootv]) {
                std::swap(rootu, rootv); 
              }
              st.push((element) {rootu, root[rootu], rootv, rank[rootv], szComponent[rootv]});
              root[rootu] = rootv;
              szComponent[rootv] += szComponent[rootu];
              ans = std::max(ans, szComponent[rootv]);
              if (rank[rootu] == rank[rootv]) {
                rank[rootv]++;
              }  
            } 
          }
        }
      }
      while (st.empty() == false) {
        element e = st.top();
        st.pop();
        root[e.rootu] = e.backRoot; 
        rank[e.rootv] = e.backRank;
        szComponent[e.rootv] = e.backSize;
      }
    }
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        int id = i * m + j;
        for (int k = 0; k < 4; k++) {
          int x = i + dx[k];
          int y = j + dy[k];
          if (x >= 0 && x < n && y >= 0 && y < m && (a[x][y] == '#' || y == j)) {
            int idnext = x * m + y;
            int rootu = findRoot(id);
            int rootv = findRoot(idnext);
            if (rootu != rootv) {
              if (rank[rootu] > rank[rootv]) {
                std::swap(rootu, rootv); 
              }
              st.push((element) {rootu, root[rootu], rootv, rank[rootv], szComponent[rootv]}); 
              root[rootu] = rootv; 
              szComponent[rootv] += szComponent[rootu];
              ans = std::max(ans, szComponent[rootv]); 
              if (rank[rootu] == rank[rootv]) {
                rank[rootv]++; 
              }
            }
          }
        }
      }
      while (st.empty() == false) {
        element e = st.top();
        st.pop();
        root[e.rootu] = e.backRoot;
        rank[e.rootv] = e.backRank;
        szComponent[e.rootv] = e.backSize; 
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}