#include <iostream> 
#include <vector>
#include <utility>
std::vector <std::pair <int, char> > adj[100005];
int n;
int L[100005], R[100005];
int timeDfs = 0;
int isOk[100005];  

void dfsEuler(int u, int father) {
  timeDfs++;
  L[u] = timeDfs;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    std::pair <int, char> neighbor = adj[u][i];
    if (neighbor.first == father) {
      continue; 
    }
    dfsEuler(neighbor.first, u); 
  }  
  R[u] = timeDfs; 
}  

void update(int l, int r) {
  isOk[l]++;
  isOk[r + 1]--; 
}

void dfs(int u, int father, char prevChar) {
  bool isEqual = false;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    std::pair <int, char> neighbor = adj[u][i];
    if (neighbor.first == father) {
      continue;
    }
    if (neighbor.second == prevChar) {
      isEqual = true;
      break;   
    }
  }
  if (isEqual == true) {
    update(L[u], R[u]);                
    for (int i = 0; i < (int) adj[u].size(); i++) {
      std::pair <int, char> neighbor = adj[u][i];
      if (neighbor.first == father) {
        continue;
      }
      if (neighbor.second != prevChar) {
        update(L[neighbor.first], R[neighbor.first]); 
      }
    }
  }
  std::vector <std::vector <int> > save;
  save.resize(26);  
  for (int i = 0; i < (int) adj[u].size(); i++) {
    std::pair <int, char> neighbor = adj[u][i];
    if (neighbor.first == father) {
      continue;
    }
    save[neighbor.second - 'a'].push_back(neighbor.first);  
  }
  int cnt = 0; 
  int saveChar = -1;
  for (int i = 0; i < 26; i++) {
    if ((int) save[i].size() == 2) {
      cnt++;    
      saveChar = i; 
    }
  }
  if (cnt > 1) {
    std::cout << 0;
    exit(0); 
  }
  if (cnt == 1) {
    int x = save[saveChar][0];
    int y = save[saveChar][1];
    update(1, L[u]); 
    update(R[u] + 1, n); 
    for (int i = 0; i < (int) adj[u].size(); i++) {
      std::pair <int, char> neighbor = adj[u][i]; 
      if (neighbor.first == father) {
        continue;
      }
      if (neighbor.first != x && neighbor.first != y) {
        update(L[neighbor.first], R[neighbor.first]); 
      }
    }  
  }
  save.clear(); 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    std::pair <int, char> neighbor = adj[u][i];
    if (neighbor.first == father) {
      continue;
    }
    dfs(neighbor.first, u, neighbor.second); 
  }
}
              
int main () {
  freopen("trie.inp", "r", stdin);
  freopen("trie.out", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL); 
  std::cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v; 
    char c;
    std::cin >> u >> v >> c; 
    adj[u].push_back(std::make_pair(v, c));
    adj[v].push_back(std::make_pair(u, c));
  }
  bool check = true; 
  for (int i = 1; i <= n; i++) {
    std::vector <int> cnt;
    cnt.resize(26, 0);
    for (int j = 0; j < (int) adj[i].size(); j++) {
      cnt[adj[i][j].second - 'a']++; 
    }
    for (int c = 0; c < 26; c++) {
      if (cnt[c] > 2) {
        check = false;
        break;  
      }
    }
    if (check == false) {
      break; 
    }  
  }
  if (check == false) {
    std::cout << 0;
    return 0; 
  }
  dfsEuler(1, -1); 
  dfs(1, -1, -1);
  for (int i = 1; i <= n; i++) {
    isOk[i] += isOk[i - 1]; 
  } 
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (isOk[i] == 0) {
      ans++;
    }
  }
  std::cout << ans; 
  return 0; 
}