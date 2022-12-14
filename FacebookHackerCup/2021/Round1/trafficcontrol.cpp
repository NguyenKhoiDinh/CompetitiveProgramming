#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 55;
int numTest;
int n, m, A, B; 
int a[MAX_N][MAX_N]; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    cin >> n >> m >> A >> B;
    if (n + m - 1 > min(A, B)) {
      cout << "Impossible" << endl;
      continue; 
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        a[i][j] = 1000;
        if (i == 1 || j == 1 || i == n || j == m) {
          a[i][j] = 1; 
        }
      }
    }
    a[n][m] = A + 2 - n - m;
    a[n][1] = B + 2 - n - m;
    cout << "Possible" << endl; 
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << a[i][j] << ' ';
      }
      cout << endl; 
    } 
  }
  return 0; 
}