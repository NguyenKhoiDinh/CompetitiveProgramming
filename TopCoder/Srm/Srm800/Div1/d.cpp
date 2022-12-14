#include <bits/stdc++.h>

using namespace std;
const long long MOD = 998244353;
const int MAX_N = 55;

map <vector <int>, long long> dp[MAX_N];

class MaxOfMin {
  public:
  int count(vector <int> F) {
    int n = (int) F.size();
    if (F[0] != n || F.back() != 1) {
      return 0;
    }
    for (int i = 1; i < n; i++) {
      if (F[i - 1] < F[i]) {
        return 0;
      }
    }
    vector <int> state;
    state.push_back(n);
    int longestEmpty = -1;
    dp[0][state] = 1;
    for (int v = 0; v < n; v++) {
      for (map <vector <int>, long long> :: iterator it = dp[v].begin(); it != dp[v].end(); it++) {
        vector <int> curState = it->first;
        long long curVal = it->second;
        for (int i = 0; i < n; i++) {
          if (F[i] == v + 1) {
            longestEmpty = i;
            break;
          }
        }
        for (int i = 0; i < (int) curState.size(); i++) {
          for (int j = 1; j <= curState[i]; j++) {
            vector <int> nextState = curState;
            nextState[i] = 0;
            nextState.push_back(j - 1);
            nextState.push_back(curState[i] - j);
            sort(nextState.begin(), nextState.end());
            reverse(nextState.begin(), nextState.end());
            while (!nextState.empty() && nextState.back() == 0) {
              nextState.pop_back();
            }
            reverse(nextState.begin(), nextState.end());
            if (!nextState.empty() && nextState.back() != longestEmpty) {
              continue;
            }
            (dp[v + 1][nextState] += curVal) %= MOD;
          }
        }
      }                         
    }
    state.clear();
    return (int) dp[n][state];
  }
};

MaxOfMin M;

int main () {
  cout << M.count({6, 5, 2, 1, 1, 1});
  return 0;
}