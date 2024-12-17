#include <bits/stdc++.h> 

using namespace std;
int n, m;
vector <int> group[200005];  

int main () {
  std::ios_base::sync_with_stdio(false);
  cin >> n >> m; 
  for (int i = 1; i <= m; i++) {
    int cnt;
    cin >> cnt; 
    for (int j = 1; j <= cnt; j++) {
      int member; 
      cin >> member; 
      group[member].push_back(cnt); 
    }
  }
  double ans = -1.0; 
  for (int u = 1; u <= n; u++) {
    double minProb = 1.0 * (group[u][0] - 1) / group[u][0]; 
    for (int i = 1; i < (int) group[u].size(); i++) {
      minProb = min(minProb, 1.0 * (group[u][i] - 1) / group[u][i]);  
    }
    ans = max(ans, minProb); 
  }
  cout << fixed << setprecision(12) << ans;
  return 0; 
}