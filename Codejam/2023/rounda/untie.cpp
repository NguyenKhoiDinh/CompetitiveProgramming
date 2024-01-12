#include <bits/stdc++.h>
int numTest;      
string s;
int dp[1005][3]; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> s;
    int n = (int) s.size(); 
    s += s;
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] == 'R') {
        s[i] = '0'; 
      }
      else if (s[i] == 'S') {
        s[i] = '1'; 
      }
      else {
        s[i] = '2'; 
      }
    }
    int ans = n + 10; 
    for (int l = 0; l < n; l++) {
      int r = l + n - 1; 
      std::vector <char> v; 
      v.push_back('!'); 
      for (int i = l + 1; i <= r; i++) {
        v.push_back(s[i]); 
      }
      for (int i = 0; i <= n; i++) {
        for (int choice = 0; choice <= 2; choice++) {
          dp[i][choice] = n + 10; 
        } 
      }
      int firstChoice = s[l] - '0'; 
      for (int choice = 0; choice <= 2; choice++) {
        if (choice != firstChoice) {
          dp[1][choice] = ((v[1] - '0') != choice);
        }  
      }
      for (int i = 1; i < n - 1; i++) {
        for (int choice = 0; choice <= 2; choice++) {
          if (dp[i][choice] == n + 10) {
            continue; 
          }
          for (int nextChoice = 0; nextChoice <= 2; nextChoice++) {
            if (nextChoice != choice) {
              dp[i + 1][nextChoice] = std::min(dp[i + 1][nextChoice], dp[i][choice] + (nextChoice != (v[i + 1] - '0'))); 
            }
          }
        }
      }
      for (int choice = 0; choice <= 2; choice++) {
        if (choice != firstChoice) {
          ans = min(ans, dp[n - 1][choice]); 
        }  
      }
    }
    cout << ans << endl;  
  }
  return 0; 
}