#include <bits/stdc++.h>
int numTest; 
int value[26]; 
int numStrings; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    for (int i = 0; i < 26; i++) {
      cin >> value[i]; 
    }
    cin >> numStrings; 
    set <std::string> S; 
    for (int i = 1; i <= numStrings; i++) {
      string s; 
      cin >> s; 
      string st = ""; 
      for (int j = 0; j < (int) s.size(); j++) {
        st += (char) (value[s[j] - 'A'] + '0'); 
      }
      S.insert(st); 
    }
    if ((int) S.size() == numStrings) {
      cout << "NO";
    }
    else {
      cout << "YES"; 
    }
    cout << endl;
  }
  return 0; 
}