#include <bits/stdc++.h>

using namespace std;
map <pair <int, int>, int> ways;
pair <int, int> a[33]; 
vector <pair <int, int> > save1, save2; 
int n, U, V;

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second; 
  }
  cin >> U >> V;
  for (int i = 1; i <= n / 2; i++) {
    save1.push_back(a[i]);
  }
  for (int i = n / 2 + 1; i <= n; i++) {
    save2.push_back(a[i]);
  }
  int sz1 = (int) save1.size(); 
  int sz2 = (int) save2.size();
  for (int mask = 0; mask < (1 << sz1); mask++) {
    int u = 0, v = 0;
    for (int i = 0; i < sz1; i++) {
      if ((mask & (1 << i)) > 0) {
        u += save1[i].first; 
        v += save1[i].second; 
      }
    }
    ways[make_pair(u, v)]++;
  }
  int ans = 0; 
  for (int mask = 0; mask < (1 << sz2); mask++) {
    int u = 0, v = 0; 
    for (int i = 0; i < sz2; i++) {
      if ((mask & (1 << i)) > 0) {
        u += save2[i].first; 
        v += save2[i].second; 
      }
    }
    ans += ways[make_pair(U - u, V - v)];
  }
  cout << ans;
  return 0; 
}