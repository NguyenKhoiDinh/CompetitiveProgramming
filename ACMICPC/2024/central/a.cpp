#include <bits/stdc++.h> 

using namespace std;
const long long inf = 100000000000007LL;
int n, W, H; 
struct item {
  int w, v; 
};
item a[105]; 
long long f[105][100005][2]; 

int main () {
  cin >> n >> W >> H;
  int sumCost = 0; 
  for (int i = 1; i <= n; i++) {
    cin >> a[i].w >> a[i].v;
    sumCost += a[i].v; 
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= sumCost; j++) {
      for (int take = 0; take <= 1; take++) {
        f[i][j][take] = inf; 
      } 
    }
  }
  f[0][0][0] = 0LL;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= sumCost; j++) {
      for (int take = 0; take <= 1; take++) {
        if (f[i][j][take] == inf) {
          continue; 
        }
        f[i + 1][j][take] = min(f[i + 1][j][take], f[i][j][take]);
        if (take == 0 && a[i + 1].w <= H) {
          f[i + 1][j + a[i + 1].v][1] = min(f[i + 1][j + a[i + 1].v][1], f[i][j][take]); 
        } 
        if (f[i][j][take] + a[i + 1].w <= W) {
          f[i + 1][j + a[i + 1].v][take] = min(f[i + 1][j + a[i + 1].v][take], f[i][j][take] + a[i + 1].w); 
        }
      }
    }
  } 
  int ans = -1; 
  for (int j = 0; j <= sumCost; j++) {
    if (f[n][j][0] <= W || f[n][j][1] <= W) {
      ans = j; 
    }
  }
  cout << ans;
  return 0; 
}