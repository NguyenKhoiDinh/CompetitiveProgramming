#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1005; 
vector <int> adj[MAX_N];
int n;
int a[MAX_N][MAX_N];
bitset <1005> have[MAX_N], unhave[MAX_N];

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]); 
      if (a[i][j] == 1){
        adj[i].push_back(j);
        have[i].set(j);
        unhave[j].set(i);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int) adj[i].size(); j++) {
      int u = adj[i][j];
      bitset <1005> tmp = have[u] & unhave[i]; 
      if (tmp.count() == 0) {
        continue; 
      }
      for (int k = 1; k <= n; k++) {
        if (tmp[k] == 1) {
          printf("%d %d %d", i, u, k);
          return 0;
        }
      }
    }
  }
  printf("-1 -1 -1");
  return 0; 
}