#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;
const int MAX_N = 1005;
int N, numTest;
int a[MAX_N][MAX_N];
int b[MAX_N][MAX_N];
int checkRow[MAX_N];
int checkCol[MAX_N];
int root[MAX_N];
struct element {
  int u, v;
  int cost;
  bool operator < (const element &other) const {
    return cost < other.cost;
  }
};
vector <element> listEdge;

int findRoot(int u) {
  return (u == root[u] ? u : findRoot(root[u]));
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> N;
    listEdge.clear();
    int res = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> b[i][j];
      }
    }
    for (int i = 0; i < N; i++) {
      cin >> checkRow[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> checkCol[i];
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (a[i][j] == -1) {
          listEdge.push_back((element) {i, j + N, b[i][j]});
          res += b[i][j];
        }
      }
    }
    sort(listEdge.begin(), listEdge.end());
    reverse(listEdge.begin(), listEdge.end());
    for (int i = 0; i < 2 * N; i++) {
      root[i] = i;
    }
    for (int i = 0; i < (int) listEdge.size(); i++) {
      element e = listEdge[i];
      int u = e.u;
      int v = e.v;
      int cost = e.cost;
      int rootu = findRoot(u);
      int rootv = findRoot(v);
      if (rootu != rootv) {
        res -= cost;
        root[rootu] = rootv;
      }
    }
    cout << "Case #" << testCase << ": ";
    cout << res << endl;
  }
  return 0;
}