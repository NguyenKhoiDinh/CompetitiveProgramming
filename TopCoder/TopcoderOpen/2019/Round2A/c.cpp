#include <bits/stdc++.h>

using namespace std;
const int MAX_V = 1027;
const int MAX_N = 53;
int sg[MAX_V];
int dp[MAX_V][MAX_V];

void DynamicProgramming() {
  dp[0][0] = 1;
  for (int i = 1; i <= 300; i++) {
    vector <int> listGrundy;
    for (int j = 1; j <= i; j++) {
      listGrundy.push_back(sg[i - j]);
    }
    for (int grundy = 0; grundy < MAX_V; grundy++) {
      if (dp[i][grundy] == 1) {
        continue;
      }
      for (int j = 1; j < i; j++) {
        if (dp[i - j][grundy ^ sg[j]] == 1) {
          dp[i][grundy] = 1;
          listGrundy.push_back(grundy);
        }
      }
    }
    listGrundy.push_back(-1);
    listGrundy.push_back(MAX_V + 100);
    sort(listGrundy.begin(), listGrundy.end());
    for (int j = 1; j < (int) listGrundy.size(); j++) {
      if (listGrundy[j] - listGrundy[j - 1] > 1) {
        sg[i] = listGrundy[j - 1] + 1;
        dp[i][sg[i]] = 1;
        break;
      }
    }
  }
}

class YetAnotherTokenGame {
  public:
  string getWinner(vector <int> piles) {
    DynamicProgramming();
    int n = (int) piles.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans ^= sg[piles[i]];
    }
    if (ans > 0) {
      return "William";
    }
    else {
      return "Xenia";
    }
  }
};