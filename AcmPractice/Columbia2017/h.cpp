#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 205; 
char a[MAX_N][MAX_N]; 
int n; 

int main () {
  //freopen("input.txt", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 2 * n + 1; j++) {
      a[i][j] = ' ';
    }
  } 
  a[1][1] = '*';
  a[1][n] = '*'; 
  for (int i = n + 2; i <= 2 * n + 1; i++) {
    a[1][i] = '*'; 
  }
  for (int i = 2; i <= n - 1; i++) {
    a[i][1] = '*';
    a[i][n] = '*';
    a[i][n + 2] = '*'; 
    a[i][2 * n + 1] = '*'; 
  }
  for (int i = 1; i <= n; i++) {
    a[n][i] = '*'; 
  }
  a[n][n + 2] = '*';
  a[n][2 * n + 1] = '*';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 2 * n + 1; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0; 
}