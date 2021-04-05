#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 35;
int numTest;
string a[MAX_N];
int R, C;
bool adj[26][26];
int mark[26];
stack <int> st;
bool visited[26];
bool isCycle = false;

void dfs(int u) {
  mark[u] = 1;
  for (int v = 0; v < 26; v++) {
    if (adj[u][v] == true) {
      if (mark[v] == 1) {
        isCycle = true;
        return;
      }
      if (mark[v] == 0) {
        dfs(v);
      }
    }
  }
  mark[u] = 2;
}

void topo(int u) {
  visited[u] = true;
  for (int v = 0; v < 26; v++) {
    if (adj[u][v] == true && visited[v] == false) {
      topo(v);
    }
  }
  st.push(u);
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> R >> C;
    for (int c = 0; c < 26; c++) {
      mark[c] = 0;
      visited[c] = false;
    }
    for (int u = 0; u < 26; u++) {
      for (int v = 0; v < 26; v++) {
        adj[u][v] = false;
      }
    }
    set <int> S;
    for (int i = 0; i < R; i++) {
      cin >> a[i];
      for (int j = 0; j < C; j++) {
        S.insert(a[i][j] - 'A');
      }
    }
    for (int j = 0; j < C; j++) {
      for (int i = R - 1; i > 0; i--) {
        if (a[i][j] != a[i - 1][j]) {
          adj[a[i][j] - 'A'][a[i - 1][j] - 'A'] = true;
        }
      }
    }
    string ans = "";
    isCycle = false;
    for (int u = 0; u < 26; u++) {
      if (mark[u] == 0) {
        dfs(u);
        if (isCycle == true) {
          ans = "-1";
          break;
        }
      }
    }
    if (ans == "-1") {
      cout << ans << endl;
      continue;
    }
    for (set <int> :: iterator it = S.begin(); it != S.end(); it++) {
      int u = *it;
      if (visited[u] == false) {
        topo(u);
      }
    }
    while (!st.empty()) {
      ans += (char) (st.top() + 'A');
      st.pop();
    }
    cout << ans << endl;
  }
  return 0;
}