#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 53;
const long long MOD = 1000000007;
long long dp[MAX_N][MAX_N][MAX_N][MAX_N][2];
struct node {
  int left, right;
};
int father[MAX_N];
int numNodes[MAX_N];
int unFilled[MAX_N];
int state[MAX_N];
int numFilled[MAX_N];
int pathLength[MAX_N];
int turnRight[MAX_N][MAX_N];
int turnLeft[MAX_N][MAX_N];
int cntCanNotFind[MAX_N];
bool isLeaf[MAX_N];
node adj[MAX_N];
long long fact[MAX_N];
long long C[MAX_N][MAX_N];
int commonAncestor[MAX_N][MAX_N];
int onRight[MAX_N];
vector <int> node;

void init() {
  fact[0] = 1LL;
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  for (int i = 0; i < MAX_N; i++) {
    C[i][0] = 1;
    C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }
}

int lca(int u, int v) {
  vector <int> parentu;
  vector <int> parentv;
  while (u != -1) {
    parentu.push_back(u);
    u = father[u];
  }
  while (v != -1) {
    parentv.push_back(v);
    v = father[v];
  }
  for (int i = 0; i < (int) parentu.size(); i++) {
    for (int j = 0; j < (int) parentv.size(); j++) {
      if (parentu[i] == parentv[j]) {
        return parentu[i];
      }
    }
  }
}

void findLowestCommonAncestor() {
  for (int i = 0; i < (int) node.size() - 1; i++) {
    for (int j = i + 1; j < (int) node.size(); j++) {
      int u = node[i];
      int v = node[j];
      commonAncestor[u][v] = commonAncestor[v][u] = lca(u, v);
    }
  }
}

void buildLeftAndRight() {
  for (int i = 0; i < (int) node.size(); i++) {
    int u = node[i];
    turnLeft[u][u] = 0;
    turnRight[u][u] = 0;
    int p = u;
    while (true) {
      int parent = father[p];
      if (parent == -1) {
        break;
      }
      if (adj[parent].left == p) {
        turnLeft[u][parent] = turnLeft[u][p] + 1;
        turnRight[u][parent] = turnRight[u][p];
      }
      else {
        turnLeft[u][parent] = turnLeft[u][p];
        turnRight[u][parent] = turnRight[u][p] + 1;
      }
      p = parent;
    }
  }
}

void buildBinaryTree(int l, int r, int parent) {
  int mid = (l + r) >> 1;
  numNodes[mid] = 1;
  father[mid] = parent;
  adj[mid].left = -1;
  adj[mid].right = -1;
  if (l == r) {
    isLeaf[mid] = true;
    node.push_back(mid);
    return;
  }
  if (l <= mid - 1) {
    int left = (l + mid - 1) >> 1;
    unFilled[left] += unFilled[mid];
    pathLength[left] = pathLength[mid] + 1;
    buildBinaryTree(l, mid - 1, mid);
    numNodes[mid] += numNodes[left];
    state[left] = 0;
    adj[mid].left = left;
  }
  if (mid + 1 <= r) {
    int right = (mid + 1 + r) >> 1;
    unFilled[right] += unFilled[mid];
    if (l <= mid - 1) {
      int left = (l + mid - 1) >> 1;
      unFilled[right] += numNodes[left];
    }
    pathLength[right] = pathLength[mid] + 1;
    if (adj[mid].left == -1) {
      onRight[right] = 1;
      node.push_back(mid);
    }
    buildBinaryTree(mid + 1, r, mid);
    numNodes[mid] += numNodes[right];
    state[right] = 1;
    adj[mid].right = right;
  }
}

void add(long long &a, long long val) {
  (a += val) %= MOD;
}

void mul(long long &a, long long val) {
  (a *= val) %= MOD;
}

void DynamicProgramming(const string &s) {
  int n = (int) s.size();
  cntCanNotFind[0] = 0;
  for (int i = 1; i <= n; i++) {
    cntCanNotFind[i] = cntCanNotFind[i - 1];
    if (s[i - 1] == '0') {
      cntCanNotFind[i]++;
    }
  }
  dp[0][1][0][0][0] = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < (int) node.size(); j++) {
      int endNode = node[j];
      for (int ignore = 0; ignore <= n; ignore++) {
        for (int unFill = 0; unFill <= n; unFill++) {
          for (int isFilled = 0; isFilled <= 1; isFilled++) {
            if (dp[i][endNode][ignore][unFill][isFilled] == 0) {
              continue;
            }
            long long cur = dp[i][endNode][ignore][unFill][isFilled];
            if (s[i] == '0') {
              add(dp[i + 1][endNode][ignore][unFill + 1][isFilled], cur);
              if (ignore > 0) {
                long long val = cur;
                mul(val, 1LL * ignore);
                add(dp[i + 1][endNode][ignore - 1][unFill][isFilled], val);
              }
            }
            else {
              if (isFilled == 0) {
                if (isLeaf[endNode] == true) {
                  add(dp[i + 1][endNode][ignore][unFill][1], cur);
                }
                else {
                  add(dp[i + 1][adj[endNode].right][ignore][unFill][0], cur);
                  if (unFill > 0) {
                    long long val = cur;
                    mul(val, 1LL * unFill);
                    add(dp[i + 1][adj[endNode].right][ignore][unFill - 1][1], val);
                  }
                }
              }
              for (int jj = j + 1; jj < (int) node.size(); jj++) {
                int nxtNode = node[jj];
                if (adj[endNode].right == nxtNode) {
                  continue;
                }
                int lowestParent = commonAncestor[endNode][nxtNode];
                int cntFillNode = turnRight[nxtNode][lowestParent] - 1;
                int cntIgnoreNode = turnLeft[endNode][lowestParent];
                if (endNode != lowestParent) {
                  cntIgnoreNode--;
                  cntIgnoreNode += (1 - isFilled);
                }
                if (unFill >= cntFillNode) {
                  long long val = cur;
                  mul(val, fact[cntFillNode]);
                  mul(val, C[unFill][cntFillNode]);
                  add(dp[i + 1][nxtNode][ignore + cntIgnoreNode][unFill - cntFillNode][0], val);
                }
                if (unFill >= cntFillNode + 1 && isLeaf[nxtNode] == true) {
                  long long val = cur;
                  mul(val, fact[cntFillNode + 1]);
                  mul(val, C[unFill][cntFillNode + 1]);
                  add(dp[i + 1][nxtNode][ignore + cntIgnoreNode][unFill - cntFillNode - 1][1], val);
                }
              }
            }
          }
        }
      }
    }
  }
}

class BinarySearch {
  public:
  int count(string status) {
    if (status == "0") {
      return 0;
    }
    else if (status == "1") {
      return 1;
    }
    int n = (int) status.size();
    pathLength[(1 + n) / 2] = 1;
    buildBinaryTree(1, n, -1);
    init();
    buildLeftAndRight();
    findLowestCommonAncestor();
    DynamicProgramming(status);
    long long res = 0LL;
    for (int unFill = 0; unFill <= n; unFill++) {
      if (dp[n][n][0][unFill][1] > 0) {
        long long cur = dp[n][n][0][unFill][1];
        mul(cur, fact[unFill]);
        add(res, cur);
      }
    }
    return (int) res;
    return 0;
  }
};