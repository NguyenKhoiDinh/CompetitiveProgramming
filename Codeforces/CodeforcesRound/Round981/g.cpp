#include <iostream> 
#include <math.h> 
#include <vector>  
int f[200005]; 
int n, numQueries;
int ans[200005];
int it[4 * 200005]; 
std::vector <int> adj[200005]; 
struct question {
  int stamina, id; 
};
std::vector <question> listQuestions[200005];
void update(int index, int L, int R, int position, int value) {
  if (L > position || R < position) {
    return; 
  }
  if (L == R) {
    it[index] = value;
    return; 
  }
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, position, value); 
  update(2 * index + 1, mid + 1, R, position, value); 
  it[index] = std::max(it[2 * index], it[2 * index + 1]); 
} 
int get(int index, int L, int R, int l, int r) {
  if (l > R || L > r) {
    return -200007; 
  }
  if (l <= L && R <= r) {
    return it[index];
  }
  int mid = (L + R) / 2; 
  int vLeft = get(2 * index, L, mid, l, r);
  int vRight = get(2 * index + 1, mid + 1, R, l, r); 
  return std::max(vLeft, vRight); 
}
void dfs(int u, int father) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs(v, u);
    f[u] = std::max(f[u], f[v] + 1); 
  }
}
void solve(int u, int father, int depth) {
  for (int i = 0; i < (int) listQuestions[u].size(); i++) {
    question q = listQuestions[u][i];
    int stamina = q.stamina;
    int id = q.id; 
    ans[id] = f[u];
    if (stamina > 0) {
      int r = depth - 1; 
      int l = std::max(1, depth - stamina);
      if (l <= r) {
        ans[id] = std::max(ans[id], depth + get(1, 1, n, l, r)); 
      } 
    } 
  }
  int numbChildren = (int) adj[u].size() - 1; 
  std::vector <int> pref(numbChildren + 10, 0), suf(numbChildren + 10, 0);
  int pos = 0; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    pos++; 
    pref[pos] = f[v] + 1; 
    suf[pos] = f[v] + 1; 
  }                                              
  for (int i = 1; i <= numbChildren; i++) {
    pref[i] = std::max(pref[i], pref[i - 1]); 
  }  
  for (int i = numbChildren; i >= 1; i--) {
    suf[i] = std::max(suf[i + 1], suf[i]); 
  }
  pos = 0; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    pos++; 
    update(1, 1, n, depth, std::max(pref[pos - 1], suf[pos + 1]) - depth);
    solve(v, u, depth + 1);
    update(1, 1, n, depth, 0);  
  }
}

int main () {
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      adj[i].clear(); 
      listQuestions[i].clear();
      f[i] = 0;  
    } 
    for (int i = 1; i <= 4 * n; i++) {
      it[i] = 0; 
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u); 
    }
    dfs(1, -1);                     
    std::cin >> numQueries; 
    for (int query = 1; query <= numQueries; query++) {
      int u, stamina;
      std::cin >> u >> stamina; 
      listQuestions[u].push_back((question) {stamina, query}); 
    }                               
    solve(1, -1, 1); 
    for (int query = 1; query <= numQueries; query++) {
      std::cout << ans[query] << ' '; 
    }
    std::cout << std::endl; 
  }
  return 0; 
}