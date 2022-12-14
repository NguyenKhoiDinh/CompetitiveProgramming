#include <bits/stdc++.h> 

using namespace std;
const int MAX_DIMENSION = 103; 
int dp[12][MAX_DIMENSION][MAX_DIMENSION][MAX_DIMENSION];
int numTest; 

void dynamicProgramming() {
  for (int u = 1; u <= 10; u++) {
    for (int x = 1; x <= 100; x++) {
      for (int y = 1; y <= 100; y++) {
        for (int z = 1; z <= 100; z++) {
          int value = 0; 
          if (y >= x && z >= x && x >= u) {
            value = max(value, y * z); 
          }
          if (x >= y && z >= y && y >= u) {
            value = max(value, x * z); 
          }
          if (x >= z && y >= z && z >= u) {
            value = max(value, x * y); 
          }
          if (x > u) {
            value = max(value, dp[u][u][y][z] + dp[u][x - u][y][z]);
          }
          if (y > u) {
            value = max(value, dp[u][x][u][z] + dp[u][x][y - u][z]); 
          }
          if (z > u) {
            value = max(value, dp[u][x][y][u] + dp[u][x][y][z - u]); 
          }
          dp[u][x][y][z] = value; 
        }
      }
    }
  }
}   

int main () {
  dynamicProgramming();
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int x, y, z, u; 
    cin >> x >> y >> z >> u; 
    cout << dp[u][x][y][z] << endl; 
  }
  return 0; 
}