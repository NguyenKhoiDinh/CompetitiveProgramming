#include <bits/stdc++.h> 

using namespace std;
int numTest;
int F[26][26];  

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    string s;
    cin >> s;
    int m;
    cin >> m;
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        F[i][j] = 1000005; 
      }
    }
    for (int i = 1; i <= m; i++) {
      string st;
      cin >> st;
      F[st[0] - 'A'][st[1] - 'A'] = 1; 
    }
    for (int i = 0; i < 26; i++) {
      F[i][i] = 0;
    }
    for (int k = 0; k < 26; k++) {
      for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
          F[i][j] = min(F[i][j], F[i][k] + F[k][j]);
        }
      }
    }
    int ans = 1000005;
    for (char c = 'A'; c <= 'Z'; c++) {
      int sum = 0;
      for (int i = 0; i < (int) s.size(); i++) {
        sum += F[s[i] - 'A'][c - 'A'];  
      }
      ans = min(ans, sum); 
    }
    cout << (ans == 1000005 ? -1 : ans) << endl; 
  }
  return 0; 
}