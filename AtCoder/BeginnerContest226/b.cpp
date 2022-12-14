#include <bits/stdc++.h> 

using namespace std;

map <vector <int>, int> cnt; 
int n; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    vector <int> a;
    int sz;
    cin >> sz;
    a.resize(sz); 
    for (int i = 0; i < sz; i++) {
      cin >> a[i];
    }
    cnt[a]++; 
  }
  cout << (int) cnt.size(); 
  return 0; 
}