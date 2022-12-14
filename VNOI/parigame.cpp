#include <iostream> 

using namespace std; 
const int MAX_N = 505; 
int a[MAX_N][MAX_N]; 
long long row[MAX_N][MAX_N], col[MAX_N][MAX_N]; 
int f[MAX_N][MAX_N];
int n, test; 

int main () {
  //freopen("PARIGAME.INP", "r", stdin);
  //freopen("PARIGAME.OUT", "w", stdout);
  scanf("%d", &test); 
  for (int tt = 1; tt <= test; tt++) {
    cin >> n; 
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%d", &a[i][j]); 
        f[i][j] = 0;
        row[i][j] = 0;
        col[i][j] = 0; 
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        row[i][j] = row[i - 1][j] + a[i][j]; 
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        col[i][j] = col[i][j - 1] + a[i][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (row[i][j] % 2 == 0) {
          if (f[i][j - 1] == 0) {
            f[i][j] = 1; 
          }
        }
        if (col[i][j] % 2 == 0) {
          if (f[i - 1][j] == 0) {
            f[i][j] = 1; 
          }
        }
      }
    }
    if (f[n][n] == 1) {
      printf("YES\n");
    }
    else {
      printf("NO\n");
    }
  }
  return 0;
}