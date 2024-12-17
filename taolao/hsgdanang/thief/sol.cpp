#include <bits/stdc++.h> 
using namespace std;
const int inf = 1000000007; 
int n, W, H; 
int w[105], c[105];
int f[105][100005][2];  
void updateMin(int &a, int b) {
  a = min(a, b);
}

int main () {
  cin >> n >> W >> H; 
  int sumMoney = 0; 
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> c[i];
    sumMoney += c[i];  
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= sumMoney; j++) {
      for (int useHand = 0; useHand <= 1; useHand++) {
        f[i][j][useHand] = inf; 
      }
    }
  }
  f[0][0][0] = 0; 
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= sumMoney; j++) {
      for (int useHand = 0; useHand <= 1; useHand++) {
        if (f[i][j][useHand] == inf) {
          continue; 
        }             
        updateMin(f[i + 1][j][useHand], f[i][j][useHand]);
        if (f[i][j][useHand] + w[i + 1] <= W) {
          updateMin(f[i + 1][j + c[i + 1]][useHand], f[i][j][useHand] + w[i + 1]);     
        }
        if (useHand == 0 && w[i + 1] <= H) {
          updateMin(f[i + 1][j + c[i + 1]][1], f[i][j][useHand]);  
        }
      }
    }
  }
  int ans = -1; 
  for (int j = 0; j <= sumMoney; j++) {
    if (f[n][j][0] != inf || f[n][j][1] != inf) {
      ans = j;     
    }      
  }
  cout << ans; 
  return 0; 
}