#include <bits/stdc++.h> 

using namespace std; 
int n, m;
int x, y; 
const int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1}; 
const int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1}; 

int main () {
  cin >> n >> m;
  cin >> x >> y;
  int ans = 0;  
  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
      ans++; 
    }
  }
  cout << ans;
  return 0; 
}