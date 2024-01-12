#include <iostream>
#include <random>
#include <time.h>
int n; 

int main () {
  std::srand(time(NULL)); 
  std::cin >> n; 
  int r = 1; 
  while (true) {
    bool found = false;
    for (int step = 1; step <= 15; step++) {
      int v;
      while (true) {
        v = std::rand() % n + 1;
        if (v != r) {
          break;
        }
      }
      std::cout << "adj " << v << std::endl; 
      fflush(stdout);
      int adj;
      std::cin >> adj; 
      std::cout << "subtree " << adj << std::endl;
      fflush(stdout); 
      int sz;
      std::cin >> sz; 
      if (2 * sz > n) {
        std::cout << "move " << adj << std::endl;
        fflush(stdout);
        int valid;
        std::cin >> valid;
        if (valid == -1) {
          return 0; 
        } 
        r = adj; 
        found = true;
        break;
      }                 
      else if (2 * sz == n) {
        std::cout << "move " << adj << std::endl;
        fflush(stdout);
        int valid;
        std::cin >> valid; 
        if (valid == -1) {
          return 0; 
        }
        break;
      }
    } 
    if (found == false) {
      std::cout << "found" << std::endl;
      fflush(stdout);
      return 0;       
    }
  }
  return 0; 
}