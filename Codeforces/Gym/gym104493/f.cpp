#include <iostream>
#include <vector>
#include <set> 

int main () {
  int n; 
  std::cin >> n; 
  std::vector <std::vector <int> > a; 
  a.resize(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(n, 0);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> a[i][j]; 
    }  
  }
  for (int i = 0; i < n; i++) {
    std::set <int> S; 
    for (int j = 0; j < n; j++) {
      S.insert(a[i][j]); 
    }
    if ((int) S.size() != n) {
      std::cout << "NO";
      return 0; 
    }
  }
  for (int j = 0; j < n; j++) {
    std::set <int> S; 
    for (int i = 0; i < n; i++) {
      S.insert(a[i][j]);   
    }
    if ((int) S.size() != n) {
      std::cout << "NO"; 
      return 0; 
    }
  }
  std::cout << "YES"; 
  return 0; 
}