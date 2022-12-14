#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 100005; 
string s, t; 
int cnt[MAX_N][26]; 
int cntT[26]; 
bool check[26]; 
stack <int> pos[26]; 
set <char> setChar; 

bool can(int position) {
  for (int c = 0; c < 26; c++) {
    if (cnt[position][c] < cntT[c]) {
      return false;
    }
  }
  return true; 
}

int main () {
  cin >> s >> t; 
  int n = (int) s.size(); 
  for (int i = n - 1; i >= 0; i--) {
    pos[s[i] - 'a'].push(i); 
  }
  int lent = (int) t.size(); 
  for (int i = 0; i < lent; i++) {
    check[t[i] - 'a'] = true;
    cntT[t[i] - 'a']++;
    setChar.insert(t[i]);   
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int c = 0; c < 26; c++) {
      cnt[i][c] = cnt[i + 1][c]; 
    } 
    cnt[i][s[i] - 'a']++; 
  }            
  string ans = ""; 
  int curPos = -1; 
  for (int i = 1; i <= lent; i++) {
    for (int c = 0; c < 26; c++) {
      while (!pos[c].empty() && pos[c].top() <= curPos) {
        pos[c].pop(); 
      }
    }
    char found = '.'; 
    for (set <char> :: iterator it = setChar.begin(); it != setChar.end(); it++) {
      char c = *it;
      if (!pos[c - 'a'].empty()) {
        int p = pos[c - 'a'].top(); 
        if (can(p) == true) {
          found = c;
          curPos = p;
          break; 
        }
      }  
    }  
    if (found == '.') {
      cout << -1;
      return 0; 
    }
    ans += found; 
    cntT[found - 'a']--; 
    if (cntT[found - 'a'] == 0) {
      set <char> :: iterator it = setChar.find(found); 
      setChar.erase(it); 
    }
  }
  cout << ans; 
  return 0; 
}