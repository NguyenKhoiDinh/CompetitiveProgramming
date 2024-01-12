#include <iostream>
#include <vector>
std::vector <int> v1, v2; 

int main () {
  freopen("copyarray.out", "r", stdin);
  int x;
  while (std::cin >> x) {
    v1.push_back(x); 
  }
  for (int i = 0; i < (int) v1.size(); i++) {
    std::cout << v1[i] << ' ';
  }
  std::cout << std::endl;
  freopen("copyarray2.out", "r", stdin);
  while (std::cin >> x) {
    v2.push_back(x); 
  }

  for (int i = 0; i < (int) v2.size(); i++) {
    std::cout << v2[i] << ' ';
  }
  std::cout << std::endl;
  std::cout << (v1 == v2 ? "CORRECT" : "WRONG");
  return 0; 
}