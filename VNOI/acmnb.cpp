#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 800005; 
int n; 
int a[MAX_N], b[MAX_N];
int c[MAX_N];

int main () {
  cin >> n;
  int res = 0; 
  for (int i = 1; i <= 2 * n; i++) {
    cin >> a[i] >> b[i]; 
    c[i] = b[i] - a[i];
    res += a[i];
  }
  sort(c + 1, c + 2 * n + 1);
  for (int i = 1; i <= n; i++) {
    res += c[i]; 
  }
  cout << res;
  return 0; 
}