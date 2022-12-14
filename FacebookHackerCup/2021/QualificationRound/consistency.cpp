#include <bits/stdc++.h> 

using namespace std;
int numTest; 

bool isVowel(char c) {
  if (c == 'A' || c == 'E' || c == 'I' || c == 'U' || c == 'O') {
    return true;
  }
  return false;
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    string s;
    cin >> s;
    int ans = 1000000005;
    for (char c = 'A'; c <= 'Z'; c++) {
      bool vowel = isVowel(c);
      int cost = 0;
      for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] != c) {
          cost += (isVowel(s[i]) == vowel ? 2 : 1);  
        }  
      }  
      ans = min(ans, cost);
    }
    cout << ans << endl;
  }
  return 0; 
}