#include <bits/stdc++.h>

using namespace std;
int d[25005]; 
long long f[25005];
int n; 

int main () {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> d[i];
  }
  f[1] = 0; 
  f[2] = d[1]; 
  for (int i = 3; i <= n; i++) {
    f[i] = f[i - 1] + d[i - 1];
    if (i > 3) {
      f[i] = min(f[i], f[i - 2] + d[i - 1]);
    }
  }
  cout << f[n];
  return 0; 
}