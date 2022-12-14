#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 500005;
int numTest;
vector <int> adj[MAX_N];
int cntNodesA[MAX_N], cntNodesB[MAX_N];
int cntLenA[MAX_N], cntLenB[MAX_N];
int n, A, B;

void dfsA(int u, int depth) {
  cntNodesA[u] -= cntLenA[depth % A];
  cntLenA[depth % A]++;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    dfsA(v, depth + 1);
  }
  cntNodesA[u] += cntLenA[depth % A];
}

void dfsB(int u, int depth) {
  cntNodesB[u] -= cntLenB[depth % B];
  cntLenB[depth % B]++;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    dfsB(v, depth + 1);
  }
  cntNodesB[u] += cntLenB[depth % B];
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> A >> B;
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      cntNodesA[i] = 0;
      cntNodesB[i] = 0;
      cntLenA[i] = 0;
      cntLenB[i] = 0;
    }
    for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      adj[p].push_back(i);
    }
    dfsA(1, 0);
    dfsB(1, 0);
    double ans = 0.0;
    for (int u = 1; u <= n; u++) {
      double probA = 1.0 * cntNodesA[u] / n;
      double probB = 1.0 * cntNodesB[u] / n;
      double prob = probA + probB - probA * probB;
      ans += prob;
    }
    cout << fixed << setprecision(10) << ans << endl;
  }
  return 0;
}