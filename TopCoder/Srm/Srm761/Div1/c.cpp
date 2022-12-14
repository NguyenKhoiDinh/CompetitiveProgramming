#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 15;
const int MAX_EDGE = 205;
const int MOD = 1000000007;
int numEdges[(1 << MAX_N) + 5];
int dp[(1 << MAX_N) + 5][MAX_EDGE];
int C[MAX_EDGE][MAX_EDGE];
int ways[MAX_EDGE][MAX_EDGE];

void init() {
  for (int i = 0; i < MAX_EDGE; i++) {
    C[i][0] = 1;
    C[i][i] = 1;
  }
  for (int i = 1; i < MAX_EDGE; i++) {
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }
}

class SpanningSubgraphs {
  public:
  vector <int> count(int n, vector <int> a, vector <int> b) {
    init();
    int m = (int) a.size();
    vector <int> ans;
    for (int mask = 1; mask < (1 << n); mask++) {
      for (int i = 0; i < m; i++) {
        if (((mask & (1 << a[i])) > 0) && ((mask & (1 << b[i])) > 0)) {
          numEdges[mask]++;
        }
      }
    }
    for (int mask = 1; mask < (1 << n); mask++) {
      int numVerticles = (int) __builtin_popcount(mask);
      int chosenVerticle = -1;
      for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) > 0) {
          chosenVerticle = i;
          break;
        }
      }
//      for (int j = numVerticles - 1; j <= numEdges[mask]; j++) {
//        dp[mask][j] = C[numEdges[mask]][j];
//        for (int subMask = (mask - 1) & mask; subMask > 0; subMask = (subMask - 1) & mask) {
//          if ((subMask & (1 << chosenVerticle)) == 0) {
//            continue;
//          }
//          for (int subEdge = 0; subEdge <= j; subEdge++) {
//            dp[mask][j] -= (1LL * dp[subMask][subEdge] * C[numEdges[mask - subMask]][j - subEdge]) % MOD;
//            if (dp[mask][j] < 0) {
//              dp[mask][j] += MOD;
//            }
//          }
//
//        }
//      }
      for (int edges = 0; edges <= numEdges[mask]; edges++) {
        for (int j = 0; j <= numEdges[mask]; j++) {
          ways[edges][j] = 0;
        }
      }
      for (int subMask = (mask - 1) & mask; subMask > 0; subMask = (subMask - 1) & mask) {
        if ((subMask & (1 << chosenVerticle)) == 0) {
          continue;
        }
        for (int j = 0; j <= numEdges[subMask]; j++) {
          (ways[numEdges[mask - subMask]][j] += dp[subMask][j]) %= MOD;
        }
      }
      for (int i = numEdges[mask] - 1; i >= 0; i--) {
        for (int j = 0; j < numEdges[mask]; j++) {
          (ways[i][j] += ways[i + 1][j]) %= MOD;
          (ways[i][j + 1] += ways[i + 1][j]) %= MOD;
        }
      }
      for (int e = numVerticles - 1; e <= numEdges[mask]; e++) {
        dp[mask][e] = C[numEdges[mask]][e];
//        for (int edges = 0; edges <= numEdges[mask]; edges++) {
//          for (int j = 0; j <= e; j++) {
//            dp[mask][e] -= (1LL * ways[edges][j] * C[edges][e - j]) % MOD;
//            if (dp[mask][e] < 0) {
//              dp[mask][e] += MOD;
//            }
//          }
//        }
        dp[mask][e] -= ways[0][e];
        if (dp[mask][e] < 0) {
          dp[mask][e] += MOD;
        }
      }
    }
    for (int j = n - 1; j <= m; j++) {
      ans.push_back(dp[(1 << n) - 1][j]);
    }
    return ans;
  }
};

SpanningSubgraphs S;

int main () {
  freopen("output.txt", "w", stdout);
  vector <int> ans = S.count(7,{0,0,0,1,1,1,1,1,2,2,3,3,3,3,3,3,4,4,5},
  {0,5,6,2,2,2,6,6,3,6,4,4,5,5,6,6,5,5,6});
//vector <int> ans = S.count(15,
//{7,3,8,2,5,8,5,11,8,3,10,8,6,6,8,8,3,9,4,6,4,6,1,1,5,4,
//0,9,4,7,6,0,6,2,2,6,11,4,6,10,9,2,6,0,4,7,6,8,1,3,11,3,
//4,8,1,0,12,9,5,14,0,13,7,14,7,9,6,7,8,8,8,4,14,1,13,5,
//1,6,13,14,0,4,8,5,13,7,2,10,10,11,8,2,4,13,12,10,5,13,
//5,9,6,4,1,11,4,13,6,4,8,8,11,1,14,10,3,1,2,0,10,5,9,5,
//10,8,4,2,5,12,7,2,3,2,4,6,9,3,7,9,2,14,14,0,14,3,12,12,
//0,11,7,8,6,6,0,10,7,2,0,7,8,10,3,11,11,7,0,0,11,8,6,11,
//13,4,11,11,8,5,13,11,9,14,10,1,12,12,3,3,0,13,13,6,2,9,
//1,4,2,7,14,5},
//{12,8,1,11,1,6,12,3,7,5,1,1,11,11,9,0,7,9,12,8,13,13,11,
//0,2,14,12,12,13,10,13,12,2,14,11,13,14,3,12,14,11,5,3,0,
//9,0,1,10,5,11,6,6,1,4,0,12,13,1,4,10,9,8,3,4,13,3,10,7,
//3,2,13,0,1,13,7,3,3,9,9,10,9,9,0,13,12,3,14,4,1,7,5,0,0,
//11,13,0,0,14,13,5,5,0,10,0,3,8,13,4,6,7,4,0,6,7,8,10,7,
//4,6,13,0,6,3,2,11,8,7,12,0,14,12,6,10,8,6,9,2,4,14,9,4,
//6,3,11,12,8,7,12,14,0,10,11,9,7,4,6,12,13,7,4,13,9,7,13,
//2,4,7,6,2,0,10,7,8,13,1,14,13,3,12,14,2,4,6,7,10,11,8,4,
//10,13,14,9,0,5,3,0,7,11});
for (int i = 0; i < (int) ans.size(); i++) {
  cout << ans[i] << "   ";
}
  return 0;
}