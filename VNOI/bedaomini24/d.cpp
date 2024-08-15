#include <bits/stdc++.h> 

using namespace std; 
int n, k;
int d; 
pair <int, int> a[100005]; 
int nxt[100005]; 
int f[100005][31]; 
int b[100005]; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> n >> k >> d; 
  for (int i = 1; i <= k; i++) {
    cin >> a[i].first >> a[i].second; 
  }
  for (int i = 1; i <= n; i++) {
    b[i] = i; 
  }
  for (int j = 1; j <= k; j++) {
    reverse(b + a[j].first, b + a[j].second + 1); 
  }
  for (int i = 1; i <= n; i++) {
    f[i][0] = b[i]; 
  }
  for (int j = 1; j <= 30; j++) {
    for (int i = 1; i <= n; i++) {
      f[i][j] = f[f[i][j - 1]][j - 1]; 
    }
  }
  for (int i = 1; i <= n; i++) {
    int p = i; 
    int tmp = d; 
    for (int j = 30; j >= 0; j--) {
      if (tmp >= (1 << j)) {
        tmp -= 1 << j; 
        p = f[p][j]; 
      }
    }
    cout << p << ' '; 
  }
  return 0; 
}