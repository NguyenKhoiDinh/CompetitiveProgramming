#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 10005; 
const int MAX_V = 30005; 
pair <int, int> a[MAX_N];
int dp[MAX_V];
int n; 
vector <int> save[MAX_V];

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second; 
    save[a[i].second].push_back(i);
  }
  dp[0] = 0; 
  int res = 0;
  for (int i = 1; i < MAX_V; i++) {
    dp[i] = dp[i - 1];
    for (int j = 0; j < (int) save[i].size(); j++) {
      pair <int, int> pr = a[save[i][j]]; 
      dp[i] = max(dp[i], dp[pr.first] + pr.second - pr.first);
    } 
    res = max(res, dp[i]);
  }
  cout << res;
  return 0; 
}