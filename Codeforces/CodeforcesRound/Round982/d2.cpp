#include <bits/stdc++.h>

using namespace std;
const long long inf = 1000000000000007LL;
const long long mod = 1000000007LL;  
int a[300005];
int b[300005]; 
int n, m; 
long long sum[300005]; 

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL); 
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
      sum[i] = sum[i - 1] + a[i]; 
    }  
    for (int i = 1; i <= m; i++) {
      cin >> b[i]; 
    }
    vector <long long> f(n + 1, inf); 
    vector <long long> ways(n + 1, 0LL); 
    f[0] = 0; 
    ways[0] = 1LL; 
    for (int k = 1; k <= m; k++) {
      long long sumWays = 0LL;
      int l = 0;
      int j = 0;
      for (int i = 1; i <= n; i++) {
        while (sum[i] - sum[j] > b[k]) {
          sumWays -= ways[j];
          (sumWays += mod) %= mod; 
          j++; 
        }
        if (l < j) {
          sumWays = 0LL; 
          l = j; 
        }
        while (l < i && f[l] == f[j]) {
          (sumWays += ways[l]) %= mod; 
          l++; 
        }
        if (j < i) {
          long long value = f[j] + m - k; 
          if (f[i] > value) {
            f[i] = value; 
            ways[i] = sumWays; 
          }
          else if (f[i] == value) {
            (ways[i] += sumWays) %= mod; 
          }
        }
      }  
    }
    if (f[n] == inf) {
      cout << -1 << endl;
      continue;   
    }
    cout << f[n] << ' ' << ways[n] << endl; 
  }
  return 0; 
}         