#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 105; 
bool dp[2][1000005];
int numTest;
int n, U, M;
int w[10005]; 
int cnt[105]; 

int main () {
  scanf("%d", &numTest); 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    scanf("%d %d %d", &n, &U, &M); 
    memset(cnt, 0, sizeof(cnt));
    memset(dp, false, sizeof(dp));
    int total = 0; 
    for (int i = 1; i <= n; i++) {
      scanf("%d", &w[i]);
      total += w[i]; 
      cnt[w[i]]++; 
    }
    vector <pair <int, int> > save;
    for (int value = 1; value <= 100; value++) {
      if (cnt[value] > 0) {
        int sz = 1;
        while (sz <= cnt[value]) {
          save.push_back(make_pair(sz * value, sz));
          cnt[value] -= sz;
          sz *= 2; 
        }
        if (cnt[value] > 0) {
          save.push_back(make_pair(cnt[value] * value, cnt[value])); 
        }
      }
    }
    n = (int) save.size(); 
    dp[0][0] = true; 
    for (int i = 1; i <= n; i++) {
      int cur = i & 1; 
      for (int j = 0; j <= total; j++) {
        dp[cur][j] = 0;
      }
      for (int j = 0; j <= total; j++) {
        dp[cur][j] = dp[!cur][j]; 
        if (j - save[i - 1].first >= 0) {
          dp[cur][j] = max(dp[cur][j], dp[!cur][j - save[i - 1].first]); 
        }
      }
    }
    int ans = 1000000007; 
    for (int j = 0; j <= total; j++) {
      if (dp[n & 1][j] == true) {
        ans = min(ans, max((j + U - 1) / U, (total - j + M - 1) / M));
        ans = min(ans, max((j + M - 1) / M, (total - j + U - 1) / U));   
      }  
    }
    printf("%d\n", ans);
  }
  return 0; 
}