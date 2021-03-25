#include <iostream>
#include <vector>
#include <bitset>
#include <fstream>

using namespace std;
const int MAX_N = 10005;
vector <int> adj[MAX_N];
bitset <MAX_N> setAdj[MAX_N];
int n, m;

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    setAdj[u].set(v);
    setAdj[v].set(u);
  }
  for (int fi = 1; fi <= n; fi++) {
    for (int i = 0; i < (int) adj[fi].size(); i++) {
      int se = adj[fi][i];
      for (int j = 0; j < (int) adj[se].size(); j++) {
        int th = adj[se][j];
        if (th != fi) {
          bitset <MAX_N> firstSet = setAdj[fi], thirdSet = setAdj[th];
          bitset <MAX_N> overlap = firstSet & thirdSet;
          if (overlap.count() <= 1) {
            continue;
          }
          for (int fo = 1; fo <= n; fo++) {
            if (overlap[fo] == 1 && fo != se) {
              cout << fi << ' ' << se << ' ' << th << ' ' << fo;
              return 0;
            }
          }
        }
      }
    }
  }
  cout << -1;
  return 0;
}