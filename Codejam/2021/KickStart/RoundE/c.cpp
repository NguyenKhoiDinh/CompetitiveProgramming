#include <bits/stdc++.h>

using namespace std;
int numTest; 
string s[1005];
int n, m, ans = 0;
vector <pair <int, int> > adj[1005][1005];
bool visited[1005][1005];

void dfs(int x, int y, char c) {
  if (s[x][y] == '.') {
    s[x][y] = c;
    ans++;
  }
  visited[x][y] = true;
  for (int i = 0; i < (int) adj[x][y].size(); i++) {
    int nextx = adj[x][y][i].first;
    int nexty = adj[x][y][i].second;
    if (visited[nextx][nexty] == false) {
      dfs(nextx, nexty, c);
    }
  }
}

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
      s[i] = '#' + s[i];
      s[i] += '#';
    }
    s[0] = "";
    s[n + 1] = "";
    for (int j = 0; j <= m + 1; j++) {
      s[0] += '#';
      s[n + 1] += '#';
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        visited[i][j] = false;
        adj[i][j].clear();
      }
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
      vector <int> col;
      for (int j = 0; j <= m + 1; j++) {
        if (s[i][j] == '#') {
          col.push_back(j);
        }
      }
      for (int k = 1; k < (int) col.size(); k++) {
        int l = col[k - 1] + 1;
        int r = col[k] - 1;
        while (l < r) {
          adj[i][l].push_back(make_pair(i, r));
          adj[i][r].push_back(make_pair(i, l));
          l++;
          r--;
        }
      }
    }
    for (int j = 1; j <= m; j++) {
      vector <int> row;
      for (int i = 0; i <= n + 1; i++) {
        if (s[i][j] == '#') {
          row.push_back(i);
        }
      }
      for (int k = 1; k < (int) row.size(); k++) {
        int l = row[k - 1] + 1;
        int r = row[k] - 1;
        while (l < r) {
          adj[l][j].push_back(make_pair(r, j));
          adj[r][j].push_back(make_pair(l, j));
          l++;
          r--;
        }                     
      }
    }            
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s[i][j] != '.' && visited[i][j] == false) {
          dfs(i, j, s[i][j]);   
        }
      }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << s[i][j];
      } 
      cout << endl;
    }
  }
  return 0;
}                          
