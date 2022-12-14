#include <bits/stdc++.h>

using namespace std;
map <string, int> M; 
int n; 

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    M[s]++;
  }
  for (map <string, int> :: iterator it = M.begin(); it != M.end(); it++) {
    if (it->second % 2 == 1) {
      cout << it->first; 
      return 0; 
    }
  }
  cout << -1;
  return 0; 
}