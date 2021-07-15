#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_N = 200005;

struct edge {
  int u, v, w;
  bool operator < (const edge &hs) const {
    return w < hs.w;
  }
};
vector <edge> listEdge;
int numTest, n, m;
int root[MAX_N];
map <int, vector <int> > M;

int findRoot(int u) {
  return (root[u] = (root[u] == u ? u : findRoot(root[u])));
}

void unionSet(int u, int v) {
  int rootu = findRoot(u);
  int rootv = findRoot(v);
  if (rootu != rootv) {
    root[rootv] = rootu;
  }
}

int main () {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    listEdge.clear();
    M.clear();
    for (int i = 1; i <= n; i++) {
      root[i] = i;
    }
    for (int i = 1; i <= m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      listEdge.push_back((edge) {u, v, w});
      M[w].push_back(i);
    }
    int numEdges = 0;
    vector <int> ans;
    for (map <int, vector <int> >::iterator it = M.begin(); it != M.end(); it++) {
      vector <int> edgePos = it->second;
      vector <int> acceptedEdges;
      for (int i = 0; i < (int) edgePos.size(); i++) {
        int pos = edgePos[i] - 1;
        edge e = listEdge[pos];
        if (findRoot(e.u) != findRoot(e.v)) {
          acceptedEdges.push_back(pos + 1);
        }
      }
      for (int i = 0; i < (int) acceptedEdges.size(); i++) {
        edge e = listEdge[acceptedEdges[i] - 1];
        if (findRoot(e.u) != findRoot(e.v)) {
          numEdges++;
          unionSet(e.u, e.v);
        }
        else {
          ans.push_back(acceptedEdges[i]);
        }
      }
    }
    if (numEdges != n - 1) {
      cout << -1 << endl;
    }
    else {
      cout << (int) ans.size() << ' ';
      for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}