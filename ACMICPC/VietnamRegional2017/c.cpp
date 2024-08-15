#include <iostream>
#include <stack> 
int n;
int deg[1005]; 
std::stack <int> store;

int main () {
  int degree = 0;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> deg[i]; 
    degree += deg[i]; 
  } 
  if (degree != 2 * (n - 1)) {
    std::cout << "NO";
    return 0; 
  }
  for (int i = n; i >= 2; i--) {
    if ((int) store.size() < deg[i] - 1) {
      std::cout << "NO";
      return 0;   
    }  
    for (int j = 1; j <= deg[i] - 1; j++) {
      store.pop(); 
    }
    store.push(i); 
  }
  std::cout << ((int) store.size() == deg[1] ? "YES" : "NO");
  return 0; 
}