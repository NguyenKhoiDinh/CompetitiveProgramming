#include <bits/stdc++.h> 

using namespace std;
string pattern[7] = {"AA", "BB", "CC", "DDDD", "BABA", "ACAC", "DABCACB"}; 
set <string> S; 
void backTrack(string s, int steps) {
  if (steps == 4) {
    if (S.find(s) == S.end()) {
      cout << s << endl; 
      S.insert(s);
    } 
    return; 
  }  
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j <= (int) s.size(); j++) {
      string new_s = "";
      for (int k = 0; k < j; k++) {
        new_s += s[k]; 
      }
      new_s += pattern[i];
      for (int k = j; k < (int) s.size(); k++) {
        new_s += s[k]; 
      }
      backTrack(new_s, steps + 1);    
    }
  }
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < (int) s.size(); j++) {
      int p = 0; 
      int pj = j; 
      while (p < (int) pattern[i].size() && pj < (int) s.size() && pattern[i][p] == s[pj]) {
        p++;
        pj++; 
      }
      if (p == (int) pattern[i].size()) {
        string new_s = "";
        for (int k = 0; k < j; k++) {
          new_s += s[k]; 
        } 
        for (int k = pj; k < (int) s.size(); k++) {
          new_s += s[k]; 
        }
        backTrack(new_s, steps + 1); 
      }
    }
  }
}
          
int main () {
  freopen("output.txt", "w", stdout);     
  backTrack("", 0); 
  return 0; 
}