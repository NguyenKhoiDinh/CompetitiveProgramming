#include <bits/stdc++.h> 

using namespace std;
int n; 
int t[100005]; 

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i]; 
  }
  sort(t + 1, t + n + 1);
  vector <int> ans; 
  int l = 1; 
  int r = n; 
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 1) {
      ans.push_back(t[r]);
      r--;
    }
    else {
      ans.push_back(t[l]);
      l++; 
    }
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' '; 
  }
  return 0;
}