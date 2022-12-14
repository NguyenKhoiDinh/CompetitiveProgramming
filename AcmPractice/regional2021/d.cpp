#include <bits/stdc++.h> 

using namespace std;
map <int, int> cnt; 
set <int> S; 
int n; 

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int v;
    cin >> v;
    cnt[v]++; 
    if (cnt[v] == 1) {
      S.insert(v); 
    }
    else {
      set <int> :: iterator it = S.find(v);
      if (it != S.end()) {
        S.erase(it); 
      } 
    }
    set <int> :: iterator it = S.begin(); 
    if (it != S.end()) {
      cout << *it << endl; 
    }
    else {
      cout << -1 << endl;
    }
  }
  return 0; 
}