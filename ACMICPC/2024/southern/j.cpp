#include <bits/stdc++.h> 
using namespace std;
const long long mod = 1000000007LL;  
string s; 
int cnt[256][100005]; 
vector <int> save;
map <vector <int>, int> f;  
int n;
 
int main () {
  cin >> n; 
  assert(2 <= n <= 100000); 
  cin >> s;
  assert(n == (int) s.size()); 
  for (int i = 1; i <= n; i++) {
    for (int c = 0; c < 256; c++) {
      cnt[c][i] = cnt[c][i - 1];   
    }
    cnt[s[i - 1]][i]++; 
  } 
  for (int c = 0; c < 256; c++) {
    if (cnt[c][n] != 0) {
      save.push_back(c); 
    }
  }
  if ((int) save.size() == 1) {
    cout << 1LL * n * (n + 1) / 2 % mod; 
    return 0; 
  }
  long long ans = 0LL;
  for (int i = 0; i <= n; i++) {
    vector <int> d; 
    for (int j = 0; j < (int) save.size() - 1; j++) {
      d.push_back(cnt[save[j]][i] - cnt[save[j + 1]][i]);
    }
    ans += f[d];
    f[d]++; 
  }
  cout << ans % mod;
  return 0;  
}