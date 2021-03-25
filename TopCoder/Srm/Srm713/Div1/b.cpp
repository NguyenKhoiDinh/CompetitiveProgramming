#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 14;
vector <int> listMask[MAX_N + 3][(1 << MAX_N) + 4];
long long dp[MAX_N + 3][(1 << MAX_N) + 4];
bool mark[MAX_N + 3];
int submask = 0;
long long fact[MAX_N + 3];

void dfs(int u, vector <string> &adj) {
  mark[u] = true;
  submask |= (1 << u);
  for (int i = 0; i < (int) adj.size(); i++) {
    if (adj[u][i] == 'Y' && mark[i] == false) {
      dfs(i, adj);
    }
  }
}

class DFSCountEasy {
  public:
  long long count(vector <string> G) {
    int n = (int) G.size();
    for (int mask = 1; mask < (1 << n); mask++) {
      for (int u = 0; u < n; u++) {
        if ((mask & (1 << u)) > 0) {
          for (int v = 0; v < n; v++) {
            if ((mask & (1 << v)) > 0) {
              mark[v] = true;
            }
            else {
              mark[v] = false;
            }
          }
          for (int v = 0; v < n; v++) {
            if (G[u][v] == 'Y' && mark[v] == false) {
              submask = 0;
              dfs(v, G);
              listMask[u][mask].push_back(submask);
            }
          }
        }
      }
    }
    fact[0] = 1LL;
    for (int i = 1; i <= n; i++) {
      fact[i] = fact[i - 1] * i;
    }
    int all = (1 << n) - 1;
    for (int u = 0; u < n; u++) {
      dp[u][0] = 1;
    }
    for (int mask = 1; mask <= all; mask++) {
      for (int u = 0; u < n; u++) {
        if ((mask & (1 << u)) == 0) {
          int visited = all ^ mask;
          vector <int> &save = listMask[u][visited];
          dp[u][mask] = fact[(int) save.size()];
          for (int i = 0; i < (int) save.size(); i++) {
            int submask = save[i];
            long long sum = 0LL;
            for (int v = 0; v < n; v++) {
              if (G[u][v] == 'Y' && (submask & (1 << v)) > 0) {
                sum += dp[v][submask - (1 << v)];
              }
            }
            dp[u][mask] *= sum;
          }
        }
      }
    }
    long long res = 0LL;
    for (int u = 0; u < n; u++) {
      res += dp[u][all - (1 << u)];
    }
    return res;
  }
};

DFSCountEasy D;

int main () {
  cout << D.count({"NYYYYYYYYYYYY",
 "YNYYYYYYYYYYY",
 "YYNYYYYYYYYYY",
 "YYYNYYYYYYYYY",
 "YYYYNYYYYYYYY",
 "YYYYYNYYYYYYY",
 "YYYYYYNYYYYYY",
 "YYYYYYYNYYYYY",
 "YYYYYYYYNYYYY",
 "YYYYYYYYYNYYY",
 "YYYYYYYYYYNYY",
 "YYYYYYYYYYYNY",
 "YYYYYYYYYYYYN"});
  return 0;
}