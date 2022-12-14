#include <iostream>
#include <cstring> 
int numTest; 
long long sum[1005][1005]; 
int n, numQuery; 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> numQuery;
    std::memset(sum, 0, sizeof(sum)); 
    for (int i = 1; i <= n; i++) {
      int h, w; 
      std::cin >> h >> w;
      sum[h][w] += 1LL * h * w;  
    }
    for (int i = 1; i <= 1000; i++) {
      for (int j = 1; j <= 1000; j++) {
        sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]; 
      }
    }  
    for (int query = 1; query <= numQuery; query++) {
      int hs, ws, hb, wb;
      std::cin >> hs >> ws >> hb >> wb; 
      std::cout << sum[hb - 1][wb - 1] - sum[hb - 1][ws] - sum[hs][wb - 1] + sum[hs][ws] << std::endl; 
    }
  }
  return 0; 
}