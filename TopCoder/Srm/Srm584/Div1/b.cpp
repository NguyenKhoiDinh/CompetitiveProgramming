#include <bits/stdc++.h>

using namespace std;
const int MAX_V = 100005;
const int MAX_N = 55;
int dep[MAX_V];
long long dp[2][MAX_N][MAX_N][MAX_N];
long long C[MAX_N][MAX_N];
bool check[MAX_N];
struct element {
  int type;
  int depth;
  bool operator < (const element &other) const {
    return (type < other.type || (type == other.type && depth < other.depth));
  }
};
vector <element> listBuilding;

void update(long long &a, long long value) {
  a += value;
}

class Excavations {
  public:
  long long count(vector <int> kind, vector <int> depth, vector <int> found, int K) {
    set <int> S;
    int n = (int) kind.size();
    int numDiff = (int) found.size();
    for (int i = 0; i < numDiff; i++) {
      check[found[i]] = true;
    }
    for (int i = 0; i <= n; i++) {
      C[i][0] = 1LL;
      C[i][i] = 1LL;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      }
    }
    for (int i = 0; i < n; i++) {
      S.insert(depth[i]);
    }
    int cnt = 0;
    for (set <int> :: iterator it = S.begin(); it != S.end(); it++) {
      int value = *it;
      cnt++;
      dep[value] = cnt;
    }
    for (int i = 0; i < n; i++) {
      listBuilding.push_back((element) {kind[i], dep[depth[i]]});
    }
    sort(listBuilding.begin(), listBuilding.end());
    sort(found.begin(), found.end());
    dp[0][0][0][0] = 1;
    for (int numBuild = 0; numBuild <= n; numBuild++) {
      int now = numBuild & 1;
      int nxt = !now;
      memset(dp[nxt], 0, sizeof(dp[nxt]));
      for (int numType = 0; numType <= numDiff; numType++) {
        for (int numChoose = 0; numChoose <= K; numChoose++) {
          for (int maxDepth = 0; maxDepth <= cnt; maxDepth++) {
            if (dp[now][numType][numChoose][maxDepth] == 0) {
              continue;
            }
            long long curValue = dp[now][numType][numChoose][maxDepth];
            update(dp[nxt][numType][numChoose][maxDepth], curValue);
            if (numType < numDiff && listBuilding[numBuild].type == found[numType]) {
              int newDepth = max(listBuilding[numBuild].depth, maxDepth);
              update(dp[nxt][numType + 1][numChoose + 1][newDepth], curValue);
            }
            if (numType > 0 && listBuilding[numBuild].type == found[numType - 1]) {
              int newDepth = maxDepth;
              update(dp[nxt][numType][numChoose + 1][newDepth], curValue);
            }
          }
        }
      }
    }
    long long ans = 0LL;
    for (int maxDepth = 1; maxDepth <= cnt; maxDepth++) {
      for (int numChoose = numDiff; numChoose <= K; numChoose++) {
        if (dp[n & 1][numDiff][numChoose][maxDepth] == 0) {
          continue;
        }
        int cntValids = 0;
        for (int i = 0; i < n; i++) {
          if (check[listBuilding[i].type] == false && listBuilding[i].depth > maxDepth) {
            cntValids++;
          }
        }
        cout << cntValids << ' ' << K << ' ' << numChoose << endl;
        if (K - numChoose > cntValids) {
          continue;
        }
        ans += dp[n & 1][numDiff][numChoose][maxDepth] * C[cntValids][K - numChoose];
      }
    }
    return ans;
  }
};

Excavations E;

int main () {
  freopen("output.txt", "w", stdout);
  cout << E.count({43, 45, 44, 43, 43, 10, 2, 9, 43, 45, 24, 32, 22, 11, 2},
  {11694, 13945, 22571, 13945, 96402, 46728, 46728, 30230, 18506, 25194, 96402, 61113, 46728, 13945, 32825},
  {11, 43},
  13
);
  return 0;
}