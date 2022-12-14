#include <bits/stdc++.h> 

using namespace std;
const int inf = 1000000007; 
string s; 
int dp[1000005]; 
int numTest; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> s;
    int n = (int) s.size(); 
    for (int i = 0; i <= n; i++) {
      dp[i] = inf;   
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      if (dp[i] != inf) {
        if (s[i] == '1') {
          dp[i + 1] = min(dp[i + 1], dp[i] + 1); 
          if (i + 2 <= n && s[i + 1] == '0') {
            dp[i + 2] = min(dp[i + 2], dp[i]); 
          }
        }
        else {
          dp[i + 1] = min(dp[i + 1], dp[i]); 
          if (i + 2 <= n && s[i + 1] == '1') {
            dp[i + 2] = min(dp[i + 2], dp[i]); 
          }
        }
      }
    }
    cout << dp[n] << endl; 
  }  
  return 0;
}