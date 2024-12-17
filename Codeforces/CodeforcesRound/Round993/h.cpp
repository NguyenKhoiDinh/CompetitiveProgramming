#include <iostream> 
int numTest; 
long long sum[2005][2005], sumx[2005][2005], sumy[2005][2005];
int a[2005][2005];
int n, numQueries;  

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> numQueries;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        std::cin >> a[i][j]; 
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + a[i][j] - sum[i - 1][j - 1]; 
        sumx[i][j] = sumx[i - 1][j] + sumx[i][j - 1] + a[i][j] * i - sumx[i - 1][j - 1]; 
        sumy[i][j] = sumy[i - 1][j] + sumy[i][j - 1] + a[i][j] * j - sumy[i - 1][j - 1];  
      }
    }
    for (int query = 1; query <= numQueries; query++) {
      int x1, y1, x2, y2; 
      std::cin >> x1 >> y1 >> x2 >> y2;
      long long ans = 0LL;
      long long valuex = sumx[x2][y2] - sumx[x1 - 1][y2] - sumx[x2][y1 - 1] + sumx[x1 - 1][y1 - 1];
      valuex *= y2 - y1 + 1;
      ans += valuex;
      long long valuey = sumy[x2][y2] - sumy[x1 - 1][y2] - sumy[x2][y1 - 1] + sumy[x1 - 1][y1 - 1];
      ans += valuey; 
      long long value = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
      value *= (-x1 * y2 + x1 * y1 - x1 - y1 + 1);    
      ans += value;
      std::cout << ans << ' ';
    }
    std::cout << std::endl;
  }
  return 0; 
}