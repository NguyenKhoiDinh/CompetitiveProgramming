#include <iostream>
#include <math.h> 
const int cost[4] = {1, 2, 3, 5}; 
int f_min[5][10], f_ways[5][10];
unsigned long long w;
int c;  
int numTest;
void init() {
  for (int i = 0; i <= 4; i++) {
    for (int j = 0; j <= 9; j++) {
      f_min[i][j] = 15;
      f_ways[i][j] = 0; 
    }
  }
  f_min[0][0] = 0;
  f_ways[0][0] = 1LL;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j <= 9; j++) {
      if (f_min[i][j] == 15) {
        continue; 
      }
      if (f_min[i + 1][j] > f_min[i][j]) {
        f_min[i + 1][j] = f_min[i][j];
        f_ways[i + 1][j] = f_ways[i][j]; 
      }
      else if (f_min[i + 1][j] == f_min[i][j]) {
        f_ways[i + 1][j] += f_ways[i][j]; 
      }
      if (j + cost[i] <= 9) {
        if (f_min[i][j + cost[i]] > f_min[i][j] + 1) {
          f_min[i][j + cost[i]] = f_min[i][j] + 1;
          f_ways[i][j + cost[i]] = f_ways[i][j];   
        }
        else if (f_min[i][j + cost[i]] == f_min[i][j] + 1) {
          f_ways[i][j + cost[i]] += f_ways[i][j]; 
        }
      }
    }
  } 
} 

int main () {
  init(); 
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> w >> c;
    c++;  
    if (w % 1000 != 0) {
      std::cout << 0 << std::endl;
      continue; 
    }
    w /= 1000; 
    long long ansMin = 0LL; 
    unsigned long long ansWays = 1LL; 
    while (w > 0 && c > 0) {
      int r = w % 10; 
      w /= 10; 
      ansMin += f_min[4][r];
      ansWays *= (unsigned long long) f_ways[4][r];
      c--;   
    }
    if (w > 0) {
      ansMin += w * 2LL;
    }
    std::cout << ansMin << ' ' << ansWays << std::endl;
  }
  return 0; 
}