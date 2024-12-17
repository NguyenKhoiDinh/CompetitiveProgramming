#include <bits/stdc++.h> 

using namespace std;
const long long inf = -1000000000000007LL; 
int n, k;
long long a[1000005]; 

int main () {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
  }
  vector <vector <vector <long long> > > f(n + 2); 
  for (int i = 0; i <= n + 1; i++) {
    f[i].resize(k + 2);
    for (int j = 0; j <= k + 1; j++) {
      f[i][j].resize(2, inf); 
    } 
  }
  f[0][0][0] = 0;  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int state = 0; state <= 1; state++) {
        if (f[i][j][state] == inf) {
          continue; 
        }
        f[i + 1][j][state] = max(f[i + 1][j][state], f[i][j][state] + (state == 1 ? a[i + 1] : 0));
        if (state == 1) {
          f[i + 1][j][0] = max(f[i + 1][j][0], f[i][j][state]); 
        } 
        if (j < k) {
          f[i + 1][j + 1][1] = max(f[i + 1][j + 1][1], f[i][j][state] + a[i + 1]);  
        }
      }
    }
  }
  cout << max(f[n][k][0], f[n][k][1]); 
  return 0; 
}