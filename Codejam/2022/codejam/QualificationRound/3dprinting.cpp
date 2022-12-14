#include <iostream> 
#include <fstream>
#include <math.h>  
int numTest; 
int a[3][4]; 
int cost[4]; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": ";
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 4; j++) {
        std::cin >> a[i][j]; 
      }
    } 
    for (int j = 0; j < 4; j++) {
      cost[j] = a[0][j]; 
    }
    for (int i = 1; i < 3; i++) {
      for (int j = 0; j < 4; j++) {
        cost[j] = std::min(cost[j], a[i][j]); 
      }
    }
    int total = 0; 
    for (int j = 0; j < 4; j++) {
      total += cost[j]; 
    }
    if (total < 1000000) {
      std::cout << "IMPOSSIBLE"; 
    }
    else {
      int lim = 1000000; 
      for (int j = 0; j < 4; j++) {
        int value = std::min(lim, cost[j]); 
        std::cout << value << ' ';  
        lim -= value; 
      }
    }
    std::cout << std::endl; 
  }
  return 0; 
}