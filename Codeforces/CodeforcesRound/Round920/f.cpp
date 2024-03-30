#include <iostream>  
#include <vector>
#include <algorithm>
#include <math.h>
int numTest; 
int n, numQueries;
int a[100005]; 
std::vector <long long> value[450][450], sum[450][450]; 

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> numQueries;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i]; 
    }
    int block = (int) std::sqrt(n);
    for (int r = 0; r < block; r++) {
      for (int start = 0; start < block; start++) {
        value[r][start].clear();
        value[r][start].push_back(0LL);
        sum[r][start].clear();   
        sum[r][start].push_back(0LL);
      }
    }
    for (int r = 0; r < block; r++) {
      for (int i = 0; i < n; i++) {
        int start = i % (r + 1);        
        int sz = (int) value[r][start].size();          
        value[r][start].push_back(value[r][start].back() + (long long) sz * a[i]); 
        sum[r][start].push_back(sum[r][start].back() + a[i]); 
      }
    }                                
    for (int query = 1; query <= numQueries; query++) {
      int start, d, k;                        
      std::cin >> start >> d >> k;  
      start--;                
      if (d > block) {
        long long ans = 0LL; 
        for (int i = 0; i < k; i++) {
          ans += (long long) (i + 1) * a[start + i * d];   
        }                             
        std::cout << ans << ' '; 
      }
      else {
        long long ans = value[d - 1][start % d][start / d + k] - value[d - 1][start % d][start / d]; 
        ans -= (long long) (start / d) * (sum[d - 1][start % d][start / d + k] - sum[d - 1][start % d][start / d]); 
        std::cout << ans << ' ';
      }
    }
    std::cout << std::endl;
  }
  return 0; 
}