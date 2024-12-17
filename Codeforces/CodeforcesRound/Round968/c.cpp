#include <bits/stdc++.h>

using namespace std;
string s; 
int n;
int cnt[26]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    for (int ch = 0; ch < 26; ch++) {
      cnt[ch] = 0; 
    }
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
      cnt[s[i] - 'a']++; 
    }
    for (int i = 1; i <= n; i++) {
      for (int ch = 0; ch < 26; ch++) {
        if (cnt[ch] > 0) {
          cout << (char) (ch + 'a');
          cnt[ch]--; 
        }
      }
    }
    cout << endl;
  }
  return 0; 
}