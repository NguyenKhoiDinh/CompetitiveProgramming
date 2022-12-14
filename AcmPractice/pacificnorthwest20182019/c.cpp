#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 1005;
const long long MOD = 998244353LL;
map <int, int> group;
int n, k;
vector <int> save;
long long dp[MAX_N][MAX_N];

int main () {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int difficult;
    cin >> difficult;
    group[difficult]++;
  }
  for (map <int, int> :: iterator it = group.begin(); it != group.end(); it++) {
    save.push_back(it->second);
  }
  if (k > (int) save.size()) {
    cout << 0;
    return 0;
  }
  dp[0][0] = 1;
  int sz = (int) save.size();
  for (int i = 0; i < sz; i++) {
    for (int numChoose = 0; numChoose <= k; numChoose++) {
      if (dp[i][numChoose] == 0) {
        continue;
      }
      (dp[i + 1][numChoose] += dp[i][numChoose]) %= MOD;
      if (numChoose < k) {
        (dp[i + 1][numChoose + 1] += (dp[i][numChoose] * 1LL * save[i]) % MOD) %= MOD;
      }
    }
  }
  cout << dp[sz][k];
  return 0; 
}