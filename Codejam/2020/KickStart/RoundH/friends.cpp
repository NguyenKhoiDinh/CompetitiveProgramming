#include <bits/stdc++.h>

using namespace std;
int numTest;
const int MAX_N = 50005; 
int dist[26][26];
int n, numQuery; 
string a[MAX_N];
int mask[MAX_N];
vector <int> group[26];
bool visited[26]; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> numQuery;
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        dist[i][j] = MAX_N;
      }
      dist[i][i] = 0; 
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      mask[i] = 0; 
      for (int j = 0; j < (int) a[i].size(); j++) {
        mask[i] |= (1 << (a[i][j] - 'A'));
      }
      for (int j = 0; j < 26; j++) {
        if ((mask[i] & (1 << j)) > 0) {
          for (int k = j + 1; k < 26; k++) {
            if ((mask[i] & (1 << k)) > 0) {
              dist[j][k] = dist[k][j] = 1; 
            }
          }
        }
      }
    }
    for (int k = 0; k < 26; k++) {
      for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    for (int query = 1; query <= numQuery; query++) {
      int u, v; 
      cin >> u >> v;
      int masku = mask[u];
      int maskv = mask[v];
      int ans = MAX_N;
      for (int i = 0; i < 26; i++) {
        if ((masku & (1 << i)) > 0) {
          for (int j = 0; j < 26; j++) {
            if ((maskv & (1 << j)) > 0) {
              ans = min(ans, 2 + dist[i][j]);
            }
          }
        }
      }
      cout << (ans == MAX_N ? -1 : ans) << ' ';
    }
    cout << endl; 
  }
  return 0;
}