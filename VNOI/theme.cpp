#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 5005; 
int a[MAX_N];
vector <int> save; 
int f[MAX_N][MAX_N];
int n; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  save.push_back(0);
  for (int i = 1; i < n; i++) {
    save.push_back(a[i + 1] - a[i]);
  }
  n--; 
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (save[i] == save[j]) {
        f[i][j] = f[i - 1][j - 1] + 1;
        if (f[i][j] > j - i - 1) {
          f[i][j] = j - i - 1; 
        }
      }
    }
  }
  int ans = -1; 
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans = max(ans, f[i][j]);
    }
  }
  cout << (ans >= 4 ? ans + 1 : 0);
  return 0; 
}