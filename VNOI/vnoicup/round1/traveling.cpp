#include <bits/stdc++.h>
using namespace std; 
const int mod = 1000000007; 
int dp_none_accepted[(1 << 20) + 5][23], dp_none_deny[(1 << 20) + 5][23], dp_none_accepted_nor_deny[(1 << 20) + 5][23]; 
int none_accepted[100005], none_deny[100005];                                                  
int n, m; 
int pw2[100005]; 

void sos(int dp[(1 << 20) + 5][23]) {
  for (int i = 1; i <= m; i++) {
    for (int mask = 0; mask < (1 << m); mask++) {
      if ((mask & (1 << (i - 1))) == 0) {
        dp[mask][i] += dp[mask][i - 1] + dp[mask + (1 << (i - 1))][i - 1]; 
      }
      else {
        dp[mask][i] += dp[mask][i - 1];  
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  std::cin >> n >> m;
  pw2[0] = 1LL;
  for (int i = 1; i <= n; i++) {
    pw2[i] = (2LL * pw2[i - 1]) % mod;
  }
  for (int i = 1; i <= n; i++) {
    none_accepted[i] = (1 << m) - 1; 
    none_deny[i] = (1 << m) - 1; 
  }
  for (int j = 0; j < m; j++) {
    int cnt;
    std::cin >> cnt; 
    for (int k = 1; k <= cnt; k++) {
      int people;
      std::cin >> people;
      if (people > 0) {
        none_accepted[people] -= (1 << j); 
      }    
      else {
        none_deny[-people] -= (1 << j); 
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    dp_none_accepted[none_accepted[i]][0]++; 
    dp_none_deny[none_deny[i]][0]++;
    dp_none_accepted_nor_deny[none_accepted[i] & none_deny[i]][0]++;  
  }
  sos(dp_none_accepted);
  sos(dp_none_deny);
  sos(dp_none_accepted_nor_deny);
  int ans = pw2[n];
  for (int mask = 1; mask < (1 << m); mask++) {   
    int accepted = n - dp_none_accepted[mask][m]; 
    int deny = n - dp_none_deny[mask][m]; 
    int accepted_or_deny = n - dp_none_accepted_nor_deny[mask][m];          
    int common = accepted + deny - accepted_or_deny; 
    if (common == 0) {
      int cnt = __builtin_popcount(mask); 
      if (cnt % 2 == 1) {
        ans = (ans - pw2[n - accepted - deny] + mod) % mod; 
      }
      else {
        ans = (ans + pw2[n - accepted - deny]) % mod; 
      }
    }
  }
  std::cout << ans; 
  return 0;          
}