#include <bits/stdc++.h> 

using namespace std;
int n, m; 
vector <pair <pair <int, int>, int> > save;

int main () {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    pair <int, int> seg;
    cin >> seg.first >> seg.second; 
    save.push_back(make_pair(seg, i)); 
  }
  sort(save.begin(), save.end());
  int p = 1;
  int last = 0;
  vector <int> ans; 
  while (p <= m) {
    int maxi = -1;
    int position = -1;  
    while (last < n && save[last].first.first <= p) {
      if (maxi < save[last].first.second) {
        maxi = save[last].first.second;
        position = last;
      }
      last++; 
    }
    if (maxi == -1) {
      cout << "NO";
      return 0; 
    }
    ans.push_back(save[position].second);
    p = maxi + 1;
  }
  cout << "YES" << endl;
  cout << (int) ans.size() << endl;
  sort(ans.begin(), ans.end());
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << ' '; 
  }
  return 0; 
}