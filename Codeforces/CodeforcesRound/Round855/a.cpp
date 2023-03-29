#include <bits/stdc++.h> 
using namespace std; 
int numTest; 
int n; 
string s; 

int main () {
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n; 
    cin >> s; 
    for (int i = 0; i < (int) s.size(); i++) {
      if ('A' <= s[i] && s[i] <= 'Z') {
        s[i] = s[i] - 'A' + 'a'; 
      }
    }
    vector <char> v; 
    v.push_back(s[0]); 
    for (int i = 1; i < (int) s.size(); i++) {
      if (s[i] != s[i - 1]) {
        v.push_back(s[i]); 
      }
    }
    if ((int) v.size() == 4 && v[0] == 'm' && v[1] == 'e' && v[2] == 'o' && v[3] == 'w') {
      cout << "YES" << endl; 
    }
    else {
      cout << "NO" << endl; 
    }
  }
  return 0; 
}