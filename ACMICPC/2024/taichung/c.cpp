#include <iostream> 
#include <math.h>
#include <vector>
const long long inf = 10000000000007LL; 
int n;
int value[12][12][12];
long long f[2][(1 << 12) + 3][(1 << 12) + 3];      
std::vector <int> listMask[13]; 
std::vector <int> listBit[(1 << 12) + 3]; 

int main () {
  std::cin >> n;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      for (int z = 0; z < n; z++) {
        std::cin >> value[x][y][z]; 
      }
    }
  }
  for (int mask = 0; mask < (1 << n); mask++) {
    int cnt = (int) __builtin_popcount(mask); 
    listMask[cnt].push_back(mask); 
    for (int i = 0; i < n; i++) {
      if ((mask & (1 << i)) == 0) {
        listBit[mask].push_back(i); 
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int now = i % 2;
    int nxt = 1 - now; 
    for (int y = 0; y < (int) listMask[i + 1].size(); y++) {
      for (int z = 0; z < (int) listMask[i + 1].size(); z++) {
        int masky = listMask[i + 1][y];
        int maskz = listMask[i + 1][z];
        f[nxt][masky][maskz] = inf;  
      }
    }                           
    for (int y = 0; y < (int) listMask[i].size(); y++) {
      for (int z = 0; z < (int) listMask[i].size(); z++) {
        int masky = listMask[i][y];
        int maskz = listMask[i][z];                                         
        for (int py = 0; py < (int) listBit[masky].size(); py++) {
          for (int pz = 0; pz < (int) listBit[maskz].size(); pz++) {
            int by = listBit[masky][py];
            int bz = listBit[maskz][pz];                                                              
            f[nxt][masky | (1 << by)][maskz | (1 << bz)] = std::min(f[nxt][masky | (1 << by)][maskz | (1 << bz)], f[now][masky][maskz] + value[i][by][bz]); 
          }
        } 
      }
    }
  }
  std::cout << f[n % 2][(1 << n) - 1][(1 << n) - 1]; 
  return 0; 
}