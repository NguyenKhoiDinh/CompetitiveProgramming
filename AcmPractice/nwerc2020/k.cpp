#include <bits/stdc++.h> 

using namespace std;
string s, t;
set <char> sticky; 

int main () {
  getline(cin, s);
  getline(cin, t);
  for (int i = 0; i < (int) s.size(); i++) {
    sticky.insert(s[i]); 
  }
  int p = 0; 
  int q = 0; 
  while (p < (int) s.size()) {
    char c = s[p]; 
    int numbs = 0;
    int numbt = 0; 
    while (p < (int) s.size() && s[p] == c) {
      numbs++;
      p++;   
    }
    while (q < (int) t.size() && t[q] == c) {
      numbt++;
      q++; 
    }
    if (numbs == numbt) {
      set <char> :: iterator it = sticky.find(c); 
      if (it != sticky.end()) {
        sticky.erase(it);
      } 
    }
  }
  for (set <char> :: iterator it = sticky.begin(); it != sticky.end(); it++) {
    cout << *it; 
  }
  return 0;
}