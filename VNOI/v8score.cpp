#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 22; 

int score[MAX_N][MAX_N];
int S, n, m; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> S >> m >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> score[i][j];
    }
  }
  for (int mask = 0; mask < (1 << m); mask++) {
    
  }
  return 0; 
}