#include <bits/stdc++.h>

using namespace std;
int numTest; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector <int> cnt(7, 0);
    for (int i = 0; i < n; i++) {
      cnt[s[i] - 'A']++; 
    }   
    int ans = 0;
    for (int i = 0; i < 7; i++) {
      ans += max(0, m - cnt[i]); 
    }
    cout << ans << endl;
  }
  return 0; 
}