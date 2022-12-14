#include <bits/stdc++.h>

using namespace std;

int calculate(const vector <int> &a) {
  vector <int> dp;
  int n = (int) a.size();
  dp.resize(n + 5, 0);
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    if (i >= 2) {
      dp[i] = max(dp[i], dp[i - 2] + a[i - 1]);
    }
  }
  return dp[n];
}

class BadNeighbors {
  public:
  int maxDonations(vector <int> donations) {
    vector <int> donate1, donate2;
    for (int i = 0; i < (int) donations.size() - 1; i++) {
      donate1.push_back(donations[i]);
      donate2.push_back(donations[i + 1]);
    }
    int res = max(calculate(donate1), calculate(donate2));
    return res;
  }
};

int main () {
  return 0;
}