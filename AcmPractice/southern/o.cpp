#include <bits/stdc++.h> 

using namespace std;
int x[200005], y[200005];
int n;  
map <pair <int, int>, int> cntxy; 
map <int, int> cntx, cnty;

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i]; 
  }
  long long ans = 0LL;
  for (int i = 1; i <= n; i++) {
    ans += cntx[x[i]] + cnty[y[i]] - cntxy[make_pair(x[i], y[i])];
    cntx[x[i]]++;
    cnty[y[i]]++;
    cntxy[make_pair(x[i], y[i])]++;   
  }
  cout << ans;
  return 0; 
}