#include <iostream>
#include <vector>
#include <math.h>
#include <utility>
#include <algorithm>
#include <fstream>

using namespace std;
const int MAX_N = 50005;
struct edge {
  int u, v;
  long long value;
};
int numTest; 
long long IT[8 * MAX_N];
int n, numQuery; 
vector <int> adj[MAX_N]; 
vector <pair <int, int> > listQuery[4 * MAX_N];
vector <edge> listEdge[4 * MAX_N];
int TIME = 0;
int le[MAX_N], ri[MAX_N];
long long res[2 * MAX_N];
int parent[MAX_N];

void init() {
  for (int i = 1; i <= n; i++) {
    adj[i].clear(); 
  }
  for (int i = 1; i <= 8 * n; i++) {
    IT[i] = 0LL; 
  }
  for (int i = 1; i <= 200000; i++) {
    listQuery[i].clear(); 
    listEdge[i].clear(); 
  }
  for (int i = 1; i <= numQuery; i++) {
    res[i] = -1; 
  }
  TIME = 0;
}

void dfs(int u, int father) {
  parent[u] = father; 
  TIME++; 
  le[u] = TIME; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs(v, u); 
  }
  TIME++; 
  ri[u] = TIME;
}

void update(int index, int L, int R, int l, int r, long long value) {
  if (L > r || l > R) {
    return; 
  }
  if (l <= L && R <= r) {
    if (IT[index] == 0) {
      IT[index] = value; 
    }
    else {
      IT[index] = __gcd(IT[index], value);
    }
    return; 
  }
  int mid = (L + R) >> 1; 
  update(2 * index, L, mid, l, r, value);
  update(2 * index + 1, mid + 1, R, l, r, value);
}

long long query(int index, int L, int R, int pos) {
  if (L == R) {
    return IT[index]; 
  }
  int mid = (L + R) >> 1; 
  if (pos <= mid) {
    return __gcd(IT[index], query(2 * index, L, mid, pos));
  }
  else {
    return __gcd(IT[index], query(2 * index + 1, mid + 1, R, pos));
  }
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> numQuery;  
    init(); 
    for (int i = 1; i < n; i++) {
      int u, v, L;
      long long A; 
      cin >> u >> v >> L >> A; 
      adj[u].push_back(v); 
      adj[v].push_back(u); 
      listEdge[L].push_back((edge) {u, v, A}); 
    }
    for (int i = 1; i <= numQuery; i++) {
      int u, W;
      cin >> u >> W; 
      listQuery[W].push_back(make_pair(u, i)); 
    }
    dfs(1, -1);
    for (int i = 1; i <= 200000; i++) {
      for (int j = 0; j < (int) listEdge[i].size(); j++) {
        const edge e = listEdge[i][j]; 
        int u = e.u; 
        int v = e.v; 
        long long value = e.value;
        if (parent[v] != u) {
          swap(u, v); 
        }
        update(1, 1, TIME, le[v], ri[v], value); 
      }
      for (int j = 0; j < (int) listQuery[i].size(); j++) {
        const pair <int, int> q = listQuery[i][j]; 
        int u = q.first;
        int pos = q.second;
        long long gcd = query(1, 1, TIME, le[u]);
        res[pos] = gcd; 
      }
    }
    for (int i = 1; i <= numQuery; i++) {
      cout << res[i] << ' ';
    }
    cout << endl; 
  }
  return 0;
}