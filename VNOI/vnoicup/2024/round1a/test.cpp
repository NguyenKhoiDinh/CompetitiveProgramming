#include <iostream>
#include <vector> 
#include <algorithm> 
#include <set>
bool check(const std::vector <int> &a) {
  std::set <int> S; 
  for (int l = 0; l < (int) a.size(); l++) {
    int sum = a[l];
    for (int r = l; r < (int) a.size(); r++) {
      sum &= a[r]; 
      if (S.find(sum) != S.end()) {
        return false; 
      }
      S.insert(sum); 
    }
  }
  return true; 
}

int main () {
  freopen("output.txt", "w", stdout); 
  for (int x = 1; x <= 10; x++) {
    for (int mask = 0; mask < (1 << x); mask++) {
    std::vector <int> a; 
    for (int i = 0; i < x; i++) {
      if ((mask & (1 << i)) > 0) {
        a.push_back(i + 1);
      }
    }
    /*for (int i = 0; i < (int) a.size(); i++) {
      std::cout << a[i] << "     "; 

    }
    std::cout << std::endl; 
      */
    do {
      if (check(a) == true) {
        std::cout << x << std::endl; 
        for (int i = 0; i < (int) a.size(); i++) {
          std::cout << a[i] << "    "; 
        }
        std::cout << std::endl;
        break;
      }
    }
    while (std::next_permutation(a.begin(), a.end()));
    } 
  }
  return 0; 
}