#include <bits/stdc++.h>

using namespace std;
int numTest;

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    string s; 
    cin >> s; 
    int n = (int) s.size();
    int cntKick = 0;
    long long ans = 0LL; 
    for (int i = 0; i < n - 4; i++) {
      if (s[i] == 'K') {
        if (s[i + 1] == 'I' && s[i + 2] == 'C' && s[i + 3] == 'K') {
          cntKick++;
        }
      }
      else if (s[i] == 'S') {
        if (s[i + 1] == 'T' && s[i + 2] == 'A' && s[i + 3] == 'R' && s[i + 4] == 'T') {
          ans += cntKick; 
        }
      }
    }
    cout << ans << endl; 
  }
  return 0;
}