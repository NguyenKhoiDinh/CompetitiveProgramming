#include <iostream>
#include <string> 
#include <algorithm> 
#include <vector> 
int n; 
std::vector <std::string> a; 

int main () {
  std::cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i]; 
  }
  std::sort(a.begin(), a.end()); 
  return 0;
}