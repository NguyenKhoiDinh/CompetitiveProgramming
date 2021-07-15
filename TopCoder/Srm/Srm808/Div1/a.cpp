#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 55; 
const int inf = 10005;  

int p[MAX_N][MAX_N];
int F[MAX_N][MAX_N];
int S[MAX_N][MAX_N];
vector <int> adj[MAX_N];
bool visited[MAX_N];

void dfs(int u) {
  visited[u] = true;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == false) {
      dfs(v);
    }
  }
}

class IOIVoting {
  public:
  vector <int> winners(int N, vector <int> votes) {
    vector <int> ans;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        p[i][j] = votes[i * N + j];
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (p[i][j] > p[j][i]) {
          F[i][j] = p[i][j] - p[j][i];
        }
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i != j) {
          int l = 1; 
          int r = inf;
          while (l <= r) {
            int mid = (l + r) >> 1;
            for (int k = 0; k < N; k++) {
              adj[k].clear();
              visited[k] = false;
            }
            for (int x = 0; x < N; x++) {
              for (int y = 0; y < N; y++) {
                if (F[x][y] >= mid) {
                  adj[x].push_back(y);
                }
              }
            }
            dfs(i);
            if (visited[j] == true) {
              S[i][j] = mid;
              l = mid + 1;
            }
            else {
              r = mid - 1;
            }
          }
        }
      }
    }
    for (int i = 0; i < N; i++) {
      bool flag = true;
      for (int j = 0; j < N; j++) {
        int first = (S[i][j] == inf ? -1 : S[i][j]);
        int second = (S[j][i] == inf ? -1 : S[j][i]);
        if (first < second) {
          flag = false;
          break;
        }
      }
      if (flag == true) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};

IOIVoting I;

int main () {
  vector <int> ans = I.winners(4,
{0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0});
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << "   ";
  }
  return 0;
}