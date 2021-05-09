#include <bits/stdc++.h>

using namespace std;
map <int, int> M; 
int cnt[12]; 

bool check() {
  for (map <int, int> :: iterator it = M.begin(); it != M.end(); it++) {
    if (it->second % 4 != 0) {
      return false; 
    }
  }
  return true; 
}

int main () {
  while (true) {
    M.clear();
    for (int i = 0; i < 12; i++) {
      cin >> cnt[i];
      M[cnt[i]]++; 
    }
    if (cnt[0] == 0) {
      break; 
    }
    cout << (check() == true ? "yes" : "no") << endl; 
  }
  return 0; 
}