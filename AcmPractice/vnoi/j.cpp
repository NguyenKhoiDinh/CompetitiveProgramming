#include <bits/stdc++.h> 

using namespace std;
set <pair <int, int> > S; 
int n;

int main () {
  cin >> n;
  int ans = 0; 
  int u, v;
  for (int i = 1; i <= n; i++) {
    cin >> u >> v;
    vector <pair <int, int> > save; 
    for (set <pair <int, int> > :: iterator it = S.begin(); it != S.end(); it++) {
      pair <int, int> pr = *it;
      if (pr.first == u || pr.second == u) {
        save.push_back(pr); 
        continue; 
      }  
      if (pr.first == -1) {
        pr.first = u;
        if (pr.first > pr.second) {
          swap(pr.first, pr.second); 
        }
        save.push_back(pr); 
      }
    }
    for (set <pair <int, int> > :: iterator it = S.begin(); it != S.end(); it++) {
      pair <int, int> pr = *it;
      if (pr.first == v || pr.second == v) {
        save.push_back(pr); 
        continue; 
      }  
      if (pr.first == -1) {
        pr.first = v;
        if (pr.first > pr.second) {
          swap(pr.first, pr.second); 
        }
        save.push_back(pr); 
      }
    }
    S.clear(); 
    if (save.empty()) {
      ans++;
      S.insert(make_pair(-1, u));
      S.insert(make_pair(-1, v));  
      continue; 
    }
    for (int j = 0; j < (int) save.size(); j++) {
      S.insert(save[j]); 
    }
  }
  cout << ans; 
  return 0; 
}